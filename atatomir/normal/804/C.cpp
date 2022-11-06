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

int n, m, i, cnt, x, y, j, v;
vector<int> who[maxN];
vector<int> list[maxN];
int col[maxN];

int last[maxN];

void dfs(int node, int root) {
    int p;
    for (auto e : who[node])
        last[col[e]] = node;

    p = 1;
    for (auto e : who[node]) {
        if (col[e]) continue;
        while (last[p] == node) p++;
        col[e] = p;
        last[p] = node;
    }

    for (auto to : list[node]) {
        if (to == root) continue;
        dfs(to, node);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &cnt);
        who[i] = vector<int>(cnt); v = max(v, cnt);
        for (auto& e: who[i]) scanf("%d", &e);
    }

    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1, 0);

    cout << max(1, v) << '\n';
    for (i = 1; i <= m; i++) cout << max(col[i], 1) << ' ';


    return 0;
}