#include <bits/stdc++.h>
using namespace std;
const int N = 102, M = 1000006;

int n;
char a[N][N];

int d[N][N];

int m;
int b[M];

int dp[M];
int p[M];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf(" %c", &a[i][j]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                d[i][j] = 0;
                continue;
            }
            if (a[i][j] == '1')
                d[i][j] = 1;
            else
                d[i][j] = N;
        }
    }
    for (int z = 1; z <= n; ++z)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                d[x][y] = min(d[x][y], d[x][z] + d[z][y]);
            }
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    dp[1] = 1;
    for (int i = 2; i <= m; ++i)
    {
        dp[i] = i + 1;
        for (int j = i - 1; j >= 1; --j)
        {
            if (i - j > n)
                break;
            if (d[b[j]][b[i]] == i - j)
            {
                if (dp[j] + 1 < dp[i])
                {
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
            }
        }
    }
    vector<int> v;
    int x = m;
    while (1)
    {
        v.push_back(b[x]);
        if (x == 1)
            break;
        x = p[x];
    }
    reverse(v.begin(), v.end());
    printf("%d\n", dp[m]);
    for (int i = 0; i < dp[m]; ++i)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}