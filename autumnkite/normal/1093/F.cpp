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

using mint = modint<998244353>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, lim;
    std::cin >> n >> m >> lim;
    std::vector<int> a(n);
    std::vector p(n + 1, std::vector(m, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] > 0) {
            --a[i];
            p[i + 1][a[i]] = p[i][a[i]] + 1;
        } else {
            for (int j = 0; j < m; ++j) {
                p[i + 1][j] = p[i][j] + 1;
            }
        }
    }

    std::vector f(n + 1, std::vector(m, mint(0)));
    std::vector g(n + 1, mint(0));
    std::vector sum(m, mint(1));
    std::vector l(m, 0);
    g[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            while (l[j] < i - p[i][j] || l[j] <= i - lim) {
                sum[j] -= g[l[j]] - f[l[j]][j];
                ++l[j];
            }
            f[i][j] = sum[j];
            g[i] += f[i][j];
        }
        for (int j = 0; j < m; ++j) {
            sum[j] += g[i] - f[i][j];
        }
    }
    std::cout << g[n] << "\n";
}