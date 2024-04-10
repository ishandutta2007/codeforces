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

const int MN = 100005, LOG = 19;

int n, q, x, y, k, u, v, depth[MN], bl[MN][LOG];
vector<int> a[MN];

void dfs(int cur, int par, int d) {
    bl[cur][0] = par;
    depth[cur] = d;
    for (int i = 1; i < LOG; i++) bl[cur][i] = bl[bl[cur][i - 1]][i - 1];
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur, d + 1);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) if (depth[u] - (1 << i) >= depth[v]) u = bl[u][i];
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    return bl[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0, 0);
    cin >> q;
    for (; q > 0; q--) {
        cin >> x >> y >> u >> v >> k;
        int d1 = dist(u, v);
        int d2 = min(dist(u, x) + dist(y, v), dist(u, y) + dist(x, v)) + 1;
        if ((k >= d1 && k % 2 == d1 % 2) || (k >= d2 && k % 2 == d2 % 2)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}