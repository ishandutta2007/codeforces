#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1024
#define tp pair< pair<int, int>, pair<int, int> >
#define inf 1000000000

const int defX[4] = {-1, 1, 0, 0};
const int defY[4] = {0, 0, -1, 1};

int n, m, i, j, p, k;
char mat[maxN][maxN];
int ix, iy, fx, fy;

pair<int, int> dp[maxN][maxN][4];
priority_queue< tp, vector< tp >, greater< tp > > H;

void add_to_queue(int x, int y, int dir, int c1, int c2) {
    if (dp[x][y][dir] > mp(c1, c2)) {
        dp[x][y][dir] = mp(c1, c2);
        H.push(mp(mp(c1, c2), mp(x, y * 4 + dir)));
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d\n", &n, &m, &k);
    for (i = 1; i <= n; i++)
        scanf("%s\n", mat[i] + 1);
    scanf("%d%d%d%d", &ix, &iy, &fx, &fy);

    for (i = 0; i <= n + 1; i++)
        mat[i][0] = mat[i][m + 1] = '#';

    for (i = 0; i <= m + 1; i++)
        mat[0][i] = mat[n + 1][i] = '#';

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            for (p = 0; p < 4; p++)
                dp[i][j][p] = mp(inf, inf);

    add_to_queue(ix, iy, 0, 0, k);

    while (!H.empty()) {
        auto act = H.top(); H.pop();
        int c1 = act.first.first;
        int c2 = act.first.second;
        int x = act.second.first;
        int y = act.second.second >> 2;
        int dir = (act.second.second & 3);

        if (dp[x][y][dir] != mp(c1, c2)) continue;
        if (x == fx && y == fy) {
            printf("%d\n", c1);
            return 0;
        }

        int xx, yy;

        for (p = 0; p < 4; p++) {
            xx = x + defX[p];
            yy = y + defY[p];

            if (mat[xx][yy] != '#')
                add_to_queue(xx, yy, p, c1 + 1, 1);
        }

        xx = x + defX[dir];
        yy = y + defY[dir];

        if (mat[xx][yy] != '#' && c2 != k)
            add_to_queue(xx, yy, dir, c1, c2 + 1);
    }

    printf("-1");


    return 0;
}