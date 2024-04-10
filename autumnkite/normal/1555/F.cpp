#include <bits/stdc++.h>

class DSU {
    std::vector<int> fa;

public:
    DSU(int n) : fa(n) {
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
    }

    int find(int x) {
        return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        fa[y] = x;
        return true;
    }
};

struct max {
    int operator()(int a, int b) const {
        return std::max(a, b);
    }
};

#if __cplusplus > 201103L
template<typename _Val, typename _Tag = _Val, 
         typename _VV = std::plus<>, typename _VT = std::plus<>, typename _TT = std::plus<>>
#else
template<typename _Val, typename _Tag, 
         typename _VV, typename _VT, typename _TT>
#endif
class segment_tree {
public:
    typedef std::size_t size_type;

private:
    static size_type enlarge(size_type n) {
        size_type res = 1;
        while (res < n) {
            res <<= 1;
        }
        return res;
    }

protected:
    const size_type n, en;

    _VV fun_vv;
    _VT fun_vt;
    _TT fun_tt;

    std::vector<_Val> val;
    std::vector<_Tag> tag;

    void up(size_type u) {
        val[u] = fun_vv(val[u << 1], val[u << 1 | 1]);
    }

    void apply(size_type u, _Tag v) {
        val[u] = fun_vt(val[u], v);
        tag[u] = fun_tt(tag[u], v);
    }

    void down(size_type u) {
        apply(u << 1, tag[u]);
        apply(u << 1 | 1, tag[u]);
        tag[u] = _Tag();
    }

    void build(size_type u, size_type l, size_type r, const std::vector<_Val> &a) {
        if (l + 1 == r) {
            val[u] = a[l];
            return;
        }
        size_type mid = (l + r + 1) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid, r);
        up(u);
    }

    void modify(size_type u, size_type l, size_type r, size_type L, size_type R, _Tag v) {
        if (L <= l && r <= R) {
            apply(u, v);
            return;
        }
        size_type mid = (l + r + 1) >> 1;
        down(u);
        if (L < mid) {
            modify(u << 1, l, mid, L, R, v);
        }
        if (mid < R) {
            modify(u << 1 | 1, mid, r, L, R, v);
        }
        up(u);
    }

    _Val query(size_type u, size_type l, size_type r, size_type L, size_type R) {
        if (L <= l && r <= R) {
            return val[u];
        }
        size_type mid = (l + r + 1) >> 1;
        down(u);
        if (R <= mid) {
            return query(u << 1, l, mid, L, R);
        } else if (L >= mid) {
            return query(u << 1 | 1, mid, r, L, R);
        } else {
            return fun_vv(query(u << 1, l, mid, L, R), query(u << 1 | 1, mid, r, L, R));
        }
    }

public:
    segment_tree() : segment_tree(0) {}

    segment_tree(size_type _n) : n(_n), en(enlarge(n)), val(en << 1), tag(en << 1) {}

    segment_tree(const std::vector<_Val> &a) : n(a.size()), en(enlarge(n)), val(en << 1), tag(en << 1) {
        build(1, 0, n, a);
    }

    size_type size() const {
        return n;
    }

    void modify(size_type l, size_type r, _Tag v) {
        if (l < r) {
            modify(1, 0, n, l, r, v);
        }
    }

    _Val query(size_type l, size_type r) {
        if (l < r) {
            return query(1, 0, n, l, r);
        } else {
            return _Val();
        }
    }
};

class tree {
    int n;
    int idx;
    std::vector<std::vector<std::pair<int, int>>> E;
    std::vector<int> fa, sz, dep, dis, son, top, dfn;
    segment_tree<bool, bool, std::logical_or<>, std::logical_or<>, std::logical_or<>> T;

    void dfs(int u) {
        sz[u] = 1;
        son[u] = -1;
        for (auto [v, w] : E[u]) {
            if (v != fa[u]) {
                fa[v] = u;
                dep[v] = dep[u] + 1;
                dis[v] = dis[u] ^ w;
                dfs(v);
                sz[u] += sz[v];
                if (son[u] == -1 || sz[v] > sz[son[u]]) {
                    son[u] = v;
                }
            }
        }
    }

    void dfs(int u, int tp) {
        top[u] = tp;
        dfn[u] = idx++;
        if (son[u] != -1) {
            dfs(son[u], tp);
        }
        for (auto [v, w] : E[u]) {
            if (v != fa[u] && v != son[u]) {
                dfs(v, v);
            }
        }
    }

    int LCA(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = fa[top[u]];
            } else {
                v = fa[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    bool check(int u, int v) {
        while (top[u] != top[v]) {
            if (T.query(dfn[top[u]], dfn[u] + 1)) {
                return false;
            }
            u = fa[top[u]];
        }
        return !T.query(dfn[v] + 1, dfn[u] + 1);
    }

    void cover(int u, int v) {
        while (top[u] != top[v]) {
            T.modify(dfn[top[u]], dfn[u] + 1, true);
            u = fa[top[u]];
        }
        T.modify(dfn[v] + 1, dfn[u] + 1, true);
    }

public:
    tree(const std::vector<std::vector<std::pair<int, int>>> &_E) : 
      n(_E.size()), idx(0), E(_E), fa(n, -1), sz(n), dep(n), dis(n), son(n), top(n), dfn(n), T(n) {
        for (int i = 0; i < n; ++i) {
            if (fa[i] == -1) {
                dfs(i);
                dfs(i, i);
            }
        }
    }

    bool add_edge(int u, int v, int w) {
        if ((dis[u] ^ dis[v]) == w) {
            return false;
        }
        int z = LCA(u, v);
        if (!check(u, z) || !check(v, z)) {
            return false;
        }
        cover(u, z);
        cover(v, z);
        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> X(m), Y(m), W(m);
    DSU D(n);
    std::vector<std::vector<std::pair<int, int>>> E(n);
    std::vector<bool> ans(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> X[i] >> Y[i] >> W[i];
        --X[i], --Y[i];
        if (D.merge(X[i], Y[i])) {
            E[X[i]].emplace_back(Y[i], W[i]);
            E[Y[i]].emplace_back(X[i], W[i]);
            ans[i] = true;
        }
    }
    tree T(E);
    for (int i = 0; i < m; ++i) {
        if (!ans[i]) {
            ans[i] = T.add_edge(X[i], Y[i], W[i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ans[i]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}