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
    std::cin.tie(nullptr);

    int L, m, n;
    std::cin >> L >> m >> n;
    std::vector<std::set<int>> E(n);
    std::vector<int> deg(n);
    for (int k = 0; k < L; ++k) {
        int c;
        std::cin >> c;
        int lst = -1;
        for (int i = 0; i < c; ++i) {
            int x;
            std::cin >> x;
            --x;
            if (i > 0) {
                E[lst].insert(x);
            }
            lst = x;
        }
    }
    for (int u = 0; u < n; ++u) {
        for (int v : E[u]) {
            ++deg[v];
        }
    }

    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            int len = 1;
            int p = i;
            while ((int)E[p].size() == 1 && deg[*E[p].begin()] == 1) {
                p = *E[p].begin();
                ++len;
            }
            if (E[p].empty()) {
                ++cnt[len];
            }
        }
    }

    std::vector<std::pair<int, int>> non_zero;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) {
            non_zero.emplace_back(i, cnt[i]);
        }
    }

    std::vector<mint> f(m + 1);
    f[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (auto [x, y] : non_zero) {
            if (i >= x) {
                f[i] += f[i - x] * y;
            }
        }
    }
    std::cout << f[m] << "\n";
}