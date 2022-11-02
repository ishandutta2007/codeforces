#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
ll c[1011][1011];
ll dp[1010];
int a[1010];
void solve() {
    for(int i = 0; i < 1010; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] <= 0) continue;
        for(int j = i; j < n; j++) {
            int len = j - i;
            if(len < a[i]) continue;
            dp[i] = (dp[i] + c[len][a[i]] * dp[j+1]) % mod;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = (ans + dp[i]) % mod;
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}