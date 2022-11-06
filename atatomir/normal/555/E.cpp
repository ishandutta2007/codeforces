#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define maxLog 20
#define up dad

int n, m, q, i, j, x, y, cnt, cnt_big;
vector<int> list[maxN], to[maxN], from[maxN], adj[maxN];
int lvl[maxN], lvl_big[maxN];
bool us[maxN];
int gr[maxN], gr_big[maxN];
stack<int> S;

int dad[maxLog][maxN];
int mv_up[maxN], mv_down[maxN];
int xx[maxN], yy[maxN];
map< pair<int, int>, bool> M;

void dfs(int node) {
    for (auto e : list[node]) {
        if (lvl[e]) {
            if (lvl[e] == lvl[node] + 1) {
                to[e].pb(node);
                from[node].pb(e);
                continue;
            }

            if (lvl[e] >= lvl[node] - 1) continue;
            to[node].pb(e);
            from[e].pb(node);
        } else {
            M[mp(node, e)] = true;
            to[node].pb(e);
            from[e].pb(node);
            lvl[e] = lvl[node] + 1;
            dfs(e);
        }
    }
}

void dfs2(int node) {
    us[node] = true;
    for (auto e : to[node]) {
        if (us[e]) continue;
        dfs2(e);
    }
    S.push(node);
}

void dfs3(int node) {
    gr[node] = cnt;
    for (auto e : from[node])
        if (gr[e] == 0)
            dfs3(e);
}

void dfs4(int node) {
    gr_big[node] = cnt_big;
    for (auto e : adj[node])
        if (gr_big[e] == 0)
            lvl_big[e] = lvl_big[node] + 1, dfs4(e), dad[0][e] = node;
}

int lca(int x, int y) {
    if (lvl_big[x] > lvl_big[y]) swap(x, y);

    int dif = lvl_big[y] - lvl_big[x];
    for (int i = 0; dif > 0; i++, dif >>= 1)
        if (dif & 1)
            y = up[i][y];

    if (x == y) return x;
    for (int i = maxLog - 1; i >= 0; i--)
        if (up[i][x] != up[i][y])
            x = up[i][x], y = up[i][y];

    return up[0][x];
}

void dfs5(int node, int root) {
    for (auto e : adj[node]) {
        if (e != root) {
            dfs5(e, node);
            mv_down[node] += mv_down[e];
            mv_up[node] += mv_up[e];
        }
    }

    if (mv_down[node] > 0 && mv_up[node] > 0) {
        printf("No\n");
        exit(0);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    lvl[1] = 1;
    dfs(1);
    dfs2(1);

    while (!S.empty()) {
        int node = S.top(); S.pop();
        if (gr[node]) continue;
        cnt++;
        dfs3(node);
    }

    for (i = 1; i <= n; i++)
        for (auto e : list[i])
            if (gr[i] != gr[e])
                adj[gr[i]].pb(gr[e]);

    for (i = 1; i <= cnt; i++) {
        if (gr_big[i]) continue;
        cnt_big++;
        dfs4(i);
    }

    for (i = 1; i < maxLog; i++)
        for (j = 1; j <= cnt; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];

    for (i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y);
        x = gr[x];
        y = gr[y];

        if (x == y) continue;
        if (gr_big[x] != gr_big[y]) {
            printf("No\n");
            return 0;
        }

        mv_up[x]++;
        mv_down[y]++;
        int pp = lca(x, y);
        mv_up[pp]--;
        mv_down[pp]--;
    }

    for (i = 1; i <= cnt; i++) {
        if (lvl_big[i] != 0) continue;
        dfs5(i, 0);
    }

    printf("Yes\n");


    return 0;
}