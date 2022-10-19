#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;


void solve() {
    ll u, v;
    cin >> u >> v;
    vector<int> indsv, indsu;
    for (int i = 0; i < 30; i++) {
        if (v & (1LL << i)) {
            indsv.push_back(i);
        }
        if (u & (1LL << i)) {
            indsu.push_back(i);
        }
    }
    int n = indsv.size();
    int m = indsu.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (indsu[j - 1] > indsv[i - 1]) {

            } else if (indsu[j - 1] == indsv[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1]);
            }
        }
    }
    if (dp[n][m]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}