#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, len = 2 * 1000000 + 1;
    cin >> t;
    vector <int> dp(len);
    dp[3] = 4;
    for (int i = 4; i < len; ++i) {
        if ((i - 4) % 3 == 2) {
            dp[i] = (dp[i - 2] + dp[i - 3] * 4 + 4 * dp[i - 4] + 4) % mod;
        }
        else {
            dp[i] = (dp[i - 1] + dp[i - 2] * 2) % mod;
        }
    }
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}