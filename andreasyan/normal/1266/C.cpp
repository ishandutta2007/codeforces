#include <bits/stdc++.h>
using namespace std;
const int N = 502;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n, m;
int a[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1)
    {
        printf("0\n");
        return 0;
    }
    if (n <= m)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                a[i][j] = i;
        }
        for (int j = 1; j <= m; ++j)
        {
            for (int i = 1; i <= n; ++i)
                a[i][j] *= (n + j);
        }
    }
    else
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int i = 1; i <= n; ++i)
                a[i][j] = j;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                a[i][j] *= (m + i);
        }
    }
    /*for (int i = 1; i <= n; ++i)
    {
        int x = a[i][1];
        for (int j = 1; j <= m; ++j)
            x = gcd(x, a[i][j]);
        printf("%d ", x);
    }
    for (int j = 1; j <= m; ++j)
    {
        int x = a[1][j];
        for (int i = 1; i <= n; ++i)
            x = gcd(x, a[i][j]);
        printf("%d ", x);
    }
    printf("\n");*/
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}