#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
int r, g;
long long dp[maxn];
void solve() {
    cin >> r >> g;
    int n = r + g;
    int h = 1;
    while(h * (h + 1)/2 <= n) h++;
    h--;
    dp[0] = 1;
    for(int d = 1; d <= h; d++) {
        for(int i = g; i >= d; i--) {
            dp[i] += dp[i-d];
            if(dp[i] >= mod) dp[i] -= mod;
        }
    }
    long long ans = 0;
    for(int i = 0; i <= g; i++) {
        if(h * (h + 1)/2 - i <= r) {
            ans = (ans + dp[i]) % mod;
        }
    }
    cout << ans << "\n";
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