#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> c(n, vector<long long>(m)), pr(n, vector<long long>(m + 1));
    vector<long long> sum(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            pr[i][j + 1] = pr[i][j] + c[i][j];
            sum[i] += pr[i][j + 1];
        }
    }
    int pos_mn = 0;
    for (int i = 0; i < n; ++i) {
        if (sum[i] < sum[pos_mn]) {
            pos_mn = i;
        }
    }
    cout << pos_mn + 1 << ' ' << sum[(pos_mn + 1) % n] - sum[pos_mn] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}