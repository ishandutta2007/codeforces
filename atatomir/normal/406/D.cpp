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

#define maxN 100011
#define maxLog 20

struct Point {
    ll x, y;
};

int n, i, j, m, x, y;
Point P[maxN];
vector< pair<Point, int> > Hull;
int dad[maxLog][maxN];
int lvl[maxN];

ll cross(Point A, Point B, Point C) {
    B.x -= A.x;
    B.y -= A.y;
    C.x -= A.x;
    C.y -= A.y;

    return B.x * C.y - B.y * C.x;
}

int lca(int x, int y) {
    int i, dif;

    if (lvl[x] > lvl[y]) swap(x, y);

    dif = lvl[y] - lvl[x];
    for (i = 0; dif > 0; i++, dif >>= 1)
        if (dif & 1)
            y = dad[i][y];

    if (x == y) return x;
    for (i = maxLog - 1; i >= 0; i--) {
        if (dad[i][x] != dad[i][y]) {
            x = dad[i][x];
            y = dad[i][y];
        }
    }

    return dad[0][x];
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld%lld", &P[i].x, &P[i].y);

    Hull = {mp(P[n], n)};
    for (i = n - 1; i > 0; i--) {
        auto act = P[i];

        while (Hull.size() >= 2) {
            if (cross(act, Hull.back().first, Hull[Hull.size() - 2].first) <= 0) break;
            Hull.pop_back();
        }

        dad[0][i] = Hull.back().second;
        lvl[i] = lvl[dad[0][i]] + 1;
        Hull.pb(mp(act, i));
    }

    for (i = 1; i < maxLog; i++)
        for (j = 1; j <= n; j++)
            dad[i][j] = dad[i - 1][ dad[i - 1][j] ];

    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        printf("%d ", lca(x, y));
    }



    return 0;
}