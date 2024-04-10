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

const int N = 2e5;

map<int, int> mp[N + 10];
vector<int> G[N + 10];
int n, m, k, dis[N + 10];
bool vis[N + 10], evis[(N << 1) + 10];

namespace Edges {
    struct Edge {
        int to, nxt, val;
    } e[(N << 1) + 10], E[(N << 1) + 10];
    int hd[N + 10], Hd[N + 10], odeg[N + 10], Etot, etot;
    void adde(int x, int y, int z) { e[++etot] = {y, hd[x], z}, hd[x] = etot; }
    void addE(int x, int y, int z) { E[++Etot] = {y, Hd[x], z}, Hd[x] = Etot, odeg[x]++; }
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
    // vis[u] = 1;
    // for (int i = hd[u]; i; i = e[i].nxt) {
    //     int v = e[i].to;
    //     if (vis[v]) continue;
    //     if (dis[u] + e[i].val == dis[v]) addE(u, v, e[i].val), addE(v, u, e[i].val), build(v);
    // }
    for (int i = 1; i <= n; i++)
        for (int j = hd[i]; j; j = e[j].nxt) {
            int k = e[j].to;
            if (dis[i] + e[j].val == dis[k]) G[k].push_back(i), odeg[k]++;
        }
}

void dfs(int u) {
    // printf("u = %lld\n", u);
    if (u > n) {
        for (int i = 1; i <= m; i++) putchar(evis[i] + '0');
        return (void)(k--, puts(""));
    }
    for (int i = 0; i < G[u].size(); i++) {
        if (k == 0) return;
        int v = G[u][i];
        // printf("id = %lld\n", mp[u][v]);
        evis[mp[u][v]] = 1, dfs(u + 1), evis[mp[u][v]] = 0;
    }
}

struct OI {
    int RP, score;
} FJOI2021;

signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    fr(n), fr(m), fr(k);
    for (int i = 1, u, v; i <= m; i++) fr(u), fr(v), adde(u, v, 1), adde(v, u, 1), mp[u][v] = mp[v][u] = i;
    Dijkstra(), memset(vis, 0, sizeof(vis)), build(1);
    long long tmp = 1;
    for (int i = 2; i <= n; i++) {
        tmp = 1ll * tmp * odeg[i];
        if (tmp > k) break;
    }
    k = min(tmp, k), printf("%lld\n", k), dfs(2);
    return 0;
}