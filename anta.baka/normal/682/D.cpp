#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    string s, t;
    cin >> n >> m >> k >> s >> t;
    int p[n][m], dp[n][m][k+1];
    for(int i=0; i<n; i++)
        p[i][0] = (s[i] == t[0]);
    for(int i=0; i<m; i++)
        p[0][i] = (s[0] == t[i]);
    for(int i=1; i<n; i++)
        for(int j=1; j<m; j++)
            p[i][j] = (s[i] == t[j] ? p[i-1][j-1] + 1 : 0);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dp[i][j][0] = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int w=1; w<=k; w++)
                dp[i][j][w] = max(max((!i ? 0 : dp[i-1][j][w]), (!j ? 0 : dp[i][j-1][w])), (p[i][j] ? (i>=p[i][j] && j>=p[i][j] ? dp[i-p[i][j]][j-p[i][j]][w-1] : 0) + p[i][j] : 0));
    int ans = 0;
    for(int w=1; w<=k; w++)
        ans = max(ans, dp[n-1][m-1][w]);
    cout << ans;
    return 0;
}