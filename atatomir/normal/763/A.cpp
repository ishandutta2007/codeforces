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

int n, i, j, x, y, need;
int c[maxN];
vector<int> list[maxN];

int col[maxN], up[maxN];
int l[maxN], r[maxN];

void dfs(int node, int root) {
    col[node] = c[node];

    for (auto to : list[node]) {
        if (to == root) continue;

        dfs(to, node);
        if (col[node] != col[to]) col[node] = -1;
    }
}

int comb(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    if (a != b) return -1;
    return a;
}

void dfs2(int node, int root) {
    int i;

    for (i = 0; i < list[node].size(); i++) {
        if (list[node][i] != root) continue;

        list[node][i] = list[node].back();
        list[node].pop_back();
        break;
    }

    if (list[node].empty()) return;

    l[0] = col[ list[node][0] ];
    for (i = 1; i < list[node].size(); i++)
        l[i] = (l[i - 1] == col[ list[node][i] ] ? l[i - 1] : -1);

    r[list[node].size() - 1] = col[ list[node].back() ];
    for (i = list[node].size() - 2; i >= 0; i--)
        r[i] = (r[i + 1] == col[ list[node][i] ] ? r[i + 1] : -1);

    for (i = 0; i < list[node].size(); i++) {
        int to = list[node][i];

        int act = up[node];
        if (i != 0) act = comb(act, l[i - 1]);
        if (i + 1 < list[node].size()) act = comb(act, r[i + 1]);

        act = comb(act, c[node]);
        up[to] = act;
    }

    for (auto to : list[node])
        dfs2(to, node);

    bool ok = (up[node] != -1);
    for (auto to : list[node]) {
        if (col[to] == -1)
            ok = false;
    }

    if (ok) {
        printf("YES\n%d\n", node);
        exit(0);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    for (i = 1; i <= n; i++)
        scanf("%d", &c[i]);

    dfs(1, 0);
    dfs2(1, 0);

    printf("NO");


    return 0;
}