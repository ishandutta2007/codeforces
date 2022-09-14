#include <bits/stdc++.h>

using namespace std;
int MAXN = 120;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int r, s, p;
    double dp[MAXN][MAXN][MAXN];
    cin >> r >> s >> p;
    int l = r + s + p;
    for (int i = 0; i <= r; i++)
        for (int j = 0; j <= s; j++)
            for (int k = 0; k <= p; k++)
                dp[i][j][k] = 0;
    dp[r][s][p] = 1;

    for (int t = l; t > 0; t--)
    {
        for (int i = 0; i <= r; i++)
            for (int j = 0; j <= s; j++)
            {
                int k = t - i - j;
                if (0 <= k && k <= p)
                {
                    int v = i * j + j * k + k * i;
                    if (i > 0 && j > 0)
                        dp[i][j - 1][k] += dp[i][j][k] * i * j / v;
                    if (j > 0 && k > 0)
                        dp[i][j][k - 1] += dp[i][j][k] * j * k / v;
                    if (k > 0 && i > 0)
                        dp[i - 1][j][k] += dp[i][j][k] * k * i / v;
                }
            }
    }
    double ansr = 0, anss = 0, ansp = 0;
    for (int i = 1; i <= r; i++)
        ansr += dp[i][0][0];
    for (int i = 1; i <= s; i++)
        anss += dp[0][i][0];
    for (int i = 1; i <= p; i++)
        ansp += dp[0][0][i];
    printf("%.12lf %.12lf %.12lf\n", ansr, anss, ansp);
    return 0;
}