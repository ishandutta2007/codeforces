#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> dp(n+1,vector<int>(4));
        vector<int> a(n+1);
        vector<bool> nope(n+1);
        bool cur_n = false;
        for(int i = 0; i < n; i ++) {
            char c;
            cin >> c;
            if(c == '*') {
                a[i] = 1;
            }
        }
        for(int i = 0; i < n; i ++) {
            char c;
            cin >> c;
            if(c == '*') {
                a[i] += 2;
            }
        }
        for(int i = 0; i <= n; i ++) {
            nope[i] = cur_n;
            cur_n |= (a[i]>0);
        }
        for(int i = 0; i <= n; i ++) {
            if(!nope[i]) {
                dp[i][0] = dp[i][1] = dp[i][2] = 0;
                dp[i][3] = 1;
                continue;
            }
            dp[i][0] = dp[i-1][a[i-1]];
            dp[i][1] = dp[i-1][a[i-1]|1]+1;
            dp[i][2] = dp[i-1][a[i-1]|2]+1;
            dp[i][3] = min(dp[i][2],dp[i][1]) + 1;
        }
        cout << dp[n][0] << "\n";
    }
    return 0;
}