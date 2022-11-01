#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[12], b[12], c[12], d[12];
int dp[1001][12];
int ans;

int main()
{
    cin >> n >> m >> c[1] >> d[1];
    for(int i = 2; i <= m + 1; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i = 0; i <= n; i++)
        for(int j = 1; j <= m + 1; j++)
            for(int k = 0; k <= 1000; k++)
            {
                if(k * b[j] > a[j]) break;
                if(k * c[j] > i) break;
                dp[i][j] = max(dp[i][j], dp[i - k * c[j]][j - 1] + k * d[j]);
                ans = max(ans, dp[i][j]);
            }
    cout << ans;
}