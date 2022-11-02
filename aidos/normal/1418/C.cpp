#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
int n, m;
int a[maxn];
int dp[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = n + 1;  i <= n + 10; i++) dp[i] = 0;
    for(int j = n; j >= 1; j--) {
        dp[j] = 1e9;
        dp[j] = min(dp[j+2] + a[j], dp[j]);
        dp[j] = min(dp[j+3] + a[j], dp[j]);
        dp[j] = min(dp[j+3] + a[j] + a[j+1], dp[j]);
        dp[j] = min(dp[j+4] + a[j] + a[j+1], dp[j]);
    }
    cout << dp[1] << "\n";

}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}