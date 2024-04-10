#include <bits/stdc++.h>

using namespace std;

int a[300005];
int pref[300005];
int dp[2000005][3];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        pref[i] = (pref[i - 1]^a[i]);
        //cout << pref[i] << endl;
        ans += dp[pref[i]][i % 2];
        dp[pref[i]][i % 2]++;
    }
    cout << ans << '\n';
    return 0;
}