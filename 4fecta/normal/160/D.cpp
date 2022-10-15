#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct edge {
    int u, v, w, dep, i;
};

bool cmp_w(edge x, edge y) {
    return x.w < y.w;
}

bool cmp_d(edge x, edge y) {
    return x.dep < y.dep;
}

const int MN = 100005, LOG = 19;

int n, m, u, v, w, bl[MN][LOG], col[MN], depth[MN], par[MN], pnum[MN], num[MN], mx[MN][LOG];
vector<edge> a[MN];
vector<edge> edges, query;
edge ed[MN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

void dfs(int cur, int par, int d, int num) {
    bl[cur][0] = par;
    depth[cur] = d;
    pnum[cur] = num;
    mx[cur][0] = ed[num].w;
    for (int i = 1; i < LOG; i++) bl[cur][i] = bl[bl[cur][i - 1]][i - 1], mx[cur][i] = max(mx[bl[cur][i - 1]][i - 1], mx[cur][i - 1]);
    for (edge nxt : a[cur]) {
        if (nxt.v == par) continue;
        dfs(nxt.v, cur, d + 1, nxt.i);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) if (depth[u] - (1 << i) >= depth[v]) u = bl[u][i];
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    return bl[u][0];
}

int largest(int u, int v) {
    int ret = 0;
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) if (depth[u] - (1 << i) >= depth[v]) ret = max(ret, mx[u][i]), u = bl[u][i];
    if (u == v) return ret;
    for (int i = LOG - 1; i >= 0; i--) if (bl[u][i] != bl[v][i]) ret = max({ret, mx[u][i], mx[v][i]}), u = bl[u][i], v = bl[v][i];
    return max({ret, mx[u][0], mx[v][0]});
}

void mark(int cur, int par, int w) {
    if (cur == par) return;
    int idx = pnum[cur];
    if (col[idx] < w) return;
    col[idx] = w;
    mark(bl[cur][0], par, w);
}

int main() {
    boost();

    memset(col, 0x3f, sizeof(col));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w, 0, i});
        ed[i] = {u, v, w, 0, i};
    }
    sort(edges.begin(), edges.end(), cmp_w);
    for (edge e : edges) {
        if (merge(e.u, e.v)) num[e.i] = 1, a[e.u].push_back({0, e.v, e.w, 0, e.i}), a[e.v].push_back({0, e.u, e.w, 0, e.i});
        else query.push_back(e);
    }
    dfs(1, 0, 0, 0);
    for (int i = 0; i < query.size(); i++) {
        edge &e = query[i];
        int par = lca(e.u, e.v);
        e.dep = depth[par];
        //printf("dep %d\n", depth[par]);
    }
    sort(query.begin(), query.end(), cmp_d);
    for (edge e : query) {
        if (largest(e.u, e.v) < e.w) continue;
        int par = lca(e.u, e.v);
        mark(e.u, par, e.w);
        mark(e.v, par, e.w);
        //printf("%d %d %d %d\n", e.u, e.v, e.w, e.dep);
        num[e.i] = 2;
    }
    for (int i = 1; i <= m; i++) {
        if (num[i] == 1 && ed[i].w < col[i]) printf("any\n");
        else if (num[i] == 2 || ed[i].w == col[i]) printf("at least one\n");
        else printf("none\n");
    }

    return 0;
}