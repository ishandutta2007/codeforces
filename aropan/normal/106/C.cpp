#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1002;
const int MAXM = 12;
const int MAXA = 102;
const int INF = 2e+9;

int n, m, c0, d0;
int a[MAXM], b[MAXM], c[MAXM], d[MAXM];
int f[MAXM][MAXN][MAXA];


int maxi(int &x, int y)
{
    if (x > y) return 0;
    x = y;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d %d %d", &n, &m, &c0, &d0);

    for (int i = 0; i < m; i++)
        scanf("%d %d %d %d\n", &a[i], &b[i], &c[i], &d[i]);
    a[m] = 0;

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= a[i]; k++)
                f[i][j][k] = -INF;

    for (int i = 0; i * c0 <= n; i++)
        f[0][n - i * c0][a[0]] = d0 * i;

    for (int i = 0; i < m; i++)
        for (int j = n; j >= 0; j--)
            for (int k = a[i]; k >= 0; k--)
                if (f[i][j][k] >= 0)
                {
                    if (j >= c[i] && k >= b[i])
                        maxi(f[i][j - c[i]][k - b[i]], f[i][j][k] + d[i]);

                    if (j) maxi(f[i][j - 1][k],  f[i][j][k]);
                    if (k) maxi(f[i][j][k - 1],  f[i][j][k]);
                    maxi(f[i + 1][j][a[i + 1]], f[i][j][k]);
                }
    printf("%d\n", f[m][0][0]);
    return 0;
}