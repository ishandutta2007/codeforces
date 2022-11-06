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

struct node {
    int id;
    vector<int> list;

    bool operator<(const node& who)const {
        return list < who.list;
    }
};

int n, m, i, j, cnt, x, y;
node nodes[maxN];
vector<int> list[maxN];
int gr[maxN], lab[maxN];
int any;

void no_sol() {
    printf("NO\n");
    exit(0);
}

void dfs(int node, int lb) {
    lab[node] = lb;

    for (auto to : list[node])
        if (lab[to] == 0)
            dfs(to, lb + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m;
    for (i = 1; i <= n; i++) nodes[i].id = i, nodes[i].list = {i};
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        nodes[x].list.pb(y);
        nodes[y].list.pb(x);
    }

    for (i = 1; i <= n; i++)
        sort(nodes[i].list.begin(), nodes[i].list.end());

    sort(nodes + 1, nodes + n + 1);

    for (i = 1; i <= n; i = j) {
        cnt++;
        for (j = i; j <= n && nodes[i].list == nodes[j].list; j++)
            gr[ nodes[j].id ] = cnt;
    }

    for (i = 1; i <= n; i++) {
        for (auto to : nodes[i].list) {
            if (gr[nodes[i].id] != gr[to])
                list[gr[nodes[i].id]].pb(gr[to]);
        }
    }

    for (i = 1; i <= cnt; i++) {
        sort(list[i].begin(), list[i].end());
        list[i].resize(unique(list[i].begin(), list[i].end()) - list[i].begin());
        if (list[i].size() > 2) no_sol();
        if (list[i].size() <= 1) any = i;
    }

    if (any == 0) no_sol();
    dfs(any, 1);

    printf("YES\n");
    for (i = 1; i <= n; i++)
        printf("%d ", lab[ gr[i] ]);

    return 0;
}