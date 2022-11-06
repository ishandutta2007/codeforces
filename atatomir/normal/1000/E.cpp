#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 300011;

int n, m, i, x, y, cnt;
vector<int> list[maxN], to[maxN], from[maxN], tree[maxN];
int lvl[maxN], id[maxN];
bool us[maxN];
stack<int> S;
pair<int, int> best;

void dfs_dir(int node) {
    for (auto e : list[node]) {
        if (lvl[e]) {
            if (lvl[node] > lvl[e] + 1) {
                to[node].pb(e);
                from[e].pb(node);
            }
        } else {
            lvl[e] = lvl[node] + 1;
            to[node].pb(e);
            from[e].pb(node);
            dfs_dir(e);
        }
    }
}

void dfs_to(int node) {
    us[node] = true;
    for (auto e : to[node]) {
        if (!us[e]) dfs_to(e);
    }
    S.push(node);
}

void dfs_from(int node) {
    us[node] = true;
    id[node] = cnt;

    for (auto e : from[node])
        if (!us[e])
            dfs_from(e);
}

void dfs(int node, int root, int lvl) {
    best = max(best, mp(lvl, node));
    for (auto e : tree[node])
        if (e != root)
            dfs(e, node, lvl + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    lvl[1] = 1;
    dfs_dir(1);


    for (i = 1; i <= n; i++)
        if (!us[i])
            dfs_to(i);


    memset(us, 0, sizeof(us));
    while (!S.empty()) {
        int node = S.top();
        S.pop();
    
        if (us[node]) continue;
        cnt++;
        dfs_from(node);
    }


    for (i = 1; i <= n; i++) {
        for (auto j : to[i]) {
            if (id[i] != id[j]) {
                tree[id[i]].pb(id[j]);
                tree[id[j]].pb(id[i]);
            }
        }
    }

    best = mp(-1, -1);
    dfs(1, 0, 0);

    int node = best.second;
    best = mp(-1, -1);
    dfs(node, 0, 0);

    printf("%d", best.first);

    return 0;
}