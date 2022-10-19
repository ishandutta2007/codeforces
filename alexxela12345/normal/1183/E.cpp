#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> dp(n + 1, vector<int> (26));
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        for (int j = n; j > 1; j--) {
            int dpp = 0;
            for (int k = 0; k < 26; k++) {
                dpp += dp[j - 1][k];
            }
            dp[j][x] = dpp;
        }
        dp[1][x] = 1;
    }
    vector<int> dp2(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int k = 0; k < 26; k++) {
            dp2[i] += dp[i][k];
        }
    }
    dp2[0] = 1;
    int cur_ans = 0;
    int cur_len = 0;
    for (int i = n; i >= 0; i--) {
        if (cur_len + dp2[i] >= k) {
            cur_ans += (k - cur_len) * (n - i);
            cur_len = k;
            break;
        }
        cur_len += dp2[i];
        cur_ans += (dp2[i]) * (n - i);
    }
    if (cur_len < k) {
        cout << -1 << endl;
    } else {
        cout << cur_ans << endl;
    }
}