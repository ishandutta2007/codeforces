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

const int maxN = 400011;
const int maxLog = 20;

int n, q, i;
int dad[maxLog][maxN], lvl[maxN];
ll a[maxN], x, y, z;
vector< pair<ll, ll> > list[maxN];
vector< pair<ll, ll> > Q[maxN];

ll down[maxN], up[maxN], dp[maxN], sumi[maxN];
ll ans[maxN];

ll data[maxN];

void dfs(int node, int root) {
    dp[node] = a[node];

    for (auto to : list[node]) {
        if (to.first == root) continue;
        dad[0][to.first] = node;
        lvl[to.first] = lvl[node] + 1;
        sumi[to.first] = sumi[node] + to.second;
        dfs(to.first, node);

        down[to.first] = max(0LL, dp[to.first] - 2LL * to.second);
        dp[node] += down[to.first];
    }
}

void dfs2(int node, int root) {
    dp[node] += up[node];

    for (auto to : list[node]) {
        if (to.first == root) continue;
        up[to.first] = max(0LL, dp[node] - down[to.first] - 2LL * to.second);
        dfs2(to.first, node);
    }
}

void pre() {
    int i, j;
    for (i = 1; i < maxLog; i++)
        for (j = 1; j <= n; j++)
            dad[i][j] = dad[i - 1][dad[i - 1][j]];
}

void go_up(int& a, int cnt) {
    for (int i = 0; cnt > 0; cnt >>= 1, i++)
        if (cnt & 1)
            a = dad[i][a];
}

int lca(int x, int y) {
    if (lvl[x] < lvl[y]) swap(x, y);
    go_up(x, lvl[x] - lvl[y]);
    if (x == y) return x;
    for (int i = maxLog - 1; i >= 0; i--)
        if (dad[i][x] != dad[i][y])
            x = dad[i][x], y = dad[i][y];
    return dad[0][x];
}

void add_query(int id) {
    if (x == y) {
        ans[id] = dp[x];
        return;
    }

    int lc = lca(x, y);
    if (lc == y) swap(x, y);

    if (lc == x) {
       Q[y].pb(mp(dad[0][x], id));
       ans[id] += up[x];
       ans[id] -= sumi[y] - sumi[x];
    } else {
        Q[x].pb(mp(dad[0][lc], id));
        Q[y].pb(mp(lc, id));
        ans[id] += up[lc];

        int yy = y;
        go_up(yy, lvl[yy] - lvl[lc] - 1);
        ans[id] -= down[yy];

        ans[id] -= sumi[x] + sumi[y] - 2LL * sumi[lc];
    }
}

void solve(int node, int root) {
    data[node] += dp[node];

    /*cerr << node << ": ";
    for (int i = 1; i <= n; i++) cerr << data[i] << ' ';
    cerr << '\n';*/

    for (auto e : Q[node]) {
        ans[e.second] += data[node] - data[e.first];
    }

    for (auto to : list[node]) {
        if (to.first == root) continue;
        data[node] -= down[to.first];
        data[to.first] += data[node] - up[to.first];
        solve(to.first, node);
        data[node] += down[to.first];
   }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (i = 1; i < n; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));
    }

    dfs(1, 0);

    //for (i = 1; i <= n; i++) cerr << dp[i] << ' ';
    //cerr << '\n';

    pre();
    dfs2(1, 0);

    //for (i = 1; i <= n; i++) cerr << up[i] << ' ';
    //cerr << '\n';

    for (i = 1; i <= q; i++) {
        scanf("%lld%lld", &x, &y);
        add_query(i);
    }



    solve(1, 0);


    for (i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);

    return 0;
}