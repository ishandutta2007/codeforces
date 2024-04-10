#include<cstdio>
#include<climits>
#include<algorithm>

/*
#include<climits>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
//*/

#define sqr(x) ((x)*(x))

using namespace std;

const int MAXN = 25;
const int MAXM = 1 << (MAXN - 1);
const int INF = LONG_MAX / 2;

int a[MAXN][MAXN];
int f[MAXM], p[MAXM];
int x[MAXN], y[MAXN], d[MAXN];
int n, m, k, prev, mini;

int dfs(int x)
{
    if (x == 0) return 0;
    dfs(x ^ p[x]);
    printf("0 ");
    for (int i = 0; i < n; i++)
        if (p[x] & (1 << i))
            printf("%d ", i + 1);
    return 0;
}

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d %d %d", &x[0], &y[0], &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &x[i], &y[i]);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            a[i][j] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
 
    m = 1 << n;

    f[0] = p[0] = 0;
    for (int mask = 1; mask < m; mask++)
    {
        f[mask] = INF;
        p[mask] = 0;

        k = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
            {
                d[k++] = i;
                if (a[0][d[0]] < a[0][d[k - 1]])
                    swap(d[0], d[k - 1]);
            }
         
        for (int i = 0; i < k; i++)
        {
            if ((mini = f[mask ^ (prev = (1 << d[i]))] + 2 * a[0][d[i] + 1]) < f[mask])
            {
                f[mask] = mini;
                p[mask] = prev;
            }

            if ((mini = f[mask ^ (prev = ((1 << d[i]) | (1 << d[0])))] + a[0][d[i] + 1] + a[d[i] + 1][d[0] + 1] + a[d[0] + 1][0]) < f[mask])
            {
                f[mask] = mini;
                p[mask] = prev;
            }
        }
    }
    printf("%d\n", f[m - 1]);
    dfs(m - 1);
    printf("0\n");

    return 0;
}