#include <bits/stdc++.h>
using namespace std;
const int N = 102, M = 51;

int n;
char a[N];
int m;

bool dp[N][M][N * 2][2];
int main()
{
    cin >> a;
    cin >> m;
    n = strlen(a);
    dp[0][0][N][1] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k <= m; ++k)
        {
            for (int x = 0; x < 2 * N; ++x)
            {
                for (int u = 0; u < 2; ++u)
                {
                    if (i == 1 && k == 0 && x == N + 1 && u == 1)
                        cout << "";
                    if (!dp[i][k][x][u])
                        continue;
                    for (int kk = 0; kk <= m - k; ++kk)
                    {
                        if ((a[i] == 'F' && kk % 2 == 0) || (a[i] == 'T' && kk % 2 == 1))
                        {
                            if (u == 0)
                                dp[i + 1][k + kk][x - 1][u] = true;
                            else
                                dp[i + 1][k + kk][x + 1][u] = true;
                        }
                        else
                        {
                            dp[i + 1][k + kk][x][u ^ 1] = true;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < 2 * N; ++x)
    {
        for (int u = 0; u <= 1; ++u)
        {
            if (dp[n][m][x][u])
                ans = max(ans, abs(x - N));
        }
    }
    cout << ans << endl;
    return 0;
}