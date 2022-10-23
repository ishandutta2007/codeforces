#include <type_traits>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) iterable.begin(), iterable.end()

template <typename T>
void print_vector(vector<T>& vec, string sep = " ", string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i].val();
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}


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
constexpr int mod = 1000000007;

using mint = modint<mod>;

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n, k;
        cin >> n >> k;
        vector<mint> p(n + 1, 0);
        p[1] = 1;
        for (int i = 0; i < k - 1; ++i) {
            if (i & 1) {
                for (int j = n - 2; j >= 0; --j) {
                    p[j] += p[j + 1];
                }
            } else {
                for (int j = 2; j <= n; ++j) {
                    p[j] += p[j - 1];
                }
            }
        }
        mint ans = 0;
        for (auto& v : p) ans += v;
        if (k > 1) ++ans;
        cout << ans.val() << '\n';
    }
    return 0;
}