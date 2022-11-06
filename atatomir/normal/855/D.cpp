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
#define maxLog 22
#define dad up

int n, q, i, j;
int par[maxN], tp[maxN];
vector< pair<int, int> > list[maxN];

int pp, t, u, v;
int l[maxN], r[maxN];
int cnt[maxN][3];
int lvl[maxN];

int up[maxLog][maxN];

void no() {
    cout << "NO\n";
}

void yes() {
    cout << "YES\n";
}

void dfs(int node) {
    l[node] = ++pp;

    for (auto to : list[node]) {
        lvl[to.first] = lvl[node] + 1;
        cnt[to.first][2] = cnt[node][2];
        cnt[to.first][1] = cnt[node][1];
        cnt[to.first][to.second]++;
        dfs(to.first);
    }

    r[node] = pp;
}

int lca(int x, int y) {
    if (lvl[x] > lvl[y])
        swap(x, y);

    for (int i = 20; i >= 0; i--)
        if (lvl[x] <= lvl[ dad[i][y] ])
            y = dad[i][y];

    if (x == y) return x;
    for (int i = 20; i >= 0; i--)
        if (dad[i][x] != dad[i][y])
            x = dad[i][x], y = dad[i][y];

    return dad[0][x];
}

void solve1(int u, int v) {
    int d = lca(u, v);

    if (u == v) {
        no();
        return;
    }

    if (lvl[u] - lvl[d] == 0 &&
        lvl[v] - lvl[d] == cnt[v][1] - cnt[d][1])
        yes();
    else
        no();
}

void solve2(int u, int v) {
    int d = lca(u, v);

    if (u == v) {
        no();
        return;
    }

    if (lvl[u] - lvl[d] == cnt[u][1] - cnt[d][1] &&
        lvl[v] - lvl[d] == cnt[v][2] - cnt[d][2] &&
        v != d)
        yes();
    else
        no();
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> par[i] >> tp[i]; tp[i]++;
        if (par[i] == -1) {
            par[i] = n + 1;
            tp[i] = 2;
        }

        list[par[i]].pb(mp(i, tp[i]));
        up[0][i] = par[i];
    }

    lvl[0] = -1;
    for (i = 1; i <= 20; i++)
        for (j = 1; j <= n + 1; j++)
            up[i][j] = up[i - 1][ up[i - 1][j] ];


    dfs(n + 1);
    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> t >> u >> v;
        if (t == 1)
            solve1(u, v);
        else
            solve2(u, v);
    }


    return 0;
}