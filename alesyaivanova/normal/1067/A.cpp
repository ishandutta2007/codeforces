#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int a[MAX_N];
int n;
int dp[2][210][2];
int mod = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[0] != -1)
        dp[0][a[0]][0] = 1;
    else
    {
        for (int i = 1; i <= 200; i++)
            dp[0][i][0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int e = i % 2;
        for (int u = 1; u <= 200; u++)
        {
            dp[e][u][0] = 0;
            dp[e][u][1] = 0;
        }
        if (a[i] != -1)
        {
            for (int u = 1; u < a[i]; u++)
            {
                dp[e][a[i]][0] += dp[1 - e][u][0] + dp[1 - e][u][1];
                while (dp[e][a[i]][0] >= mod)
                    dp[e][a[i]][0] -= mod;
            }
            dp[e][a[i]][1] += dp[1 - e][a[i]][0] + dp[1 - e][a[i]][1];
            while (dp[e][a[i]][1] >= mod)
                dp[e][a[i]][1] -= mod;
            for (int u = a[i] + 1; u <= 200; u++)
            {
                dp[e][a[i]][1] += dp[1 - e][u][1];
                while (dp[e][a[i]][1] >= mod)
                    dp[e][a[i]][1] -= mod;
            }
        }
        else
        {
            for (int s = 2; s <= 200; s++)
            {
                dp[e][s][0] += dp[e][s - 1][0];
                dp[e][s][0] += dp[1 - e][s - 1][0] + dp[1 - e][s - 1][1];
                while (dp[e][s][0] >= mod)
                    dp[e][s][0] -= mod;
            }
            for (int s = 199; s >= 1; s--)
            {
                dp[e][s][1] += dp[e][s + 1][1];
                dp[e][s][1] += dp[1 - e][s + 1][1];
                while (dp[e][s][1] >= mod)
                    dp[e][s][1] -= mod;
            }
            for (int s = 1; s <= 200; s++)
            {
                dp[e][s][1] += dp[1 - e][s][0] + dp[1 - e][s][1];
                while (dp[e][s][1] >= mod)
                    dp[e][s][1] -= mod;
            }
        }
        /*for (int u = 1; u <= 200; u++)
            cout << dp[e][u][0] << " ";
        cout << endl;
        for (int u = 1; u <= 200; u++)
            cout << dp[e][u][1] << " ";
        cout << endl;*/
    }
    int e = (n - 1) % 2;
    if (a[n - 1] != -1)
        cout << dp[e][a[n - 1]][1];
    else
    {
        int ans = 0;
        for (int s = 1; s <= 200; s++)
        {
            ans += dp[e][s][1];
            ans %= mod;
        }
        cout << ans;
    }
}