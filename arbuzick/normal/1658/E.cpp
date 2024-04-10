#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> pos(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            v[i][j]--;
            pos[v[i][j]] = i * n + j;
        }
    }
    vector<vector<int>> ans(n, vector<int>(n));
    int mn_sum = n * 10, mx_sum = -n * 10, mn_sub = n * 10, mx_sub = -n * 10;
    for (int i = n * n - 1; i >= 0; --i) {
        int x = pos[i] / n, y = pos[i] % n;
        if (x + y - mn_sum <= k && mx_sum - x - y <= k && x - y - mn_sub <= k && mx_sub - x + y <= k) {
            ans[x][y] = 1;
            mn_sum = min(mn_sum, x + y);
            mx_sum = max(mx_sum, x + y);
            mn_sub = min(mn_sub, x - y);
            mx_sub = max(mx_sub, x - y);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (ans[i][j] ? 'M' : 'G');
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}