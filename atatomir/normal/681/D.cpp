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

int n, m, i, x, y;
vector<int> list[maxN];
bool head[maxN];
int dad[maxN], gift[maxN];

bool used[maxN];
vector<int> ans;

void dead() {
    printf("-1");
    exit(0);
}

void dfs_check(int node) {
    if (gift[node] != node && gift[node] != gift[ dad[node] ])
        dead();

    for (int to : list[node])
        dfs_check(to);
}

void dfs(int node) {
    if (!used[gift[node]]) {
        ans.pb(gift[node]);
        used[gift[node]] = true;
    }

    for (int to : list[node])
        dfs(to);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) head[i] = true;

    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        dad[y] = x;

        head[y] = false;
    }

    for (i = 1; i <= n; i++) scanf("%d", &gift[i]);
    for (i = 1; i <= n; i++)
        if (head[i])
            dfs_check(i);

    for (i = 1; i <= n; i++)
        if (head[i])
            dfs(i);

    reverse(ans.begin(), ans.end());
    for (i = 1; i <= n; i++)
        if (!used[i])
            ans.pb(i);

    printf("%d\n", ans.size());
    for (auto e : ans)
        printf("%d\n", e);

    return 0;
}