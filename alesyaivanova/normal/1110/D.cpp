#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 1000009;
int a[MAX_N];
int n, m;
int dp[MAX_N][3][3];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a[b]++;
    }
    dp[0][0][0] = a[0] / 3;
    if (a[0] >= 1 && a[1] >= 1 && a[2] >= 1)
        dp[0][0][1] = (a[0] - 1) / 3 + 1;
    if (a[0] >= 2 && a[1] >= 2 && a[2] >= 2)
        dp[0][0][2] = (a[0] - 2) / 3 + 2;
    for (int i = 0; i <= m; i++)
    {
        for (int e = 0; e < 3; e++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i] < e + j || a[i + 1] < e + j || a[i + 2] < j)
                    continue;
                for (int t = 0; t < 3; t++)
                {
                    if (a[i + 1] < e + j + t || a[i + 2] < j + t || a[i + 3] < t)
                        continue;
                    dp[i + 1][j][t] = max(dp[i + 1][j][t], dp[i][e][j] + t + (a[i + 1] - e - t - j) / 3);
                }
            }
        }
    }
    cout << dp[m][0][0];
}