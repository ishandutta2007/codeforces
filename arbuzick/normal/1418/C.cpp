#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<vector<int>> dp(n+1, vector<int>(2));
        dp[0][0] = n+1;
        if(n == 1){
            cout << a[0] << '\n';
            continue;
        }
        for(int i = 0; i < n; ++i){
            dp[i+1][0] = dp[i][1]+a[i];
            if(i > 0)
                dp[i+1][0] = min(dp[i+1][0], dp[i-1][1]+a[i]+a[i-1]);
            dp[i+1][1] = dp[i][0];
            if(i > 0)
                dp[i+1][1] = min(dp[i+1][1], dp[i-1][0]);
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
    return 0;
}