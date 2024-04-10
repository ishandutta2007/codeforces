#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAXS = 1001 * 101;
const int MAXN = 101;

long double c[MAXS][MAXN];
int n, m, h, a, s;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    c[0][0] = 1;
    for (int i = 1; i < MAXS; i++)
    {
        c[i][0] = c[i - 1][0];
        for (int j = 1; j <= i && j < MAXN; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }

    scanf("%d %d %d", &n, &m, &h);
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        s += x;
        if (h == i) a = x;
    }

    if (s < n)
    {
        puts("-1");
        return 0;
    }


    if (s - a < n - 1)
    {
        puts("1.0");
        return 0;
    }

    printf("%.10lf\n", (double)(1 - c[s - a][n - 1] / c[s - 1][n - 1]));
    return 0;
}