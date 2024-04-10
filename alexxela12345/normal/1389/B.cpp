#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int INF = 1e18;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<vector<int>> dp(n, vector<int> (z + 1, -INF));
        dp[0][0] = arr[0];
        for (int j = 0; j <= z; j++) {
            for (int i = 0; i < n; i++) {
                if (i != n - 1) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1]);
                }
                if (i != 0 && j != z) {
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + arr[i - 1] + arr[i]);
                }
            }
        }
        int best_ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= z; j++) {
                if (i + 2 * j == k) {
                    best_ans = max(best_ans, dp[i][j]);
                } else if (i + 2 * j == k  - 1 && i != 0 && j != z) {
                    best_ans = max(best_ans, dp[i][j] + arr[i - 1]);
                }
            }
        }
        cout << best_ans << endl;
    }
}