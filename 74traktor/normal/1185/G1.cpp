#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[16][60000];
int mod = 1e9 + 7;
int a[16][2];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, ans = 0;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1];
    for (int i = 1; i <= n; ++i) dp[i][(1<<(i - 1))] = 1;
    for (int mask = 0; mask < (1<<n); ++mask){
        int sum = 0;
        for (int u = 1; u <= n; ++u){
            if ((mask&(1<<(u - 1))) == 0) continue;
            sum += a[u][0];
        }
        for (int u = 1; u <= n; ++u){
            if ((mask&(1<<(u - 1))) == 0) continue;
            int to = (mask^(1<<(u - 1)));
            for (int v = 1; v <= n; ++v){
                if (a[v][1] != a[u][1]) dp[u][mask] = (dp[u][mask] + dp[v][to]) % mod;
            }
            if (sum == t) ans = (ans + dp[u][mask]) % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}