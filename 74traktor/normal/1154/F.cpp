#include <bits/stdc++.h>

using namespace std;

int a[200005];
int best[200005];
int pref[200005];
int dp[2005];
int inf = 1e9;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    for (int i = 1; i <= m; ++i){
        cin >> x >> y;
        best[x] = max(best[x], y);
    }
    for (int i = 1; i <= k; ++i){
        dp[i] = inf;
        for (int j = 0; j <= i - 1; ++j){
            dp[i] = min(dp[i], dp[j] + pref[i] - pref[j + best[i - j]]);
        }
    }
    cout << dp[k] << '\n';
    return 0;
}