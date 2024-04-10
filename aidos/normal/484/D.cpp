#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
typedef long long ll;
int n, q;
int a[maxn];
ll dp[maxn];
ll b[maxn];
ll c[maxn];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    vector<int> x, y;
    b[0] = -1e18;
    c[0] = -1e18;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        dp[i] = max(b[i-1] + a[i], dp[i]);
        dp[i] = max(c[i-1] - a[i], dp[i]);
        c[i] = max(c[i-1], dp[i-1] + a[i]);
        b[i] = max(b[i-1], dp[i-1] - a[i]);
    }
    cout << dp[n] << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}