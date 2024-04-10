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
#define maxLog 18

int n, m, q, i, j, x, y, a;
vector<int> list[maxN];
int dad[maxLog][maxN];
vector<int> pre[maxLog][maxN];
int lvl[maxN];

int ss, dd;
vector<int> ans[2];

void dfs(int node, int root) {
    for (auto to : list[node]) {
        if (to == root) continue;
        lvl[to] = lvl[node] + 1;
        dad[0][to] = node;
        dfs(to, node);
    }
}

void comb(vector<int>& dest, vector<int>& s1, vector<int>& s2) {
    dest.resize(s1.size() + s2.size());
    merge(s1.begin(), s1.end(), s2.begin(), s2.end(), dest.begin());
    if (dest.size() > a) dest.resize(a);
}

void solve() {
    int i;
    if (lvl[x] > lvl[y]) swap(x, y);

    ss = 0; dd = 1;
    ans[0].clear();
    ans[1].clear();

    int dif = lvl[y] - lvl[x];
    for (i = 0; dif > 0; i++, dif >>= 1) {
        if (dif & 1) {
            comb(ans[dd], ans[ss], pre[i][y]);
            swap(ss, dd);

            y = dad[i][y];
        }
    }

    for (i = maxLog - 1; i >= 0; i--) {
        if (dad[i][x] == dad[i][y]) continue;
        comb(ans[dd], ans[ss], pre[i][x]);
        swap(ss, dd);
        comb(ans[dd], ans[ss], pre[i][y]);
        swap(ss, dd);

        x = dad[i][x];
        y = dad[i][y];
    }

    if (x != y) {
        comb(ans[dd], ans[ss], pre[0][x]);
        swap(ss, dd);
        comb(ans[dd], ans[ss], pre[0][y]);
        swap(ss, dd);

        x = dad[0][x];
        y = dad[0][y];
    }

    comb(ans[dd], ans[ss], pre[0][x]);
    swap(ss, dd);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    a = 10;

    dfs(1, 0);
    for (i = 1; i <= m; i++) {
        scanf("%d", &x);
        if(pre[0][x].size() < 10)
            pre[0][x].pb(i);
    }

    for (i = 1; i < maxLog; i++) {
        for (j = 1; j <= n; j++) {
            dad[i][j] = dad[i - 1][dad[i - 1][j]];
            comb(pre[i][j], pre[i - 1][j], pre[i - 1][dad[i - 1][j]]);
        }
    }

    for (i = 1; i <= q; i++) {
        scanf("%d%d%d", &x, &y, &a);
        solve();

        printf("%d ", ans[ss].size());
        for (auto e : ans[ss]) printf("%d ", e);
        printf("\n");
    }



    return 0;
}