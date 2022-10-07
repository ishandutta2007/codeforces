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

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        char op;
        std::cin >> op;
        if (op == '+') {
            std::cin >> a[i];
        } else {
            a[i] = -1;
        }
    }

    mint ans = 0;
    for (int p = 0; p < n; ++p) {
        if (a[p] != -1) {
            std::vector<mint> f(n + 1);
            f[0] = 1;
            for (int i = 0; i < n; ++i) {
                if (i == p) {
                    continue;
                }
                std::vector<mint> g(n + 1);
                if (a[i] == -1) {
                    for (int j = 0; j < n; ++j) {
                        g[j] = f[j] + f[j + 1];
                    }
                    if (i < p) {
                        g[0] += f[0];
                    }
                } else {
                    for (int j = 0; j < n; ++j) {
                        if (std::make_pair(a[i], i) < std::make_pair(a[p], p)) {
                            g[j] = f[j] + (j > 0 ? f[j - 1] : 0);
                        } else {
                            g[j] = f[j] * 2;
                        }
                    }
                }
                f.swap(g);
            }
            ans += a[p] * std::accumulate(f.begin(), f.end(), mint(0));
        }
    }
    std::cout << ans << "\n";
}