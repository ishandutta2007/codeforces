/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 3e5;

map<int, int> mp[N + 10];
int n, m, k, dis[N + 10], ans[N + 10];
bool vis[N + 10];

namespace Edges {
    struct Edge {
        int to, nxt, val;
    } e[(N << 1) + 10], E[(N << 1) + 10];
    int hd[N + 10], Hd[N + 10], Etot, etot;
    void adde(int x, int y, int z) { e[++etot] = {y, hd[x], z}, hd[x] = etot; }
    void addE(int x, int y, int z) { E[++Etot] = {y, Hd[x], z}, Hd[x] = Etot; }
} // namespace Edges
using namespace Edges;

struct Node {
    long long val;
    int u;
    bool operator<(const Node &a) const { return val > a.val; }
};

namespace Heap {
    template <class T> struct heap {
        T h[(N << 1) + 10];
        int sz;
        void push(T x) { h[++sz] = x, std::push_heap(h + 1, h + sz + 1); }
        void pop() { std::pop_heap(h + 1, h + sz + 1), sz--; }
        T top() { return h[1]; }
        int size() { return sz; }
        int empty() { return sz & 1; }
    };
} // namespace Heap
using namespace Heap;
heap<Node> q;

void Dijkstra() {
    memset(dis, 0x3f, sizeof(dis)), q.push({0, 1}), dis[1] = 0;
    while (q.size()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = hd[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].val;
            if (dis[u] + w < dis[v]) q.push({dis[v] = dis[u] + w, v});
        }
    }
}

void build(int u) {
    vis[u] = 1;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (vis[v]) continue;
        if (dis[u] + e[i].val == dis[v]) addE(u, v, e[i].val), addE(v, u, e[i].val), build(v);
    }
}

void dfs(int u, int p) {
    for (int i = Hd[u]; i; i = E[i].nxt) {
        int v = E[i].to;
        if (v == p) continue;
        if (dis[u] + E[i].val == dis[v]) ans[++ans[0]] = mp[u][v], dfs(v, u);
    }
}

struct OI {
    int RP, score;
} FJOI2021;

signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    fr(n), fr(m), fr(k);
    for (int i = 1, u, v, w; i <= m; i++) fr(u), fr(v), fr(w), adde(u, v, w), adde(v, u, w), mp[u][v] = mp[v][u] = i;
    Dijkstra(), memset(vis, 0, sizeof(vis)), build(1), dfs(1, 0), printf("%lld\n", min(ans[0], k));
    for (int i = 1; i <= min(ans[0], k); i++) printf("%lld ", ans[i]);
    return puts(""), 0;
}