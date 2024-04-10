#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
const int MOD = 998244353;

int dp[N][N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    int n = s.size() - 1;
    int m = t.size() - 1;
    {
        int lst = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0][0] = i - lst;
            if (i != n && s[i] == s[i + 1]) lst = i;  
        }
    }
    {
        int lst = 0;
        for (int i = 1; i <= m; i++) {
            dp[0][i][1] = i - lst;
            if (i != m && t[i] == t[i + 1]) lst = i;  
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // dp[i][j][0]
            if (s[i] != s[i - 1]) dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0]) % MOD;
            if (s[i] != t[j]) dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][1]) % MOD;
            if (i != 1 && s[i] != t[j]) dp[i][j][0] = (dp[i][j][0] + dp[0][j][1]) % MOD;
            // dp[i][j][1]
            if (t[j] != t[j - 1]) dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % MOD;
            if (t[j] != s[i]) dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][0]) % MOD;
            if (j != 1 && t[j] != s[i]) dp[i][j][1] = (dp[i][j][1] + dp[i][0][0]) % MOD;
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << '(' << dp[i][j][0] << ',' << dp[i][j][1] << ") ";
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 2; k++) {
                ans = (ans + dp[i][j][k]) % MOD;
            }
        }
    }

    cout << ans << '\n';
    

    return 0;
}