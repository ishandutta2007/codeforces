// https://codeforces.com/contest/1569/submission/128302340
//  
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
    mint a, h;
    std::cin >> n >> a >> h;
    std::vector<mint> pw((1 << n) + 1);
    pw[0] = 1;
    for (int i = 1; i <= (1 << n); ++i) {
        pw[i] = pw[i - 1] * a;
    }
    int tot = 1 << (n - 1);
    std::vector<int> p(tot);
    auto dfs = [&](auto self, int S, int u, int l, int r, int d) -> int {
        if (l + 1 == r) {
            return l;
        }
        int mid = (l + r + 1) >> 1;
        int L = self(self, S, u << 1, l, mid, d + 1);
        int R = self(self, S, u << 1 | 1, mid, r, d + 1);
        if (S >> u & 1) {
            p[R] = (1 << d) + 1;
            return L;
        } else {
            p[L] = (1 << d) + 1;
            return R;
        }
    };
    auto hash = [&](int t) {
        mint res = 0;
        for (int i = 0; i < tot; ++i) {
            res += (i + t + 1) * pw[p[i]];
        }
        return res;
    };
    std::map<int, std::vector<int>> st1, st2;
    for (int S = 0; S < (1 << tot); S += 2) {
        int t = dfs(dfs, S, 1, 0, tot, 1);
        p[t] = 1;
        st1[hash(0).val()] = p;
        p[t] = 2;
        st2[hash(0).val()] = p;
    }
    for (int S = 0; S < (1 << tot); S += 2) {
        int t = dfs(dfs, S, 1, 0, tot, 1);
        p[t] = 1;
        unsigned ht1 = (h - hash(tot)).val();
        if (st2.count(ht1)) {
            for (int x : st2[ht1]) {
                std::cout << x << " ";
            }
            for (int x : p) {
                std::cout << x << " ";
            }
            std::cout << "\n";
            return 0;
        }
        p[t] = 2;
        unsigned ht2 = (h - hash(tot)).val();
        if (st1.count(ht2)) {
            for (int x : st1[ht2]) {
                std::cout << x << " ";
            }
            for (int x : p) {
                std::cout << x << " ";
            }
            std::cout << "\n";
            return 0;
        }
    }
    std::cout << -1 << "\n";
}