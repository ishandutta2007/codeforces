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

int n, u, v, q, depth[MN], bl[MN][LOG], psa[MN], ans[MN], mp[MN];
vector<int> a[MN];
pii edge[MN];

void dfs(int cur, int par, int d) {
    depth[cur] = d;
    bl[cur][0] = par;
    for (int i = 1; i < LOG; i++) bl[cur][i] = bl[bl[cur][i - 1]][i - 1];
    for (int nxt : a[cur]) if (nxt != par) dfs(nxt, cur, d + 1);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) if (depth[u] - (1 << i) >= depth[v]) u = bl[u][i];
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    return bl[u][0];
}

void dfs(int cur, int par) {
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        psa[cur] += psa[nxt];
    }
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        edge[i] = {u, v};
    }
    dfs(1, 0, 0);
    for (int i = 1; i < n; i++) {
        if (depth[edge[i].f] < depth[edge[i].s]) swap(edge[i].f, edge[i].s);
        mp[edge[i].f] = i;
    }
    cin >> q;
    for (; q > 0; q--) {
        cin >> u >> v;
        int par = lca(u, v);
        psa[u]++; psa[v]++;
        psa[par] -= 2;
    }
    dfs(1, 0);
    for (int i = 2; i <= n; i++) ans[mp[i]] = psa[i];
    for (int i = 1; i < n; i++) printf("%d ", ans[i]);

    return 0;
}