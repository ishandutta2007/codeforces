#include <bits/stdc++.h>

template<int id>
class dynamic_modint {
    using mint = dynamic_modint<id>;

protected:
    static unsigned P;

    unsigned v;

public:
    dynamic_modint() : v() {}

    template<typename T, typename std::enable_if<std::__and_<
      std::is_signed<T>, std::is_integral<T>>::value, bool>::type = true>
    dynamic_modint(T _v) {
        long long tmp = _v % static_cast<long long>(P);
        if (tmp < 0) {
            tmp += P;
        }
        v = tmp;
    }

    template<typename T, typename std::enable_if<std::__and_<
      std::is_unsigned<T>, std::is_integral<T>>::value, bool>::type = true>
    dynamic_modint(T _v) {
        v = _v % P;
    }

    unsigned val() const {
        return v;
    }

    static unsigned mod() {
        return P;
    }

    static void set_mod(unsigned _P) {
        P = _P;
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

template<int id>
unsigned dynamic_modint<id>::P = 0;

using mint = dynamic_modint<0>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, L, P;
    std::cin >> n >> m >> L >> P;
    mint::set_mod(P);

    std::vector C(n + 1, std::vector(n + 1, mint(0)));
    for (int i = 0; i <= n; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    std::vector g(n + 1, mint(0));
    g[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            g[i] += g[j] * g[i - j - 1] * C[i - 1][j];
        }
    }

    std::vector vis(n + 1, std::vector(m + 1, std::vector(L + 1, false)));
    std::vector f(n + 1, std::vector(m + 1, std::vector(L + 1, mint(0))));

    auto DP = [&](auto &self, int n, int m, int L) -> mint {
        if (n < L) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (m == 1) {
            if (L == 1) {
                return g[n];
            } else {
                return 0;
            }
        }
        if (vis[n][m][L]) {
            return f[n][m][L];
        }
        vis[n][m][L] = true;
        mint &ans = f[n][m][L];
        for (int i = 0; i < n; ++i) {
            for (int j = std::max(0, L - n + i + 1); j <= L && j <= i; ++j) {
                ans += self(self, i, m - 1, j)
                       * self(self, n - i - 1, m - 1, L - j)
                       * C[n - 1][i];
            }
        }
        return ans;
    };

    std::cout << DP(DP, n, m, L) << "\n";
}