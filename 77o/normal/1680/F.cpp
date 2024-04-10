#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1), tr(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> used(n + 1);
    vector<int> tin(n + 1);
    int cur_time = 0;
    int bad_edge_count = 0;
    vector<int> sub_bad(n + 1), sub_good(n + 1);
    auto dfs = [&](const auto& self, int v, int p) -> void {
        tin[v] = ++cur_time;
        for (int u : g[v]) {
            if (!used[u]) {
                tr[v].push_back(u);
                used[u] = 3 - used[v];
                self(self, u, v);
                sub_bad[v] += sub_bad[u];
                sub_good[v] += sub_good[u];
            } else if (used[u] != used[v] && tin[u] < tin[v] && u != p) {
                ++sub_good[v];
                --sub_good[u];
            } else if (used[u] == used[v] && tin[u] < tin[v]) {
                ++sub_bad[v];
                --sub_bad[u];
                ++bad_edge_count;
            }
        }
    };
    used[1] = 1;
    dfs(dfs, 1, 0);
    if (bad_edge_count <= 1) {
        cout << "YES\n";
        int recolor = 0;
        for (int v = 1; v <= n; v++)
            for (int u : g[v])
                recolor |= used[v] == 1 && used[u] == 1;
        for (int v = 1; v <= n; v++)
            cout << ((used[v] - 1) ^ recolor);
        cout << '\n';
        return;
    }
    
    auto contract = [&](const auto &self, int v, bool recolor) -> void {
        int nxt = -1;
        if (sub_bad[v] == bad_edge_count && sub_good[v] == 0) {
            recolor = true;
        }   
        if (recolor) {
            used[v] = 3 - used[v];
        }
        for (int u : tr[v])
            self(self, u, recolor);
    };
    contract(contract, 1, false);
    
    int bad = 0;
    int recolor = 0;
    for (int v = 1; v <= n; v++)
        for (int u : g[v]) {
            recolor |= used[v] == 1 && used[u] == 1;
            bad += used[v] == used[u];
        }
    if (bad / 2 > 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int v = 1; v <= n; v++)
        cout << ((used[v] - 1) ^ recolor);
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}