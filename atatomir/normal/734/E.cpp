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

int n, i, x, y;
vector<int> list[maxN];
int col[maxN];

int cnt;
int comp[maxN];
vector<int> adj[maxN];
pair<int, int> best;

void dfs(int node) {
    comp[node] = cnt;

    for (int to : list[node])
        if (col[node] == col[to] && comp[to] == 0)
            dfs(to);
}

void solve(int node, int root, int lvl) {
    best = max(best, mp(lvl, node));
    for (int to : adj[node]) {
        if (to == root) continue;
        solve(to, node, lvl + 1);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &col[i]);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    for (i = 1; i <= n; i++) {
        if (comp[i]) continue;
        cnt++;
        dfs(i);
    }

    for (i = 1; i <= n; i++) {
        for (int to : list[i]) {
            if (comp[i] != comp[to]) {
                adj[comp[i]].pb(comp[to]);
                adj[comp[to]].pb(comp[i]);
            }
        }
    }

    n = cnt;
    for (i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
    }

    best = mp(-1, -1);
    solve(1, 0, 0);

    int R = best.second;
    best = mp(-1, -1);
    solve(R, 0, 0);

    int dist = best.first;

    if (dist % 2 == 0)
        printf("%d", dist / 2);
    else
        printf("%d", (dist / 2) + 1);

    return 0;
}