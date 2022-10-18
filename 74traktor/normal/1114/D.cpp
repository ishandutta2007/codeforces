#include <bits/stdc++.h>

using namespace std;

int g[5005];
int a[5005];
int b[5005];
int dp[5005][5005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> g[i];
    }
    int uk = 1;
    for (int i = 1; i <= n; ++i){
        if (g[i] != g[i - 1]){
            a[uk] = g[i];
            uk++;
        }
    }
    for (int i = uk - 1; i >= 1; --i) b[i] = a[uk - i];
    /*for (int i = 1; i <= uk - 1; ++i) cout << a[i] << " ";
    cout << endl;
    for (int i = 1; i <= uk - 1; ++i) cout << b[i] << " ";
    cout << endl;
    */for (int i = 1; i <= uk - 1; ++i){
        for (int j = 1; j <= uk - 1; ++j){
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans = 1e9;
    uk--;
    for (int i = 1; i <= uk; ++i){
        //cout << uk << " " << dp[i - 1][uk - i] << " " << i - 1 << " " << uk - i << endl;
        ans = min(ans, uk - 1 - dp[i - 1][uk - i]);
    }
    cout << ans << '\n';
    return 0;
}