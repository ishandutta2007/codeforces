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

const int maxN = 111;

int n, k, i, j, x, y, xx, yy;
int data[10][maxN];
bool any = false;
vector< pair<int, int> > ord;
vector< pair<int, pair<int, int> > > ans;

void mv(int id, int x, int y) {
    ans.pb(mp(id, mp(x, y)));
}

bool can_park(int x, int y) {
    if (x == 2) {
        if (data[1][y] == data[x][y]) {
            mv(data[x][y], 1, y);
            data[x][y] = 0;
            return true;
        }
    } else {
        if (data[4][y] == data[x][y]) {
            mv(data[x][y], 4, y);
            data[x][y] = 0;
            return true;
        }
    }

    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= 4; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &data[i][j]);

    for (i = 1; i <= n; i++) {
        if (data[1][i] == data[2][i] && data[1][i] != 0) {
            mv(data[1][i], 1, i);
            data[2][i] = 0;
        }

        if (data[3][i] == data[4][i] && data[3][i] != 0) {
            mv(data[4][i], 4, i);
            data[3][i] = 0;
        }

        any |= (data[2][i] == 0);
        any |= (data[3][i] == 0);
    }

    if (!any) {
        printf("-1");
        return 0;
    }

    for (i = 1; i <= n; i++) ord.pb(mp(2, i));
    for (i = n; i >= 1; i--) ord.pb(mp(3, i));
    ord.pb(ord[0]);

    any = true;
    while (any) {
        any = false;

        for (i = 0; i + 1 < ord.size(); i++) {
            x = ord[i].first;
            y = ord[i].second;
            xx = ord[i + 1].first;
            yy = ord[i + 1].second;

            if (data[x][y] == 0) continue;
            if (can_park(x, y)) continue;
            any = true;

            if (data[xx][yy] != 0) continue;
            mv(data[x][y], xx, yy);
            data[xx][yy] = data[x][y];
            data[x][y] = 0;
        }

    }

    printf("%d\n", ans.size());
    for (auto e : ans)
        printf("%d %d %d\n", e.first, e.second.first, e.second.second);

    return 0;
}