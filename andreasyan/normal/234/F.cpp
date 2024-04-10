#include <bits/stdc++.h>
using namespace std;
const int N = 202, INF = 1000000009;

int n, g1, g2;
int h[N];
int p[N];

int dp[N][N * N][3];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> g1 >> g2;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + h[i];

    for (int i = 0; i <= n; ++i)
    {
        for (int gg1 = 0; gg1 <= g1; ++gg1)
        {
            for (int k = 1; k <= 2; ++k)
                dp[i][gg1][k] = INF;
        }
    }

    dp[0][g1][1] = 0;
    dp[0][g1][2] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int gg1 = 0; gg1 <= g1; ++gg1)
        {
            int gg2 = g2 - (p[i] - (g1 - gg1));

            if (gg1 >= h[i + 1])
            {
                //1 - i vra 1
                dp[i + 1][gg1 - h[i + 1]][1] = min(dp[i + 1][gg1 - h[i + 1]][1], dp[i][gg1][1]);
                //2 - i vra 1
                dp[i + 1][gg1 - h[i + 1]][1] = min(dp[i + 1][gg1 - h[i + 1]][1], dp[i][gg1][2] + min(h[i], h[i + 1]));
            }
            if (gg2 >= h[i + 1])
            {
                //2 - i vra 2
                dp[i + 1][gg1][2] = min(dp[i + 1][gg1][2], dp[i][gg1][2]);
                //1 - i vra 2
                dp[i + 1][gg1][2] = min(dp[i + 1][gg1][2], dp[i][gg1][1] + min(h[i], h[i + 1]));
            }
        }
    }

    int ans = INF;
    for (int gg1 = 0; gg1 <= g1; ++gg1)
        ans = min(ans, min(dp[n][gg1][1], dp[n][gg1][2]));

    if (ans == INF)
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}