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

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i];
        --a[i];
    }
    a.erase(std::unique(a.begin(), a.end()), a.end());
    m = a.size();

    std::vector<int> L(n, -1), R(n, -1);
    std::vector<int> sta;
    for (int i = 0; i < m; ++i) {
        while (!sta.empty() && sta.back() > a[i]) {
            sta.pop_back();
        }
        if (L[a[i]] != -1 && (sta.empty() || sta.back() < a[i])) {
            std::cout << 0 << "\n";
            return 0;
        }
        if (L[a[i]] == -1) {
            L[a[i]] = i;
        }
        R[a[i]] = i;
        sta.push_back(a[i]);
    }

    std::vector<std::vector<bool>> vis(n, std::vector<bool>(n));
    std::vector<std::vector<mint>> f(n, std::vector<mint>(n));

    auto solve = [&](auto self, int l, int r) -> mint {
        if (l > r) {
            return 1;
        }
        if (vis[a[l]][a[r]]) {
            return f[a[l]][a[r]];
        }
        int mn = n;
        for (int i = l; i <= r; i = R[a[i]] + 1) {
            mn = std::min(mn, a[i]);
        }
        mint pre = 0;
        for (int i = l; i <= L[mn]; i = R[a[i]] + 1) {
            pre += self(self, l, i - 1) * self(self, i, L[mn] - 1);
        }
        mint suf = 0;
        for (int i = r; i >= R[mn]; i = L[a[i]] - 1) {
            suf += self(self, i + 1, r) * self(self, R[mn] + 1, i);
        }
        mint ans = pre * suf;
        int lst = L[mn];
        for (int i = L[mn] + 1; i <= R[mn]; ++i) {
            if (a[i] == mn) {
                ans *= self(self, lst + 1, i - 1);
                lst = i;
            }
        }
        vis[a[l]][a[r]] = true;
        f[a[l]][a[r]] = ans;
        return ans;
    };

    std::cout << solve(solve, 0, m - 1) << "\n";
}