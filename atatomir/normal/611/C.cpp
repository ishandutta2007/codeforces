#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 555
#define x1 xx1
#define x2 xx2
#define y1 yy1
#define y2 yy2

int n, i, j, m, q, x1, y1, x2, y2, ans;
char grid[maxN][maxN];
int vert[maxN][maxN];
int hori[maxN][maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%s\n", grid[i] + 1);

    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++) {
            vert[i][j] = vert[i - 1][j] + vert[i][j - 1] - vert[i - 1][j - 1];
            hori[i][j] = hori[i - 1][j] + hori[i][j - 1] - hori[i - 1][j - 1];

            if (grid[i][j] == grid[i][j + 1] && grid[i][j] == '.')
                hori[i][j]++;
            if (grid[i][j] == grid[i + 1][j] && grid[i][j] == '.')
                vert[i][j]++;
        }
    }

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        ans = 0;

        y2--;
        if (y1 <= y2) ans += hori[x2][y2] - hori[x1 - 1][y2] - hori[x2][y1 - 1] + hori[x1 - 1][y1 - 1];
        y2++;

        x2--;
        if (x1 <= x2) ans +=vert[x2][y2] - vert[x1 - 1][y2] - vert[x2][y1 - 1] + vert[x1 - 1][y1 - 1];
        x2++;

        printf("%d\n", ans);
    }


    return 0;
}