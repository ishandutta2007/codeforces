#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 392699;

int n, m, k, _, val[(N << 1) + 10];

namespace LCA {
    int sz[N + 10], fa[N + 10], dep[N + 10], ltop[N + 10], ch[N + 10];
    vector<int> e[N + 10];
    void adde(int x, int y) { e[x].push_back(y); }
    void dfs1(int u, int p) {
        sz[u] = 1, fa[u] = p, dep[u] = dep[p] + 1;
        for (auto v : e[u]) {
            if (v == p) continue;
            dfs1(v, u), sz[u] += sz[v];
            if (sz[v] > sz[ch[u]]) ch[u] = v;
        }
    }
    void dfs2(int u, int p) {
        ltop[u] = p;
        if (ch[u] == 0) return;
        dfs2(ch[u], p);
        for (auto v : e[u]) {
            if (v == fa[u] || v == ch[u]) continue;
            dfs2(v, v);
        }
    }
    int lca(int u, int v) {
        while (ltop[u] != ltop[v]) {
            if (dep[ltop[u]] < dep[ltop[v]]) swap(u, v);
            u = fa[ltop[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        return u;
    }
    void main(int rt) { dfs1(rt, 0), dfs2(rt, rt); }
} // namespace LCA

namespace Dijkstra {
    int dis[N + 10];
    bool vis[N + 10];
    vector<pair<int, int>> e[N + 10];
    struct Node {
        int val, u;
        bool operator<(const Node &a) const { return val > a.val; }
    };
    template <class T> struct heap {
        T h[(N << 2) + 10];
        int sz;
        void push(T x) { h[++sz] = x, std::push_heap(h + 1, h + sz + 1); }
        void pop() { std::pop_heap(h + 1, h + sz + 1), sz--; }
        T top() { return h[1]; }
        int size() { return sz; }
    };
    heap<Node> q;
    void adde(int x, int y, int z) { e[x].push_back({y, z}); }
    void main() {
        memset(dis, 0x3f, sizeof(dis)), memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= k; i++) q.push({dis[i] = 0, i});
        while (q.size()) {
            int u = q.top().u;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto i : e[u]) {
                int v = i.first, w = i.second;
                if (dis[u] + w < dis[v]) q.push({dis[v] = dis[u] + w, v});
            }
        }
    }
} // namespace Dijkstra

namespace MST {
    struct Edge { int u, v, w; } e[N + 10];
    int tot, fa[(N << 1) + 10];
    int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
    void main() {
        for (int i = 1; i <= m; i++) e[i].w += Dijkstra::dis[e[i].u] + Dijkstra::dis[e[i].v];
        sort(e + 1, e + 1 + m, [] (Edge a, Edge b) { return a.w < b.w; }), tot = n;
        for (int i = 1; i <= (n << 1); i++) fa[i] = i;
        for (int i = 1, etot = 0; i <= m && etot < n; i++) {
            int u = find(e[i].u), v = find(e[i].v);
            if (u == v) continue;
            fa[u] = fa[v] = ++tot, val[tot] = e[i].w, LCA::adde(u, tot), LCA::adde(tot, u), LCA::adde(v, tot), LCA::adde(tot, v), etot++;
        }
    }
} // namespace MST

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n, m, k, _);
    for (int i = 1, u, v, w; i <= m; i++) fr(u, v, w), Dijkstra::adde(u, v, w), Dijkstra::adde(v, u, w), MST::e[i] = {u, v, w};
    Dijkstra::main(), MST::main(), LCA::main(MST::tot);
    for (int i = 1, a, b; i <= _; i++) fr(a, b), printf("%lld\n", val[LCA::lca(a, b)]);
    return 0;
}