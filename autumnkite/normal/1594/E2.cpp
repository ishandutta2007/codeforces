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

using mint = modint<1000000007>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    std::cin >> k;
    int n;
    std::cin >> n;
    std::map<std::string, int> id;
    id["white"] = 0;
    id["yellow"] = 1;
    id["green"] = 2;
    id["blue"] = 3;
    id["red"] = 4;
    id["orange"] = 5;
    std::map<long long, int> col;
    for (int i = 0; i < n; ++i) {
        long long v;
        std::cin >> v;
        std::string s;
        std::cin >> s;
        col[v] = id[s];
        while (v) {
            if (!col.count(v)) {
                col[v] = -1;
            }
            v >>= 1;
        }
    }

    typedef std::array<mint, 6> state;
    std::map<long long, state> f;

    auto dfs = [&](auto &self, long long u, int d) -> state {
        if (!col.count(u)) {
            state res;
            res.fill(mint(4).pow((1ll << d) - 2));
            return res;
        }
        state res;
        for (int i = 0; i < 6; ++i) {
            if (col[u] == -1 || col[u] == i) {
                res[i] = 1;
            } else {
                res[i] = 0;
            }
        }
        if (d == 1) {
            return res;
        }
        for (int k = 0; k < 2; ++k) {
            state tmp = self(self, u << 1 | k, d - 1);
            mint sum = std::accumulate(tmp.begin(), tmp.end(), mint());
            for (int i = 0; i < 6; ++i) {
                res[i] *= sum - tmp[i] - tmp[i ^ 1];
            }
        }
        return res;
    };

    state res = dfs(dfs, 1, k);
    std::cout << std::accumulate(res.begin(), res.end(), mint()) << "\n";
}