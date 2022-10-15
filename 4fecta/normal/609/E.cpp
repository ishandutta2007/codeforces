#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct edge {
    int u, v, w, i;
};

const int MN = 200005, LOG = 19;

int n, m, u, v, w, bl[MN][LOG], mx[MN][LOG], ans[MN], cost, par[MN], vis[MN], depth[MN], val[MN];
vector<pii> a[MN];
edge edges[MN];

bool cmp(edge x, edge y) {
    return x.w < y.w;
}

bool cmp1(edge x, edge y) {
    return x.i < y.i;
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

void dfs(int cur, int par, int d, int w) {
    depth[cur] = d;
    val[cur] = w;
    bl[cur][0] = par;
    for (int i = 1; i < LOG; i++) bl[cur][i] = bl[bl[cur][i - 1]][i - 1];
    for (pii nxt : a[cur]) {
        if (nxt.f == par) continue;
        dfs(nxt.f, cur, d + 1, nxt.s);
    }
}

void dfs(int cur, int par) {
    mx[cur][0] = val[cur];
    for (int i = 1; i < LOG; i++) mx[cur][i] = max(mx[cur][i - 1], mx[bl[cur][i - 1]][i - 1]);
    for (pii nxt : a[cur]) {
        if (nxt.f == par) continue;
        dfs(nxt.f, cur);
    }
}

int lca(int u, int v) {
    int ret = 0;
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            ret = max(ret, mx[u][i]);
            u = bl[u][i];
        }
    }
    if (u == v) return ret;
    for (int i = LOG - 1; i >= 0; i--) {
        if (bl[u][i] != bl[v][i]) {
            ret = max({ret, mx[u][i], mx[v][i]});
            u = bl[u][i], v = bl[v][i];
        }
    }
    return max({ret, mx[u][0], mx[v][0]});
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        edges[i] = {u, v, w, i};
    }
    sort(edges + 1, edges + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        if (merge(edges[i].u, edges[i].v)) {
            cost += edges[i].w;
            vis[edges[i].i] = 1;
            a[edges[i].u].push_back({edges[i].v, edges[i].w});
            a[edges[i].v].push_back({edges[i].u, edges[i].w});
        }
    }
    dfs(1, 0, 0, 0); dfs(1, 0);
    sort(edges + 1, edges + m + 1, cmp1);
    for (int i = 1; i <= m; i++) {
        if (vis[i]) {ans[i] = cost; continue;}
        int best = lca(edges[i].u, edges[i].v);
        ans[i] = cost - best + edges[i].w;
    }
    for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);

    return 0;
}