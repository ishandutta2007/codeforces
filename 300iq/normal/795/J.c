#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int dp[n + 1][n + 1][n + 1];
    char s[n];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &s[i]);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (!dp[i][j][k])
                {
                    continue;
                }
                if (s[i] == 'Y' || s[i] == '?')
                {
                    dp[i + 1][max(j, k)][0] = 1;
                }
                if (s[i] == 'N' || s[i] == '?')
                {
                    dp[i + 1][j][k + 1] = 1;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[n][i][j] && max(i, j) == k)
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
}