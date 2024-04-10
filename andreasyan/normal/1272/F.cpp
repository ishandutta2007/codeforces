#include <bits/stdc++.h>
using namespace std;
const int N = 205, INF = 1000000009;

int n, m;
char a[N], b[N];

int dp[N][N][N + N + N + N];
char p[N][N][N + N + N + N];

int t;
char yans[N * N];
int main()
{
    scanf(" %s %s", a, b);
    n = strlen(a);
    m = strlen(b);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N + N + N + N; ++k)
                dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            for (int k = 0; k < N + N + N + N - 1; ++k)
            {
                if (dp[i][j][k] == INF)
                    continue;
                // (
                if (a[i] == '(' && b[j] == '(')
                {
                    if (dp[i][j][k] + 1 < dp[i + 1][j + 1][k + 1])
                    {
                        dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
                        p[i + 1][j + 1][k + 1] = '(';
                    }
                    if (dp[i][j][k] + 1 < dp[i + 1][j][k + 1])
                    {
                        dp[i + 1][j][k + 1] = dp[i][j][k] + 1;
                        p[i + 1][j][k + 1] = '(';
                    }
                    if (dp[i][j][k] + 1 < dp[i][j + 1][k + 1])
                    {
                        dp[i][j + 1][k + 1] = dp[i][j][k] + 1;
                        p[i][j + 1][k + 1] = '(';
                    }
                    if (dp[i][j][k] + 1 < dp[i][j][k + 1])
                    {
                        dp[i][j][k + 1] = dp[i][j][k] + 1;
                        p[i][j][k + 1] = '(';
                    }
                }
                else if (a[i] == '(')
                {
                    if (dp[i][j][k] + 1 < dp[i + 1][j][k + 1])
                    {
                        dp[i + 1][j][k + 1] = dp[i][j][k] + 1;
                        p[i + 1][j][k + 1] = '(';
                    }
                    if (dp[i][j][k] + 1 < dp[i][j][k + 1])
                    {
                        dp[i][j][k + 1] = dp[i][j][k] + 1;
                        p[i][j][k + 1] = '(';
                    }
                }
                else if (b[j] == '(')
                {
                    if (dp[i][j][k] + 1 < dp[i][j + 1][k + 1])
                    {
                        dp[i][j + 1][k + 1] = dp[i][j][k] + 1;
                        p[i][j + 1][k + 1] = '(';
                    }
                    if (dp[i][j][k] + 1 < dp[i][j][k + 1])
                    {
                        dp[i][j][k + 1] = dp[i][j][k] + 1;
                        p[i][j][k + 1] = '(';
                    }
                }
                else
                {
                    if (dp[i][j][k] + 1 < dp[i][j][k + 1])
                    {
                        dp[i][j][k + 1] = dp[i][j][k] + 1;
                        p[i][j][k + 1] = '(';
                    }
                }
                // )
                if (k == 0)
                    continue;
                if (a[i] == ')' && b[j] == ')')
                {
                    if (dp[i][j][k] + 1 < dp[i + 1][j + 1][k - 1])
                    {
                        dp[i + 1][j + 1][k - 1] = dp[i][j][k] + 1;
                        p[i + 1][j + 1][k - 1] = ')';
                    }
                    if (dp[i][j][k] + 1 < dp[i + 1][j][k - 1])
                    {
                        dp[i + 1][j][k - 1] = dp[i][j][k] + 1;
                        p[i + 1][j][k - 1] = ')';
                    }
                    if (dp[i][j][k] + 1 < dp[i][j + 1][k - 1])
                    {
                        dp[i][j + 1][k - 1] = dp[i][j][k] + 1;
                        p[i][j + 1][k - 1] = ')';
                    }
                }
                else if (a[i] == ')')
                {
                    if (dp[i][j][k] + 1 < dp[i + 1][j][k - 1])
                    {
                        dp[i + 1][j][k - 1] = dp[i][j][k] + 1;
                        p[i + 1][j][k - 1] = ')';
                    }
                }
                else if (b[j] == ')')
                {
                    if (dp[i][j][k] + 1 < dp[i][j + 1][k - 1])
                    {
                        dp[i][j + 1][k - 1] = dp[i][j][k] + 1;
                        p[i][j + 1][k - 1] = ')';
                    }
                }
            }
        }
    }
    int ans = INF;
    int ansk;
    for (int k = 0; k < N + N + N + N; ++k)
    {
        if (dp[n][m][k] + k < ans)
        {
            ans = dp[n][m][k] + k;
            ansk = k;
        }
    }
    /*if (ans == INF)
    {
        printf("WA\n");
        return 0;
    }*/
    //printf("%d\n", ans);
    t = ans;
    for (int i = 0; i < ansk; ++i)
        yans[--t] = ')';
    int i = n;
    int j = m;
    int k = ansk;
    while (1)
    {
        if (i == 0 && j == 0 && k == 0)
            break;
        yans[--t] = p[i][j][k];
        int ii = i, jj = j, kk;
        if (p[i][j][k] == '(')
        {
            kk = k - 1;
            if (i - 1 >= 0 && a[i - 1] == '(')
                --ii;
            if (j - 1 >= 0 && b[j - 1] == '(')
                --jj;
        }
        else
        {
            kk = k + 1;
            if (i - 1 >= 0 && a[i - 1] == p[i][j][k])
                --ii;
            if (j - 1 >= 0 && b[j - 1] == p[i][j][k])
                --jj;
        }
        i = ii;
        j = jj;
        k = kk;
    }
    for (int i = 0; i < ans; ++i)
    {
        if (yans[i] == 0)
            yans[i] = ')';
    }
    printf("%s\n", yans);
    return 0;
}
/*
((())()()()()
))(((
*/