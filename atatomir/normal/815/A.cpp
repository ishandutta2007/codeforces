#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 111

int n, m, i, j;
int g[maxN][maxN], rez[maxN][maxN], mini;

int ln[maxN], co[maxN], p1, p2;
int ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    mini = 1111;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &g[i][j]), mini = min(mini, g[i][j]), rez[i][j] = g[i][j];

    if (mini > 0) {
        if (n < m) {
            for (i = 1; i <= n; i++)
                ln[i] += mini;
        } else {
            for (i = 1; i <= m; i++)
                co[i] += mini;
        }

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                g[i][j] -= mini;
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (g[i][j] == 0)
                p1 = i, p2 = j;

    for (i = 1; i <= n; i++)
        ln[i] += g[i][p2];

    for (i = 1; i <= m; i++)
        co[i] += max(0, rez[1][i] - ln[1] - co[i]);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (ln[i] + co[j] != rez[i][j]) {
                printf("-1");
                return 0;
            }
        }
    }

    for (i = 1; i <= n; i++)
        ans += ln[i];

    for (i = 1; i <= m; i++)
        ans += co[i];

    printf("%d\n", ans);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= ln[i]; j++)
            printf("row %d\n", i);
    }
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= co[i]; j++)
            printf("col %d\n", i);
    }


    return 0;
}