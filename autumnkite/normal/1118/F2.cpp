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

    int n, m;
    std::cin >> n >> m;
    std::vector<int> col(n);
    std::vector<std::vector<int>> nd(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> col[i];
        --col[i];
        if (col[i] != -1) {
            nd[col[i]].push_back(i);
        }
    }
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    std::vector<int> fa(n, -1);
    int idx = 0;
    std::vector<int> dfn(n), end(n);

    auto dfs = [&](auto &self, int u) -> void {
        dfn[u] = idx++;
        for (int v : E[u]) {
            if (v != fa[u]) {
                fa[v] = u;
                self(self, v);
            }
        }
        end[u] = idx;
    };

    dfs(dfs, 0);

    auto check = [&](int u, int v) {
        return dfn[u] <= dfn[v] && dfn[v] < end[u];
    };

    for (int i = 0; i < m; ++i) {
        std::sort(nd[i].begin(), nd[i].end(), [&](int u, int v) {
            return dfn[u] < dfn[v];
        });
        for (int j = 1; j < (int)nd[i].size(); ++j) {
            int u = nd[i][j - 1], v = nd[i][j];
            for (int x = u; x != -1; x = fa[x]) {
                if (col[x] != -1 && col[x] != i) {
                    std::cout << 0 << "\n";
                    return 0;
                }
                col[x] = i;
                if (check(x, v)) {
                    break;
                }
            }
            for (int x = v; x != -1; x = fa[x]) {
                if (col[x] != -1 && col[x] != i) {
                    std::cout << 0 << "\n";
                    return 0;
                }
                col[x] = i;
                if (check(x, u)) {
                    break;
                }
            }
        }
    }

    std::vector<mint> f(n), g(n);

    auto get_ans = [&](auto &self, int u) -> void {
        if (col[u] != -1) {
            f[u] = 1;
            for (int v : E[u]) {
                if (v != fa[u]) {
                    self(self, v);
                    f[u] *= f[v] + g[v];
                }
            }
            g[u] = 0;
        } else {
            g[u] = 1;
            for (int v : E[u]) {
                if (v != fa[u]) {
                    self(self, v);
                    g[u] *= f[v] + g[v];
                }
            }
            f[u] = 0;
            for (int v : E[u]) {
                if (v != fa[u]) {
                    f[u] += g[u] * (f[v] + g[v]).inv() * f[v];
                }
            }
        }
    };

    get_ans(get_ans, 0);
    std::cout << f[0] << "\n";
}