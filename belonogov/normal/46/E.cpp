#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

long long a[1600][1600], b[1600][1600], d[1600][1600], use[1600][1600];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%I64d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = b[i][j - 1] + a[i][j];
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            long long mm = m;
            for (int j = m; j >= 1; j--)
                if (d[i][j] + b[i][j] > d[i][mm] + b[i][mm])
                {
                    for (int k = j; k <= mm - 1; k++)
                    {
                        d[i + 1][k] = d[i][mm] + b[i][mm];
                        use[i + 1][k] = 1;
                    }
                    mm = j;
                }
            for (int k = 1; k <= mm - 1; k++)
            {
                d[i + 1][k] = d[i][mm] + b[i][mm];
                use[i + 1][k] = 1;
            }

        }
            else
        {
            long long mm = 1;
            for (int j = 1; j <= m; j++)
                if (d[i][j] + b[i][j] > d[i][mm] + b[i][mm])
                {
                    for (int k = mm + 1; k <= j ; k++)
                    {
                        d[i + 1][k] = d[i][mm] + b[i][mm];
                        use[i + 1][k] = 1;
                    }
                    mm = j;
                }
            for (int k = mm + 1; k <= m ; k++)
            {
                d[i + 1][k] = d[i][mm] + b[i][mm];
                use[i + 1][k] = 1;
            }
        }
    }
    long long mm = d[n + 1][1];
    if (use[n + 1][1] == 0) mm = d[n + 1][2];
    for (int i = 2; i <= m; i++)
        if (d[n + 1][i] > mm && use[n + 1][i] == 1) mm = d[n + 1][i];
    cout << mm;
    return 0;
}