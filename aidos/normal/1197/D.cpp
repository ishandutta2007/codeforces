#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m, k;
ll dp[maxn];
ll sum[maxn];
int a[maxn];
void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= m && j <= i; j++) {
            dp[i] = max(dp[i-j] + sum[i] - sum[i-j] - k, dp[i]);
        }
        ans = max(ans,  dp[i]);
    }
    cout << ans << "\n";
}


int main() {
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