#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
const int M = 1000000007;

int n, m;
char a[N][N];
int s[N][N][2];
int dp[N][N][2];
int ds[N][N][2];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            s[i][j][0] = (s[i][j + 1][0]);
            s[i][j][1] = (s[i + 1][j][1]);
            if (a[i][j] == 'R')
            {
                s[i][j][0]++;
                s[i][j][1]++;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (i == n - 1)
            {
                if (s[i][j][0] == 0)
                {
                    dp[i][j][0] = dp[i][j][1] = 1;
                }
                ds[i][j][0] = (ds[i][j + 1][0] + dp[i][j][1]) % M;
                ds[i][j][1] = (ds[i + 1][j][1] + dp[i][j][0]) % M;
                continue;
            }
            if (j == m - 1)
            {
                if (s[i][j][1] == 0)
                {
                    dp[i][j][0] = dp[i][j][1] = 1;
                }
                ds[i][j][0] = (ds[i][j + 1][0] + dp[i][j][1]) % M;
                ds[i][j][1] = (ds[i + 1][j][1] + dp[i][j][0]) % M;
                continue;
            }
            // 0 == dzaxic
            if (a[i][j] == '.')
            {
                int qr = s[i][j + 1][0];
                if (j + 1 <= m - qr - 1)
                    dp[i][j][0] = (dp[i][j][0] + (ds[i + 1][j + 1][0] - ds[i + 1][m - qr][0] + M) % M) % M;
                int qn = s[i + 1][j][1];
                if (i + 1 <= n - qn - 1)
                    dp[i][j][0] = (dp[i][j][0] + (ds[i + 1][j + 1][1] - ds[n - qn][j + 1][1] + M) % M) % M;
            }
            else
            {
                int qr = s[i][j + 1][0] + 1;
                if (qr != m - j && j + 1 <= m - qr - 1)
                    dp[i][j][0] = (dp[i][j][0] + (ds[i + 1][j + 1][0] - ds[i + 1][m - qr][0] + M) % M) % M;
                int qn = s[i + 1][j][1];
                if (qr != m - j && i + 1 <= n - qn - 1)
                    dp[i][j][0] = (dp[i][j][0] + (ds[i + 1][j + 1][1] - ds[n - qn][j + 1][1] + M) % M) % M;
            }
            // 1 == verevic
            if (a[i][j] == '.')
            {
                int qr = s[i][j + 1][0];
                if (j + 1 <= m - qr - 1)
                    dp[i][j][1] = (dp[i][j][1] + (ds[i + 1][j + 1][0] - ds[i + 1][m - qr][0] + M) % M) % M;
                int qn = s[i + 1][j][1];
                if (i + 1 <= n - qn - 1)
                    dp[i][j][1] = (dp[i][j][1] + (ds[i + 1][j + 1][1] - ds[n - qn][j + 1][1] + M) % M) % M;
            }
            else
            {
                int qr = s[i][j + 1][0];
                int qn = s[i + 1][j][1] + 1;
                if (qn != n - i && j + 1 <= m - qr - 1)
                    dp[i][j][1] = (dp[i][j][1] + (ds[i + 1][j + 1][0] - ds[i + 1][m - qr][0] + M) % M) % M;
                if (qn != n - i && i + 1 <= n - qn - 1)
                    dp[i][j][1] = (dp[i][j][1] + (ds[i + 1][j + 1][1] - ds[n - qn][j + 1][1] + M) % M) % M;
            }
            ds[i][j][0] = (ds[i][j + 1][0] + dp[i][j][1]) % M;
            ds[i][j][1] = (ds[i + 1][j][1] + dp[i][j][0]) % M;
        }
    }
    cout << dp[0][0][0] << endl;
    return 0;
}