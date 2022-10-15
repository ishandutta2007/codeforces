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

const int MN = 200005, LOG = 19;

int n, q, k, u, v, depth[MN], bl[MN][LOG];
vector<int> a[MN], vec;

void dfs(int cur, int par, int d) {
    bl[cur][0] = par;
    depth[cur] = d;
    for (int i = 1; i < LOG; i++) {
        bl[cur][i] = bl[bl[cur][i - 1]][i - 1];
    }
    for (int nxt : a[cur]) {
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

int dist(int u, int v) {
    int U = u, V = v;
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) u = bl[u][i];
    }
    if (u == v) return depth[U] + depth[V] - 2 * depth[u];
    for (int i = LOG - 1; i >= 0; i--) {
        if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    }
    return depth[U] + depth[V] - 2 * depth[bl[u][0]];
}

int main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (; q > 0; q--) {
        vec.clear();
        cin >> k;
        for (int i = 1; i <= k; i++) cin >> u, vec.push_back(u);
        int mx = 0, node = 0;
        for (int p : vec) {
            if (depth[p] > mx) mx = depth[p], node = p;
        }
        bool meme = 1;
        for (int p : vec) {
            int par = lca(p, node);
            if (par == p || dist(par, p) <= 1) continue;
            meme = 0; break;
        }
        if (meme) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}