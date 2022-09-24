#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> dp(n+1);
    for (int i=0;i<=n;i++)
    {
        dp[i].resize(n+1);
        for (int j=0;j<=n;j++)
        {
            dp[i][j] = -100000;
        }
    }
    dp[0][0] = 0;
    int sum = 0;
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        sum += a[i];
        sum %= h;
        for (int j=0;j<=i;j++)
        {
            int cursum = (sum+j)%h;
            int curans = dp[i][j];
            if (cursum>=l and cursum<=r) curans++;
            if (curans>ans) ans = curans;
            dp[i+1][j] = max(dp[i+1][j],curans);
            cursum = (sum+j+1)%h;
            curans = dp[i][j];
            if (cursum>=l and cursum<=r) curans++;
            if (curans>ans) ans = curans;
            dp[i+1][j+1] = max(dp[i+1][j+1],curans);
        }
    }
    cout << ans << endl;
    return 0;
}