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

#define maxN 1024
#define maxM 200011

struct que {
    int l, r, s, t, id;

    void read(int _id) {
        id = _id;
        scanf("%d%d%d%d", &l, &r, &s, &t);
    }

    bool operator<(const que& who)const {
        return l < who.l;
    }
};

int n, m, i, j, pos, x, y, q;
pair<int, int> E[maxM];
que Q[maxM];

int dp[maxN][maxN];
bool ans[maxM];


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        E[i] = mp(x, y);
    }

    for (i = 1; i <= q; i++) Q[i].read(i);
    sort(Q + 1, Q + q + 1);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            dp[i][j] = m + 7;

    pos = q;
    for (i = m; i > 0; i--) {
        x = E[i].first;
        y = E[i].second;

        for (j = 1; j <= n; j++) dp[x][j] = dp[y][j] = min(dp[x][j], dp[y][j]);
        dp[x][x] = dp[x][y] = dp[y][x] = dp[y][y] = i;

        while (pos > 0 && Q[pos].l == i) {
            ans[ Q[pos].id ] = (dp[ Q[pos].s ][ Q[pos].t ] <= Q[pos].r);
            pos--;
        }
    }

    for (i = 1; i <= q; i++)
        if (ans[i])
            printf("Yes\n");
        else
            printf("No\n");


    return 0;
}