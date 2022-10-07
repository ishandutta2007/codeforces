#include <bits/stdc++.h>

template<unsigned P>
class modint {
    static_assert(1 <= P);

    using mint = modint<P>;

protected:
    unsigned v;

public:
    modint() : v() {}

    template<typename T, 
             typename std::enable_if<
                      std::is_signed<T>::value
                      && std::is_integral<T>::value,
                      bool>::type = true>
    modint(T _v) {
        long long tmp = _v % static_cast<long long>(P);
        if (tmp < 0) {
            tmp += P;
        }
        v = tmp;
    }

    template<typename T, 
             typename std::enable_if<
                      std::is_unsigned<T>::value
                      && std::is_integral<T>::value,
                      bool>::type = true>
    modint(T _v) {
        v = _v % P;
    }

    unsigned val() const {
        return v;
    }

    static constexpr unsigned mod() {
        return P;
    }

    static mint raw(unsigned v) {
        mint res;
        res.v = v;
        return res;
    }

    mint &operator+=(const mint &rhs) {
        v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
        return *this;
    }

    mint &operator++() {
        v + 1 < P ? ++v : v = 0;
        return *this;
    }

    mint operator++(int) {
        mint tmp = *this;
        v + 1 < P ? ++v : v = 0;
        return tmp;
    }

    mint &operator-=(const mint &rhs) {
        v < rhs.v ? v += P - rhs.v : v -= rhs.v;
        return *this;
    }

    mint &operator--() {
        v == 0 ? v = P - 1 : --v;
        return *this;
    }

    mint operator--(int) {
        mint tmp = *this;
        v == 0 ? v = P - 1 : --v;
        return tmp;
    }

    mint operator-() const {
        mint res;
        res.v = v == 0 ? 0 : P - v;
        return res;
    }

    mint &operator*=(const mint &rhs) {
        v = static_cast<unsigned long long>(v) * rhs.v % P;
        return *this;
    }

    mint pow(unsigned long long b) const {
        mint a(*this), s(1);
        for (; b; b >>= 1) {
            if (b & 1) {
                s *= a;
            }
            a *= a;
        }
        return s;
    }

    mint inv() const {
        return pow(P - 2);
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
        return mint(lhs) += rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {
        return mint(lhs) -= rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
        return mint(lhs) *= rhs;
    }

    friend bool operator==(const mint &lhs, const mint &rhs) {
        return lhs.v == rhs.v;
    }

    friend bool operator!=(const mint &lhs, const mint &rhs) {
        return lhs.v != rhs.v;
    }

    friend std::istream &operator>>(std::istream &in, mint &x) {
        return in >> x.v;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &x) {
        return out << x.v;
    }
};

template<typename _Val, typename _VV = std::plus<_Val>>
class fenwick_tree {
public:
    typedef std::size_t size_type;

protected:
    const _Val E;

    size_type n;
    std::vector<_Val> val;

    _VV fun;

public:
    fenwick_tree() : fenwick_tree(0) {}

    fenwick_tree(size_type _n)
    : E(), n(_n), val(n + 1, E) {}

    fenwick_tree(size_type _n, const _Val &_E)
    : E(_E), n(_n), val(n + 1, E) {}

    size_type size() const {
        return n;
    }

    void modify(size_type x, _Val v) {
        for (++x; x <= n; x += x & -x) {
            val[x] = fun(val[x], v);
        }
    }

    _Val query(size_type x) {
        _Val s = E;
        for (; x; x ^= x & -x) {
            s = fun(s, val[x]);
        }
        return s;
    }
};

using mint = modint<998244353>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
            --a[i][j];
        }
    }

    std::vector<std::vector<mint>> f(n + 1, std::vector<mint>(n + 1));
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i][0] = f[i - 1][0] * i;
        for (int j = 1; j <= i; ++j) {
            f[i][j] = f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    std::vector<mint> pw(n);
    pw[0] = 1;
    for (int i = 1; i < n; ++i) {
        pw[i] = pw[i - 1] * f[n][n];
    }

    mint ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[0][i] > a[0][j]) {
                ans += f[n - i - 1][0];
            }
        }
    }
    ans *= pw[n - 1];

    auto solve = [&](const std::vector<int> &a, const std::vector<int> &b) {
        mint res = 0;
        int cnt = 0;
        std::vector<int> vis(n);
        fenwick_tree<int> S(n), T(n);
        for (int i = 0; i < n; ++i) {
            if (!vis[b[i]]) {
                T.modify(b[i], 1);
                ++cnt;
            }
            vis[b[i]] ^= 1;
            int x = a[i] - S.query(a[i]), y = T.query(a[i]);
            x -= y;
            if (vis[b[i]] && b[i] < a[i]) {
                --y;
            }
            int k = n - i - 1;
            res += f[k][k - cnt] * x;
            res += f[k][k - cnt + 1] * y;
            S.modify(a[i], 1);
            if (vis[a[i]]) {
                T.modify(a[i], -1);
                --cnt;
            }
            vis[a[i]] ^= 1;
        }
        return res;
    };

    for (int i = 1; i < n; ++i) {
        ans += solve(a[i], a[i - 1]) * pw[n - i - 1];
    }
    std::cout << ans << "\n";
}