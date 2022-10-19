#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, m;
char **a;

int **p;
int **pp;
int **u;
void pre()
{
    u = new int*[n + 6];
    for (int i = 0; i < n + 6; ++i)
    {
        u[i] = new int[m + 6];
    }
    for (int i = 0; i < n + 6; ++i)
    {
        for (int j = 0; j < m + 6; ++j)
        {
            u[i][j] = 0;
        }
    }
    pp = new int*[n + 6];
    for (int i = 0; i < n + 6; ++i)
    {
        pp[i] = new int[m + 6];
    }
    for (int i = 0; i < n + 6; ++i)
    {
        for (int j = 0; j < m + 6; ++j)
        {
            pp[i][j] = 0;
        }
    }
    p = new int*[n + 6];
    for (int i = 0; i < n + 6; ++i)
    {
        p[i] = new int[m + 6];
    }
    for (int i = 0; i < n + 6; ++i)
    {
        for (int j = 0; j < m + 6; ++j)
        {
            p[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            if (a[i][j] == '.')
                ++p[i][j];
        }
    }
}
bool stgg(int x1, int x2, int y1, int y2)
{
    if (x1 <= 0)
        return false;
    if (x2 > n)
        return false;
    if (y1 <= 0)
        return false;
    if (y2 > m)
        return false;
    return (p[x2][y2] - p[x2][y1 - 1] - p[x1 - 1][y2] + p[x1 - 1][y1 - 1] == 0);
}

bool stg(int k)
{
    for (int i = 0; i < n + 6; ++i)
    {
        for (int j = 0; j < m + 6; ++j)
        {
            pp[i][j] = 0;
        }
    }
    for (int i = 0; i < n + 6; ++i)
    {
        for (int j = 0; j < m + 6; ++j)
        {
            u[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (stgg(i - k, i + k, j - k, j + k))
            {
                u[i - k][j - k]++;
                u[i + k + 1][j + k + 1]++;
                u[i - k][j + k + 1]--;
                u[i + k + 1][j - k]--;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            pp[i][j] = pp[i - 1][j] + pp[i][j - 1] - pp[i - 1][j - 1];
            pp[i][j] += u[i][j];
            if (a[i][j] == 'X' && pp[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    a = new char*[n + 6];
    for (int i = 0; i < n + 6; ++i)
        a[i] = new char[m + 6];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf(" %c", &a[i][j]);
        }
    }
    pre();
    int l = 0, r = n;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (stgg(i - ans, i + ans, j - ans, j + ans))
            {
                printf("X");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}