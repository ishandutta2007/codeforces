#include <bits/stdc++.h>

using namespace std;
#define int long long
int mod = 998244353;
signed main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector <int> dp(m + 1);
    for (int i = 0; i < m; ++i) {
        if (a[0] == b[i]) {
            dp[i] = 2;
        }
    }
    dp[m] = 2;
    int ans = 0;
    if (m == 1) ans = dp[0];
    for (int i = 1; i < n; ++i) {
        vector <int> dp1(m + 1);
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                dp1[j] = dp[j + 1];
            }
            if (j + i < m && a[i] == b[j + i]) {
                dp1[j] += dp[j];
            }
            else if (j + i >= m) {
                dp1[j] += dp[j];
            }
            dp1[j] %= mod;
        }
        dp1[m] = (dp[m] * 2) % mod;
        dp = dp1;
        if (i + 1 >= m) ans += dp[0];
        ans %= mod;
    }
    cout << ans;
}