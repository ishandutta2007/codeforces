#include <bits/stdc++.h>

using namespace std;
const int MAXN = 50;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    int p[MAXN];
    double dp[MAXN][MAXN][20];
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            dp[i][j][0] = 1;
    for (int l = 1; l <= k; l++)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                double q = 0;
                for (int t = 0; t < n - j + i; t++)
                {
                    int l1 = min (t, i);
                    int r1 = max(t + j - i, j);
                    q += (double) min (l1 + 1, n - r1) * (1 - dp[t][t + j - i][l - 1]);
                }
                for (int t = 0; t < j; t++)
                {
                    int l1 = min(t, i);
                    int r1 = max(t, i);
                    q += (double) min(l1 + 1, j - r1) * dp[t][j][l - 1];
                }
                for (int t = i + 1; t < n; t++)
                {
                    int l1 = min(t, j);
                    int r1 = max(t, j);
                    q += (double) min(l1 - i, n - r1) * dp[i][t][l - 1];
                }
                q += (double) (i * (i + 1) / 2 + (j - i - 1) * (j - i) / 2 + (n - j - 1) * (n - j) / 2) * dp[i][j][l - 1];
                dp[i][j][l] = (double) q / (n * (n + 1) / 2);
            }
    double ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n ; j++)
            if (p[i] > p[j])
                ans += (double)dp[i][j][k];
            else
                ans += (double)1 - dp[i][j][k];
    printf("%.15lf\n", ans);
    return 0;
}