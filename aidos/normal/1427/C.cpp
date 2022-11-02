#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 3e5 + 100;
const int mod = (int)998244353 ;
int n, r;
int t[maxn];
int x[maxn];
int y[maxn];
int pref[maxn];
int dp[maxn];
void solve() {
    cin >> r >> n;
    x[0] = 1, y[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = -mod;
        for(int j = i-1; j >= 0; j--) {
            if(i - j >= 2 * r) {
                dp[i] = max(dp[i], pref[j] + 1);
                break;
            } else if(t[j] + abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        pref[i] = max(dp[i], pref[i-1]);
    }
    cout<<pref[n] << "\n";
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