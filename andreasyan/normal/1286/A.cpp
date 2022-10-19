#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 102, INF = 1000000009;

int n;
int a[N];

int dp[N][N][N][2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= (n / 2); ++j)
        {
            for (int k = 0; k <= (n / 2) + (n % 2); ++k)
            {
                for (int z = 0; z < 2; ++z)
                    dp[i][j][k][z] = INF;
            }
        }
    }
    if (a[1] == 0)
    {
        dp[1][(n / 2) - 1][(n / 2) + (n % 2)][0] = 0;
        dp[1][(n / 2)][(n / 2) + (n % 2) - 1][1] = 0;
    }
    else
    {
        if (a[1] % 2 == 0)
            dp[1][(n / 2) - 1][(n / 2) + (n % 2)][0] = 0;
        else
            dp[1][(n / 2)][(n / 2) + (n % 2) - 1][1] = 0;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= (n / 2); ++j)
        {
            for (int k = 0; k <= (n / 2) + (n % 2); ++k)
            {
                for (int z = 0; z < 2; ++z)
                {
                    if (a[i + 1] == 0)
                    {
                        {
                            if ((a[i + 1] % 2) == z)
                            {
                                if (j - 1 >= 0)
                                    dp[i + 1][j - 1][k][(a[i + 1] % 2)] = min(dp[i + 1][j - 1][k][(a[i + 1] % 2)], dp[i][j][k][z]);
                            }
                            else
                            {
                                if (j - 1 >= 0)
                                    dp[i + 1][j - 1][k][(a[i + 1] % 2)] = min(dp[i + 1][j - 1][k][(a[i + 1] % 2)], dp[i][j][k][z] + 1);
                            }
                        }
                        a[i + 1] = 1;
                        {
                            if ((a[i + 1] % 2) == z)
                            {
                                if (k - 1 >= 0)
                                    dp[i + 1][j][k - 1][(a[i + 1] % 2)] = min(dp[i + 1][j][k - 1][(a[i + 1] % 2)], dp[i][j][k][z]);
                            }
                            else
                            {
                                if (k - 1 >= 0)
                                    dp[i + 1][j][k - 1][(a[i + 1] % 2)] = min(dp[i + 1][j][k - 1][(a[i + 1] % 2)], dp[i][j][k][z] + 1);
                            }
                        }
                        a[i + 1] = 0;
                    }
                    else
                    {
                        if (a[i + 1] % 2 == 0)
                        {
                            if ((a[i + 1] % 2) == z)
                            {
                                if (j - 1 >= 0)
                                    dp[i + 1][j - 1][k][(a[i + 1] % 2)] = min(dp[i + 1][j - 1][k][(a[i + 1] % 2)], dp[i][j][k][z]);
                            }
                            else
                            {
                                if (j - 1 >= 0)
                                    dp[i + 1][j - 1][k][(a[i + 1] % 2)] = min(dp[i + 1][j - 1][k][(a[i + 1] % 2)], dp[i][j][k][z] + 1);
                            }
                        }
                        else
                        {
                            if ((a[i + 1] % 2) == z)
                            {
                                if (k - 1 >= 0)
                                    dp[i + 1][j][k - 1][(a[i + 1] % 2)] = min(dp[i + 1][j][k - 1][(a[i + 1] % 2)], dp[i][j][k][z]);
                            }
                            else
                            {
                                if (k - 1 >= 0)
                                    dp[i + 1][j][k - 1][(a[i + 1] % 2)] = min(dp[i + 1][j][k - 1][(a[i + 1] % 2)], dp[i][j][k][z] + 1);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", min(dp[n][0][0][0], dp[n][0][0][1]));
    return 0;
}