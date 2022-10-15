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

const int MN = 100005, LOG = 19;

int n, m, u, v, sz[MN], bl[MN][LOG], dist[MN], down[MN], depth[MN];
vector<int> a[MN];

void dfs(int cur, int par, int d) {
    depth[cur] = d;
    dist[1] += depth[cur];
    bl[cur][0] = par;
    for (int i = 1; i < LOG; i++) bl[cur][i] = bl[bl[cur][i - 1]][i - 1];
    sz[cur] = 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur, d + 1);
        sz[cur] += sz[nxt];
        down[cur] += sz[nxt] + down[nxt];
    }
}

void dfs(int cur, int par) {
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dist[nxt] = dist[cur] + n - 2 * sz[nxt];
        dfs(nxt, cur);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) if (depth[u] - (1 << i) >= depth[v]) u = bl[u][i];
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    return bl[u][0];
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0, 0); dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (depth[u] < depth[v]) swap(u, v);
        int par = lca(u, v);
        int len = depth[u] + depth[v] - 2 * depth[par] + 1;
        if (par == v) {
            int cnt1 = sz[u], cnt2 = n - sz[v] + 1;
            int n1 = down[u], n2 = dist[v] - down[v];
            for (int nxt : a[v]) {
                if (lca(nxt, u) != v) continue;
                n2 += down[nxt] + sz[nxt];
                cnt2 += sz[nxt];
            }
            int tot = len * cnt1 * cnt2 + n1 * cnt2 + n2 * cnt1;
            //printf("%d %d %d %d %d\n", len, cnt1, cnt2, n1, n2);
            printf("%.8f\n", (double) tot / (double) (cnt1 * cnt2));
        } else {
            int cnt1 = sz[u], cnt2 = sz[v];
            int n1 = down[u], n2 = down[v];
            int tot = len * cnt1 * cnt2 + n1 * cnt2 + n2 * cnt1;
            printf("%.8f\n", (double) tot / (double) (cnt1 * cnt2));
        }
    }

    return 0;
}