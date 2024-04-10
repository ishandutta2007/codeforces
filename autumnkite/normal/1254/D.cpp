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

template<typename _Val, typename _VV = std::plus<_Val>>
class fenwick_tree {
public:
    typedef std::size_t size_type;

protected:
    const _Val _E;

    size_type n;
    std::vector<_Val> val;

    _VV fun;

public:
    fenwick_tree() : fenwick_tree(0) {}

    fenwick_tree(size_type _n) : fenwick_tree(_n, _Val()) {}

    fenwick_tree(size_type _n, _Val E) : _E(E), n(_n), val(n + 1, _E) {}

    size_type size() const {
        return n;
    }

    void modify(size_type x, _Val v) {
        for (++x; x <= n; x += x & -x) {
            val[x] = fun(val[x], v);
        }
    }

    _Val query(size_type x) {
        _Val s = _E;
        for (; x; x ^= x & -x) {
            s = fun(s, val[x]);
        }
        return s;
    }
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, q;
	std::cin >> n >> q;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int idx = 0;
    std::vector<int> fa(n), dep(n), sz(n), son(n), top(n), dfn(n);
    
    auto dfs1 = [&](auto self, int u) -> void {
        sz[u] = 1;
        son[u] = -1;
        for (int v : E[u]) {
            if (v != fa[u]) {
                fa[v] = u;
                dep[v] = dep[u] + 1;
                self(self, v);
                sz[u] += sz[v];
                if (son[u] == -1 || sz[v] > sz[son[u]]) {
                    son[u] = v;
                }
            }
        }
    };

    auto dfs2 = [&](auto self, int u, int tp) -> void {
        top[u] = tp;
        dfn[u] = idx++;
        if (son[u] != -1) {
            self(self, son[u], tp);
        }
        for (int v : E[u]) {
            if (v != fa[u] && v != son[u]) {
                self(self, v, v);
            }
        }
    };

    fa[0] = -1, dep[0] = 0;
    dfs1(dfs1, 0);
    dfs2(dfs2, 0, 0);

    mint invn = mint(n).inv();
    std::vector<mint> a(n);
    fenwick_tree<mint> T(n);
    mint sum = 0;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int u;
            mint d;
            std::cin >> u >> d;
            --u;
            a[u] += d;
            sum += d * sz[u];
            T.modify(dfn[u], -d * sz[u]);
            if (son[u] != -1) {
                T.modify(dfn[son[u]], d * (n - sz[son[u]]));
            }
        } else {
            int u;
            std::cin >> u;
            --u;
            int t = u;
            mint ans = sum;
            while (u != -1) {
                ans += T.query(dfn[u] + 1) - T.query(dfn[top[u]]);
                if (fa[top[u]] != -1) {
                    ans += a[fa[top[u]]] * (n - sz[top[u]]);
                }
                u = fa[top[u]];
            }
            std::cout << ans * invn + a[t] << "\n";
        }
    }
}