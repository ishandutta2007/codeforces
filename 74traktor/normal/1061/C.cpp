#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[100004];
int dp[100004];
int mod = 1e9 + 7;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        int p = (int)sqrt(a[i]);
        for (int j = min(p, i); j >= 1; --j){
            if (a[i] % j == 0){
                if (j * j != a[i] && a[i] / j <= i)
                    dp[a[i] / j] = (dp[a[i] / j] + dp[a[i] / j - 1]) % mod;
                if (j == 1)
                    dp[j]++;
                else
                    dp[j] += dp[j - 1];
                dp[j] = dp[j] % mod;
            }
        }
    }
    long long ans = 0;
   // cout << dp[1] << " " << dp[2] << endl;
    for (auto key : dp)
        ans = (ans + key) % mod;
    cout << ans << endl;
    return 0;
}