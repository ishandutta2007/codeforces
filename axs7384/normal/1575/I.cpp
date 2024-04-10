#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 9;

struct BIT {
    int n;
    long long s[N];
    void init(int _n) { n = _n; }
    void upd(int p, long long k) {
        for (; p <= n; p += p & -p) s[p] += k;
    }
    long long sum(int p) {
        long long r = 0;
        for (; p; p -= p & -p) r += s[p];
        return r;
    }
    long long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
} bit;

long long a[N], b[N];

int tot, p[N], dep[N], sz[N], hc[N], top[N], dfn[N];

vector<int> G[N];

void dfs1(int u, int _p) {
    dep[u] = dep[p[u] = _p] + 1;
    sz[u] = 1; hc[u] = 0;
    for (int v : G[u]) if (v != _p) {
        dfs1(v, u); sz[u] += sz[v];
        if (sz[v] > sz[hc[u]]) hc[u] = v;
    }
}

void dfs2(int u, int _top) {
    top[u] = _top; dfn[u] = ++tot;
    if (hc[u]) dfs2(hc[u], _top);
    for (int v : G[u]) if (v != p[u] && v != hc[u]) dfs2(v, v);
}

void upd(int u, int c) {
    a[u] = c;
    if (u != 1) {
        long long pre = b[dfn[u]];
        b[dfn[u]] = max(abs(a[u] + a[p[u]]), abs(a[u] - a[p[u]]));
        bit.upd(dfn[u], b[dfn[u]] - pre);
    }
    if (hc[u]) {
        int v = hc[u];
        long long pre = b[dfn[v]];
        b[dfn[v]] = max(abs(a[v] + a[p[v]]), abs(a[v] - a[p[v]]));
        bit.upd(dfn[v], b[dfn[v]] - pre);
    }
}

long long query(int u, int v) {
    long long dis = 0;
    for (; top[u] != top[v]; u = p[top[u]]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        dis += bit.sum(dfn[top[u]], dfn[u]);
        int w = top[u];
        dis += max(abs(a[w] + a[p[w]]), abs(a[w] - a[p[w]])) - b[dfn[w]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    if (u != v) dis += bit.sum(dfn[u] + 1, dfn[v]);
    return dis;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 1);
    bit.init(n);
    for (int i = 2; i <= n; ++i) {
        b[dfn[i]] = max(abs(a[i] + a[p[i]]), abs(a[i] - a[p[i]]));
        bit.upd(dfn[i], b[dfn[i]]);
    }
    for (int i = 1; i <= q; ++i) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int u, c;
            scanf("%d %d", &u, &c);
            upd(u, c);
        }
        else if (op == 2) {
            int u, v;
            scanf("%d %d", &u, &v);
            long long ans = query(u, v);
            printf("%lld\n", ans);
        }
    }
    return 0;
}