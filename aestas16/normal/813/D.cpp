#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 5000 * 2, M = 5000 * 7, INF = 0x3f3f3f3f;

int n, m, s, S, t, maxflow, mincost, a[N + 10], d[N + 10], ecur[N + 10], que[N + 10], Hd, Tl;
bool vis[N + 10];

namespace Edges {
    struct Edge { int to, nxt, flow, val; } e[(M << 1) + 10];
    int hd[N + 10], etot = 1;
    void add(int x, int y, int flow, int val) { e[++etot] = {y, hd[x], flow, val}, hd[x] = etot; }
    void adde(int x, int y, int flow, int val) { add(x, y, flow, val), add(y, x, 0, -val); }
} // namespace Edges
using namespace Edges;

bool bfs() {
    memset(d, -1, sizeof(d)), Hd = 1, Tl = 0, que[++Tl] = s, d[s] = 0, ecur[s] = hd[s];
    while (Hd != Tl + 1) {
        int u = que[Hd++];
        (Hd == N + 1) && (Hd = 1), vis[u] = 0;
        for (int i = hd[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].flow == 0) continue;
            if (d[u] + e[i].val > d[v]) {
                d[v] = d[u] + e[i].val, ecur[v] = hd[v];
                if (vis[v] == 0) (Tl == N) && (Tl = 0), que[++Tl] = v, vis[v] = 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int u, int limit) {
    if (u == t) return limit;
    int flow = 0;
    vis[u] = 1;
    for (int i = ecur[u]; i && flow < limit; i = e[i].nxt) {
        int v = e[i].to;
        ecur[u] = i;
        if (vis[v] || e[i].flow == 0 || d[v] != d[u] + e[i].val) continue;
        int f = dfs(v, min(e[i].flow, limit - flow));
        if (f == 0) d[v] = INF;
        e[i].flow -= f, e[i ^ 1].flow += f, flow += f, mincost += e[i].val * f;
    }
    return vis[u] = 0, flow;
}

void dinic() {
    int flow = 0;
    while (bfs())
        while (flow = dfs(s, INF)) maxflow += flow;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n), m = 2, s = 0, S = n * 2 + 1, t = S + 1, adde(s, S, m, 0);
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 1; i <= n; i++) {
        adde(S, i, INF, 0), adde(i, i + n, 1, 1), adde(i + n, t, INF, 0);
        for (int j = i + 1; j <= n; j++) if (a[i] - 1 == a[j]) { adde(i + n, j, INF, 0); break; }
        for (int j = i + 1; j <= n; j++) if (a[i] + 1 == a[j]) { adde(i + n, j, INF, 0); break; }
        for (int j = i + 1; j <= n; j++) if (a[i] % 7 == a[j] % 7) { adde(i + n, j, INF, 0), adde(i, j, INF, 0); break; }
    }
    return dinic(), printf("%d\n", mincost), 0;
}