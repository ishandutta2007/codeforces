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

struct query {
    int u, v, lca, val;
};

bool cmp(query x, query y) {
    return x.val < y.val;
}

const int MN = 5005, LOG = 15;

int n, m, u, v, w, val[MN], bl[MN][LOG], depth[MN], best = 0;
pii edges[MN];
vector<int> a[MN];
vector<query> q;

int adj(int cur, int ed) {
    return cur == edges[ed].f ? edges[ed].s : edges[ed].f;
}

void dfs(int cur, int par, int d) {
    depth[cur] = d;
    bl[cur][0] = par;
    for (int i = 1; i < LOG; i++) bl[cur][i] = bl[bl[cur][i - 1]][i - 1];
    for (int ed : a[cur]) {
        int nxt = adj(cur, ed);
        if (nxt == par) continue;
        dfs(nxt, cur, d + 1);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) u = bl[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    }
    return bl[u][0];
}

void mark(int cur, int end, int col) {
    if (cur == end) return;
    for (int ed : a[cur]) {
        int nxt = adj(cur, ed);
        if (depth[nxt] > depth[cur]) continue;
        val[ed] = col;
        mark(nxt, end, col);
    }
}

void min_val(int cur, int end) {
    if (cur == end) return;
    for (int ed : a[cur]) {
        int nxt = adj(cur, ed);
        if (depth[nxt] > depth[cur]) continue;
        best = min(best, val[ed]);
        min_val(nxt, end);
    }
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(i);
        a[v].push_back(i);
        edges[i] = {u, v};
        val[i] = 1;
    }
    dfs(1, 0, 0);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        int par = lca(u, v);
        q.push_back({u, v, par, w});
    }
    sort(q.begin(), q.end(), cmp);
    for (query p : q) {
        mark(p.u, p.lca, p.val);
        mark(p.v, p.lca, p.val);
    }
    for (query p : q) {
        int mn = 0x3f3f3f3f;
        best = 0x3f3f3f3f;
        min_val(p.u, p.lca);
        mn = min(mn, best);
        best = 0x3f3f3f3f;
        min_val(p.v, p.lca);
        mn = min(mn, best);
        if (mn != p.val) return 0 * printf("-1\n");
    }
    for (int i = 1; i < n; i++) printf("%d ", val[i]);

    return 0;
}