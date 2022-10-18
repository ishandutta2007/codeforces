/*
     []
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e5;

int n, m, timer, top, H = 1, T = 0, que[N + 10], dfn[N + 10], low[N + 10], stk[N + 10], to[N + 10], ans[N + 10], sz[N + 10];
bool instk[N + 10], vis[N + 10], orz[N + 10], qwq[N + 10];

namespace Edges {
    struct Edge {
        int to, nxt, val;
    } e[N + 10], E[N + 10];
    int etot = 1, hd[N + 10], Etot = 1, Hd[N + 10], ideg[N + 10];
    void adde(int x, int y, int z) { e[++etot] = {y, hd[x], z}, hd[x] = etot; }
    void addE(int x, int y, int z) { E[++Etot] = {y, Hd[x], z}, Hd[x] = Etot, ideg[y]++; }
} // namespace Edges
using namespace Edges;

void tarjan(int u) {
    // printf("%d\n", u);
    dfn[u] = low[u] = ++timer, instk[u] = 1, stk[++top] = u;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (dfn[v] == 0) tarjan(v), low[u] = min(low[u], low[v]);
        else if (instk[v]) low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u]) {
        to[0]++;
        // printf("scc-%d: ", to[0]);
        while (1) {
            int cur = stk[top--];
            // printf("%d ", cur);
            instk[cur] = 0, to[cur] = to[0], sz[to[0]]++;
            if (orz[cur]) vis[to[0]] = 1;
            if (cur == u) break;
        }
        if (sz[to[0]] > 1) vis[to[0]] = 1;
        // puts("");
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int Test = fr(); Test--;) {
        fr(n), fr(m), etot = Etot = 1, to[0] = top = timer = 0;
        for (int i = 1; i <= n; i++) hd[i] = Hd[i] = orz[i] = vis[i] = sz[i] = ideg[i] = dfn[i] = ans[i] = qwq[i] = instk[i] = to[i] = 0;
        for (int i = 1, u, v; i <= m; i++) {
            fr(u), fr(v);
            if (u == v) orz[u] = 1;
            adde(u, v, 0);
        }
        for (int i = 1; i <= n; i++)
            if (dfn[i] == 0) tarjan(i);
        for (int u = 1; u <= n; u++)
            for (int i = hd[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if (to[u] == to[v]) continue;
                addE(to[u], to[v], e[i].val);
                // printf("%d -> %d\n", to[u], to[v]);
            }
        H = 1, T = 0;
        for (int i = 1; i <= to[0]; i++)
            if (ideg[i] == 0) que[++T] = i;
        ans[to[1]] = 1, qwq[to[1]] = 1;
        while (H <= T) {
            int u = que[H++];
            for (int i = Hd[u]; i; i = E[i].nxt) {
                int v = E[i].to;
                ans[v] += ans[u];
                ans[v] = min(ans[v], 2ll);
                if (qwq[u] == 1) qwq[v] = 1;
                if (vis[u] == 1 && qwq[u] == 1) vis[v] = 1;
                ideg[v]--;
                if (ideg[v] == 0) que[++T] = v;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (qwq[to[i]] == 0) printf("0 ");
            else if (vis[to[i]]) printf("-1 ");
            else printf("%lld ", ans[to[i]]);
        }
        puts("");
    }
    return 0;
}