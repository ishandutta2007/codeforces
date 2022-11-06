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
#define inf 1000000000;

int n, m, i, x, y, op;
vector<int> list[maxN];
int cnt[maxN];

int R;
vector<int> adj[maxN];
bool dead[maxN];

vector< pair<int, int> > dist[maxN];
vector<int> way;
int lvl[maxN];
int ans[maxN];
int dad[maxN];

void clean(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (dead[v[i]]) {
            v[i] = v.back();
            v.pop_back();
            i--;
            continue;
        }
    }
}

void dfs(int node, int root) {
    cnt[node] = 1;

    clean(list[node]);

    for (auto to : list[node]) {
        if (to == root || dead[to]) continue;
        dfs(to, node);
        cnt[node] += cnt[to];
    }
}

int dfs2(int node, int root, int target) {
    bool ok = true;

    for (auto to : list[node]) {
        if (to == root || dead[to]) continue;

        int ans = dfs2(to, node, target);
        if (ans) return ans;

        if (cnt[to] > target / 2) ok = false;
    }

    if (target - cnt[node] > target / 2) ok = false;
    if (ok) return node;
    return 0;
}

void dfs_dist(int node, int root) {
    way.pb(node);

    dist[node].pb(mp(way.size() - 1, way[0]));

    for (auto to : list[node])
        if (to != root && dead[to] == false)
            dfs_dist(to, node);

    way.pop_back();
}

int get_centroid(int node, int act_lvl) {
    int R;

    dfs(node, 0);
    R = dfs2(node, 0, cnt[node]);
    dfs_dist(R, 0);

    lvl[R] = act_lvl;
    dead[R] = true;

    for (auto to : list[R]) {
        if (!dead[to]) {
            int aux = get_centroid(to, act_lvl + 1);
            adj[R].pb(aux);
            dad[aux] = R;
        }
    }


    /*sort(dist[R].begin(), dist[R].end(), [](const pair<int, int>& a, const pair<int, int>& b)->bool const {
        return lvl[ a.second ] < lvl[ b.second ];
    });*/

    return R;
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    R = get_centroid(1, 0);

    for (i = 1; i <= n; i++) ans[i] = inf;

    for (i = 0; i <= m; i++) {
        if (i > 0)
            scanf("%d%d", &op, &x);
        else
            op = 1, x = 1;

        if (op == 1) {
            for (int lca = x; lca != 0; lca = dad[lca])
                ans[lca] = min(ans[lca], dist[x][ lvl[lca] ].first);
        }

        if (op == 2) {
            int sol = inf;

            for (int lca = x; lca != 0; lca = dad[lca])
                sol = min(sol, dist[x][ lvl[lca] ].first + ans[lca]);

            printf("%d\n", sol);
        }
    }



    return 0;
}