#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
long long dp[maxm];
int n, x, y;
void solve() {
    cin >> n >> x >> y;
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + x;
        if(i % 2 == 0) {
            dp[i] = min(dp[i/2] + y, dp[i]);
        } else {
            dp[i] = min(dp[i/2] + y + x, dp[i]);
            dp[i] = min(dp[(i+1)/2] + y + x, dp[i]);
        }
    }
    cout << dp[n] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}