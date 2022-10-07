#include <bits/stdc++.h>

template<unsigned P>
class modint {
    static_assert(1 <= P);

    using mint = modint<P>;

protected:
    unsigned v;

public:
    modint() : v() {}

    template<typename T, typename std::enable_if<std::__and_<
      std::is_signed<T>, std::is_integral<T>>::value, bool>::type = true>
    modint(T _v) {
        long long tmp = _v % static_cast<long long>(P);
        if (tmp < 0) {
            tmp += P;
        }
        v = tmp;
    }

    template<typename T, typename std::enable_if<std::__and_<
      std::is_unsigned<T>, std::is_integral<T>>::value, bool>::type = true>
    modint(T _v) {
        v = _v % P;
    }

    unsigned val() const {
        return v;
    }

    static constexpr unsigned mod() {
        return P;
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
        return mint(0) -= *this;
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
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<bool> a(n), b(m);
    for (int i = 0; i < k; ++i) {
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;
        --r1, --c1, --r2, --c2;
        a[r1] = a[r2] = true, b[c1] = b[c2] = true;
    }

    auto DP = [&](const std::vector<bool> &a) {
        int n = a.size();
        std::vector<std::vector<mint>> f(n + 1, std::vector<mint>(n + 1));
        f[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i + 1][j] += f[i][j];
                if (i + 1 < n && !a[i] && !a[i + 1]) {
                    f[i + 2][j + 1] += f[i][j];
                }
            }
        }
        return f[n];
    };

    int N = std::max(n, m);

    std::vector<mint> fac(N + 1);
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fac[i] = fac[i - 1] * i;
    }

    std::vector<std::vector<mint>> C(N + 1, std::vector<mint>(N + 1));
    for (int i = 0; i <= N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    int cx = 0, cy = 0;
    for (int i = 0; i < n; ++i) {
        cx += !a[i];
    }
    for (int i = 0; i < m; ++i) {
        cy += !b[i];
    }

    auto f = DP(a), g = DP(b);
    mint ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i * 2 + j <= cx && i + j * 2 <= cy) {
                ans += f[i] * g[j] * C[cx - 2 * i][j] * C[cy - 2 * j][i] * fac[i] * fac[j];
            }
        }
    }
    std::cout << ans << "\n";
}