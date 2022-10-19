#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>

using namespace std;
vector <vector <int>> g;
vector <int> ans;

void dfs(int v, int p, int gl) {
    for (int i : g[v]) {
        if (i == p) continue;
        dfs(i, v, gl ^ 1);
    }
    if (v == 0) ans[v] = (int)g[v].size();
    else if (gl == 0) ans[v] = (int)g[v].size();
    else ans[v] = -(int)g[v].size();
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.assign(n, {});
        ans.assign(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y; --x; --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(0, -1, 0);
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
}