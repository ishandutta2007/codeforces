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

using mint = modint<1000000007>;

const int INF = 0x3f3f3f3f;

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    std::vector<std::vector<int>> lcp(n + 1, std::vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] == s[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
    }

    auto check = [&](int i, int j, int l) {
        int t = lcp[i][j];
        if (t >= l || s[i + t] < s[j + t]) {
            return true;
        } else {
            return false;
        }
    };

    std::vector<std::vector<mint>> f(n + 1, std::vector<mint>(n + 1));
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1, INF));
    for (int i = 0; i <= n; ++i) {
        f[0][i] = 1;
        g[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (s[i - j] == '1') {
                if (i - j >= j && check(i - 2 * j, i - j, j)) {
                    f[i][j] = f[i - j][j];
                    g[i][j] = g[i - j][j] + 1;
                } else {
                    f[i][j] = f[i - j][j - 1];
                    g[i][j] = g[i - j][j - 1] + 1;
                }
            }
        }
        for (int j = 1; j <= n; ++j) {
            f[i][j] += f[i][j - 1];
            g[i][j] = std::min(g[i][j], g[i][j - 1]);
        }
    }

    std::cout << f[n][n] << "\n";

    int mn = INF;
    for (int i = 0; i <= n; ++i) {
        if (g[n][i] != INF) {
            mint ans = 0;
            for (int j = n - i; j < n; ++j) {
                ans = ans * 2 + (s[j] - '0');
            }
            if (i <= 30 && (1 << i) <= 2 * n) {
                mn = std::min(mn, (int)ans.val() + g[n][i]);
            } else {
                if (mn != INF) {
                    std::cout << mn << "\n";
                } else {
                    std::cout << ans + g[n][i] << "\n";
                }
                return 0;
            }
        }
    }
    std::cout << mn << "\n";
}