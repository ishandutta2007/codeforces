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

#define maxN 300011
#define maxLog 21

int n, q, i, x;
vector<int> list[maxN];
int lvl[maxN];
int dad[maxN];
int cnt[maxN];
int worst[maxN];

vector<int> Q[maxN];

int cen[maxN];
int ans[maxN];



void dfs(int node) {
    cnt[node] = 1;

    for (auto to : list[node]) {
        lvl[to] = lvl[node] + 1;
        dfs(to);
        cnt[node] += cnt[to];

        worst[node] = max(worst[node], cnt[to]);
    }
}

int move_up(int node, int val_lim, int node_lim) {
    while (node != node_lim && 2 * worst[ dad[node] ] <= val_lim) node = dad[node];
    return node;
}


void solve(int node) {
    int aux;
    cen[node] = node;

    for (auto to : list[node]) {
        solve(to);

        aux = move_up(cen[to], cnt[node], node);
        if (lvl[aux] > lvl[cen[node]])
            cen[node] = aux;
    }

    if (lvl[node] + 1 == lvl[ cen[node] ]) {
        //! find the best node
        pair<int, int> best = mp(-1, -1);
        for (auto to : list[node])
            best = max(best, mp(cnt[to], to));
        cen[node] = best.second;
    }

    for (auto e : Q[node])
        ans[e] = cen[node];
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 2; i <= n; i++) {
        scanf("%d", &x);
        list[x].pb(i);
        dad[i] = x;
    }

    dfs(1);

    for (i = 1; i <= q; i++) {
        scanf("%d", &x);
        Q[x].pb(i);
    }

    solve(1);
    for (i = 1; i <= q; i++) printf("%d\n", ans[i]);


    return 0;
}