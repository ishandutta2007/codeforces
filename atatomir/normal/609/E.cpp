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

#define maxN 200011
#define maxLog 18

struct edge {
    int x, y, id;
    ll cost;

    bool operator<(const edge& who)const {
        return cost < who.cost;
    }
};

int n, m, i, j;
edge E[maxN];
int dad[maxN];
ll total;
vector< pair<int, ll> > list[maxN];

bool us[maxN];
int lvl[maxN];
int up[maxLog][maxN];
int cost_up[maxLog][maxN];
ll ans[maxN];


int Find(int x) {
    if (dad[x] == x) return x;
    dad[x] = Find(dad[x]);
    return dad[x];
}

bool Merge(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) return false;
    dad[x] = y;
    return true;
}

void dfs(int node) {
    us[node] = true;

    for (auto to : list[node]) {
        if (us[to.first]) continue;
        lvl[to.first] = lvl[node] + 1;
        up[0][to.first] = node;
        cost_up[0][to.first] = to.second;
        dfs(to.first);
    }
}

void go_up(int& x, int how, int& ans) {
    for (int i = 0; how > 0; i++) {
        if (how & 1) {
            ans = max(ans, cost_up[i][x]);
            x = up[i][x];
        }

        how >>= 1;
    }
}

int query(int x, int y) {
    int ans = 0;

    if (lvl[x] < lvl[y]) swap(x, y);

    go_up(x, lvl[x] - lvl[y], ans);
    if (x == y) return ans;

    if (lvl[x] < lvl[y]) swap(x, y);
    for (int i = maxLog - 1; i >= 0; i--) {
        if (up[i][x] == up[i][y]) continue;
        ans = max(ans, cost_up[i][x]);
        ans = max(ans, cost_up[i][y]);

        x = up[i][x];
        y = up[i][y];
    }

    return max(ans, max(cost_up[0][x], cost_up[0][y]));
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%lld", &E[i].x, &E[i].y, &E[i].cost);
        E[i].id = i;
        dad[i] = i;
    }

    sort(E + 1, E + m + 1);
    for (i = 1; i <= m; i++) {
        if (!Merge(E[i].x, E[i].y)) continue;
        total += E[i].cost;
        list[E[i].x].pb(mp(E[i].y, E[i].cost));
        list[E[i].y].pb(mp(E[i].x, E[i].cost));
    }

    dfs(1);
    for (i = 1; i < maxLog; i++) {
        for (j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][ up[i - 1][j] ];
            cost_up[i][j] = max(cost_up[i - 1][j], cost_up[i - 1][ up[i - 1][j] ]);
        }
    }

    for (i = 1; i <= m; i++)
        ans[E[i].id] = total + E[i].cost - query(E[i].x, E[i].y);

    for (i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);


    return 0;
}