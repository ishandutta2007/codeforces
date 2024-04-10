#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011
#define def 100000
#define inf (1LL << 50)

int n, m, k, i;
int x[maxN], y[maxN];

vector<int> pp[maxN], mm[maxN];
ll ans[maxN];


ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

void solve_pp(int xx, int yy, int dx, int dy, ll now) {
    int id = def + xx - yy;

    for (auto e : pp[id])
        ans[e] = min(ans[e], now + abss(xx - x[e]));
    pp[id].clear();
}

void solve_mm(int xx, int yy, int dx, int dy, ll now) {
    int id = xx + yy;

    for (auto e : mm[id])
        ans[e] = min(ans[e], now + abss(xx - x[e]));
    mm[id].clear();
}

void solve() {
    int x, y, dx, dy, difx, dify, dif;
    ll now;

    now = 0;
    x = y = 0;
    dx = dy = 1;

    int limit = (n + m) * 10;
    while (limit-- > 0) {
        if (dx * dy == 1)
            solve_pp(x, y, dx, dy, now);
        else
            solve_mm(x, y, dx, dy, now);

        if (dx > 0)
            difx = n - x;
        else
            difx = x;

        if (dy > 0)
            dify = m - y;
        else
            dify = y;

        dif = min(difx, dify);

        x += dx * dif;
        y += dy * dif;
        now += dif;

        if ( (x == 0 || x == n) && (y == 0 || y == m) ) break;
        if (x == 0 || x == n)
            dx *= -1;
        if (y == 0 || y == m)
            dy *= -1;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= k; i++) {
        scanf("%d%d", &x[i], &y[i]);
        pp[def + x[i] - y[i]].pb(i);
        mm[x[i] + y[i]].pb(i);
        ans[i] = inf;
    }

    solve();
    for (i = 1; i <= k; i++) {
        if (ans[i] >= inf)
            printf("-1\n");
        else
            printf("%lld\n", ans[i]);
    }

    return 0;
}