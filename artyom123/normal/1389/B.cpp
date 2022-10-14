#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define fi first
#define se second
#define ll long long

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<vector<int>> dp(k + 1, vector<int>(z + 1, -1));
        dp[0][0] = a[0];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= z && j <= i; j++) {
                if (dp[i][j] == -1) continue;
                int pos = i - 2 * j;
                if (pos != 0 && j < z) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[pos - 1]);
                if (pos < n - 1) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[pos + 1]);
            }
        }
        int ans = 0;
        for (auto &c : dp[k]) ans = max(ans, c);
        cout << ans << "\n";
    }
    return 0;
}