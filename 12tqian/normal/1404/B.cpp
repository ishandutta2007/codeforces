#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
        a--, b--;
        vector<vector<int>> adj(n);
        vector<int> depth(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        function<void(int, int)> dfs_depth = [&](int src, int par) {
            for (int nxt: adj[src]) {
                if (nxt == par) continue;
                depth[nxt] = depth[src] + 1;
                dfs_depth(nxt, src);
            }
        };
        dfs_depth(b, -1);
        int diam = 0;
        function<int(int, int)> dfs_diam = [&](int src, int par) -> int {
            vector<int> depths;
            int max_depth = depth[src];
            for (int nxt: adj[src]) {
                if (nxt == par) continue;
                int dep = dfs_diam(nxt, src);
                depths.push_back(dep);
                max_depth = max(max_depth, dep);
            }
            sort(depths.begin(), depths.end());
            reverse(depths.begin(), depths.end());
            diam = max(diam, max_depth);
            if (depths.size() >= 2) {
                diam = max(diam, depths[0] + depths[1] - 2 * depth[src]);
            }
            return max_depth;
        };
        dfs_diam(b, -1);
        if (da * 2 >= db || depth[a] <= da || diam <= 2 * da) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}