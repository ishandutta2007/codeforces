/*
     []
*/

// 392699

#include <bits/stdc++.h>

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

const int N = 1e5;

int n, m;
long long f[N + 10], sum[N + 10];

namespace Edges {
    struct Edge {
        int to, nxt;
    } e[(N << 1) + 10];
    int etot = 1, hd[N + 10];
    void adde(int x, int y) { e[++etot] = {y, hd[x]}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

namespace TreeLink {
    int sz[N + 10], fa[N + 10], dep[N + 10], top[N + 10], ch[N + 10];
    void dfs1(int u, int p) {
        sz[u] = 1, fa[u] = p, dep[u] = dep[p] + 1;
        for (int i = hd[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (v == p) continue;
            dfs1(v, u), sz[u] += sz[v], sum[u] += sum[v] + sz[v];
            if (sz[v] > sz[ch[u]]) ch[u] = v;
        }
    }
    void dfs2(int u, int p) {
        top[u] = p;
        if (ch[u] == 0) return;
        dfs2(ch[u], p);
        for (int i = hd[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (v == fa[u] || v == ch[u]) continue;
            dfs2(v, v);
        }
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        return u;
    }
} // namespace TreeLink
using namespace TreeLink;

void dfs3(int u, int p) {
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p) continue;
        f[v] = f[u] + n - sz[v] * 2;
        dfs3(v, u);
    }
}

int getson(int u, int p) {
    while (top[u] != top[p]) {
        u = top[u];
        if (fa[u] == p) return u;
        u = fa[u];
    }
    return ch[p];
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(m);
    for (int i = 1, x, y; i < n; i++) fr(x), fr(y), adde(x, y), adde(y, x);
    dfs1(1, 0), dfs2(1, 1), f[1] = sum[1], dfs3(1, 1);
    for (int i = 1, x, y, z; i <= m; i++) {
        fr(x), fr(y);
        int LCA = lca(x, y);
        long long a, b, c, d;
        if (LCA == x) swap(x, y);
        if (LCA != y) a = sum[x], b = sum[y], c = sz[x], d = sz[y];
        else z = getson(x, y), a = sum[x], b = f[y] - (sum[z] + sz[z]), c = sz[x], d = n - sz[z];
        printf("%.9lf\n", 1.0 * (a * d + b * c) / c / d + dep[x] + dep[y] - 2 * dep[LCA] + 1);
    }
    return 0;
}