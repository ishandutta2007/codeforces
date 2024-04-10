#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005, M = 255;

int n, qq;
char a[N];
int u[N][26];

int m[4];
int dp[M][M][M];
char b[4][M];

int main()
{
    scanf("%d%d", &n, &qq);
    scanf(" %s", a);
    for (int j = 0; j < 26; ++j)
        u[n][j] = u[n + 1][j] = n;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
        {
            u[i][j] = u[i + 1][j];
        }
        u[i][a[i] - 'a'] = i;
    }
    while (qq--)
    {
        char ty;
        int uu;
        scanf(" %c%d", &ty, &uu);
        if (ty == '-')
        {
            --m[uu];
        }
        else
        {
            char x;
            scanf(" %c", &x);
            b[uu][m[uu]++] = x;
            if (uu == 1)
            {
                for (int i1 = m[1]; i1 <= m[1]; ++i1)
                {
                    for (int i2 = 0; i2 <= m[2]; ++i2)
                    {
                        for (int i3 = 0; i3 <= m[3]; ++i3)
                        {
                            dp[i1][i2][i3] = n + 1;
                            if (i1 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1 - 1][i2][i3]][b[1][i1 - 1] - 'a'] + 1);
                            if (i2 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1][i2 - 1][i3]][b[2][i2 - 1] - 'a'] + 1);
                            if (i3 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1][i2][i3 - 1]][b[3][i3 - 1] - 'a'] + 1);
                        }
                    }
                }
            }
            else if (uu == 2)
            {
                for (int i2 = m[2]; i2 <= m[2]; ++i2)
                {
                    for (int i1 = 0; i1 <= m[1]; ++i1)
                    {
                        for (int i3 = 0; i3 <= m[3]; ++i3)
                        {
                            dp[i1][i2][i3] = n + 1;
                            if (i1 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1 - 1][i2][i3]][b[1][i1 - 1] - 'a'] + 1);
                            if (i2 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1][i2 - 1][i3]][b[2][i2 - 1] - 'a'] + 1);
                            if (i3 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1][i2][i3 - 1]][b[3][i3 - 1] - 'a'] + 1);
                        }
                    }
                }
            }
            else
            {
                for (int i3 = m[3]; i3 <= m[3]; ++i3)
                {
                    for (int i2 = 0; i2 <= m[2]; ++i2)
                    {
                        for (int i1 = 0; i1 <= m[1]; ++i1)
                        {
                            dp[i1][i2][i3] = n + 1;
                            if (i1 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1 - 1][i2][i3]][b[1][i1 - 1] - 'a'] + 1);
                            if (i2 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1][i2 - 1][i3]][b[2][i2 - 1] - 'a'] + 1);
                            if (i3 > 0)
                                dp[i1][i2][i3] = min(dp[i1][i2][i3], u[dp[i1][i2][i3 - 1]][b[3][i3 - 1] - 'a'] + 1);
                        }
                    }
                }
            }
        }
        if (dp[m[1]][m[2]][m[3]] <= n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}