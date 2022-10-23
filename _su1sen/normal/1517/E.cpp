#include <bits/stdc++.h>
#include <cassert>
#include <type_traits>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) (iterable).begin(), (iterable).end()

constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template <typename T>
void print_vector(const vector<T>& vec, const string sep = " ", const string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}

template <typename T>
void read_vector(vector<T>& a, int begin_index, int length) {
    if (a.size() < begin_index + length) a.resize(begin_index + length);
    while (length --> 0) cin >> a[begin_index++];
}
template <typename T>
void read_vector(vector<T>& a) { read_vector(a, 0, a.size()); }


template <int mod> class modint {
    public:
        modint(): _v(0) {}
        template <typename T> modint(T x) {
            T v = x % mod;
            if (v < 0) v += mod;
            _v = v;
        }

        unsigned int val() const { return _v; }

        modint& operator+=(const modint& x) { _v = add(_v, x._v); return *this; }
        modint& operator-=(const modint& x) { _v = sub(_v, x._v); return *this; }
        modint& operator*=(const modint& x) { _v = mul(_v, x._v); return *this; }
        modint& operator/=(const modint& x) { _v = mul(_v, inv(x._v)); return *this; }

        friend modint operator+(const modint& x, const modint& y) { return modint(x) += y; }
        friend modint operator-(const modint& x, const modint& y) { return modint(x) -= y; }
        friend modint operator*(const modint& x, const modint& y) { return modint(x) *= y; }
        friend modint operator/(const modint& x, const modint& y) { return modint(x) /= y; }

        modint& operator++() {
            ++_v;
            if (_v == mod) _v = 0;
            return *this;
        }
        modint& operator--() {
            if (_v == 0) _v = mod;
            --_v;
            return *this;
        }
        modint operator++(int) {
            modint res = modint(_v);
            ++*this;
            return res;
        }
        modint operator--(int) {
            modint res = modint(_v);
            --*this;
            return res;
        }
        modint operator+() const { return modint(_v); }
        modint operator-() const { return modint(mod - _v); }

        bool operator==(const modint& x) const { return _v == x._v; }
        bool operator!=(const modint& x) const { return _v != x._v; }
        bool operator!() const noexcept { return _v > 0; }

        modint inv() const { return inv(_v); }

        modint pow(long long x, bool accept_negative_power = false) const {
            bool negative_power = false;
            if (accept_negative_power) {
                if (x < 0) {
                    negative_power = true;
                    x = -x;
                }
            } else {
                assert(x >= 0);
            }
            modint res = 1, pw2 = _v;
            for (; x > 0; x >>= 1) {
                if (x & 1) res *= pw2;
                pw2 *= pw2;
            }
            return negative_power ? 1 / res : res;
        }

        static constexpr unsigned int safe_mod(const long long v) {
            long long z = v % (long long) mod;
            if (z < 0) z += mod;
            return (unsigned int) z;
        }
    private:
        unsigned int _v;
        static constexpr unsigned int add(const unsigned int x, const unsigned int y) {
            unsigned int z = x + y;
            if (z >= mod) z -= mod;
            return z;
        }
        static constexpr unsigned int sub(const unsigned int x, const unsigned int y) {
            return x < y ? x + mod - y : x - y;
        }
        static constexpr unsigned int mul(const unsigned int x, const unsigned int y) {
            return (unsigned int) ((unsigned long long) x * y % mod);
        }
        static constexpr unsigned int inv(const unsigned int x) {
            long long a = x, b = mod, u = 1, v = 0;
            long long tmp;
            while (b) {
                long long t = a / b;
                a -= t * b; tmp = a; a = b; b = tmp;
                u -= t * v; tmp = u; u = v; v = tmp;
            }
            return safe_mod(u);
        }
};
using mint = modint<998244353>;

mint solve(int n, vector<long long> &a) {
    long long sum = 0;
    for (long long v : a) sum += v;
    sum = (sum - 1) / 2;
    vector<long long> s(n + 1, 0);
    rep(i, n) s[i + 1] = s[i] + a[i];
    const int el = n - n / 2, ol = n / 2;
    vector<vector<long long>> parity_sum(
        {vector<long long>(el + 1, 0), vector<long long>(ol + 1, 0)}
    );
    rep(i, n) {
        parity_sum[i & 1][i / 2 + 1] = parity_sum[i & 1][i / 2] + a[i];
    }
    mint ans = 1;
    {
        long long t = 0;
        for (int i = n - 1; i >= 2; --i) {
            t += a[i];
            ans += t <= sum;
        }
    }
    {
        for (int i = 1; i <= n; ++i) {
            long long t = s[i];
            if (t > sum) break;
            auto& cum = parity_sum[(i - 1) & 1];
            int p = (i - 1) / 2;
            int kmax = (n - i) / 2;
            long long thr = sum - t + cum[p + 1];
            int lk = 0, rk = kmax + 1;
            while (rk - lk > 1) {
                int mk = (lk + rk) / 2;
                if (cum[p + mk + 1] <= thr) {
                    lk = mk;
                } else {
                    rk = mk;
                }
            }
            ans += rk;
        }
    }
    {
        for (int i = 1; i <= n - 3; ++i) {
            long long t = s[i] + a[n - 1];
            if (t > sum) break;
            auto& cum = parity_sum[(i - 1) & 1];
            int p = (i - 1) / 2;
            int kmax = (n - 3 - i) / 2;
            long long thr = sum - t + cum[p + 1];
            int lk = 0, rk = kmax + 1;
            while (rk - lk > 1) {
                int mk = (lk + rk) / 2;
                if (cum[p + mk + 1] <= thr) {
                    lk = mk;
                } else {
                    rk = mk;
                }
            }
            ans += rk;
        }
    }
    {
        for (int i = 1; i <= n - 1; ++i) {
            long long t = s[i + 1] - a[0];
            if (t > sum) break;
            auto& cum = parity_sum[i & 1];
            int p = i / 2;
            int kmax = (n - 1 - i) / 2;
            long long thr = sum - t + cum[p + 1];
            int lk = 0, rk = kmax + 1;
            while (rk - lk > 1) {
                int mk = (lk + rk) / 2;
                if (cum[p + mk + 1] <= thr) {
                    lk = mk;
                } else {
                    rk = mk;
                }
            }
            ans += rk;
        }
    }
    {
        for (int i = 1; i <= n - 4; ++i) {
            long long t = s[i + 1] - a[0] + a[n - 1];
            if (t > sum) break;
            auto& cum = parity_sum[i & 1];
            int p = i / 2;
            int kmax = (n - 4 - i) / 2;
            long long thr = sum - t + cum[p + 1];
            int lk = 0, rk = kmax + 1;
            while (rk - lk > 1) {
                int mk = (lk + rk) / 2;
                if (cum[p + mk + 1] <= thr) {
                    lk = mk;
                } else {
                    rk = mk;
                }
            }
            ans += rk;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector<long long> a(n);
        read_vector(a);
        mint ans = solve(n, a);
        cout << ans.val() << '\n';
    }
    return 0;
}