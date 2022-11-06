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
vector<int> list[maxN], from[maxN];
vector<int> aux, who;
bool us[maxN];
int sz;
int ans;

bool cycl[maxN];
bool any;


void dfs(int node) {
    us[node] = true;
    for (int to : list[node])
        if (!us[to])
            dfs(to);
    aux.pb(node);
}

void dfs2(int node) {
    us[node] = true;
    who.pb(node);
    sz++;
    for (int to : from[node])
        if (!us[to])
            dfs2(to);
}

void dfs3(int node) {
    us[node] = true;
    sz++;
    any |= cycl[node];
    for (int to : from[node])
        if (!us[to])
            dfs3(to);
    for (int to : list[node])
        if (!us[to])
            dfs3(to);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        from[y].pb(x);
    }

    for (i = 1; i <= n; i++)
        if (!us[i])
            dfs(i);

    memset(us, 0, sizeof(us));
    reverse(aux.begin(), aux.end());

    for (auto i : aux) {
        if (us[i]) continue;
        sz = 0;
        who.clear();
        dfs2(i);

        if (sz > 1)
            for (auto e : who)
                cycl[e] = true;
    }

    memset(us, 0, sizeof(us));
    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        any = false;
        sz = 0;

        dfs3(i);

        if (any)
            ans += sz;
        else
            ans += sz - 1;
    }

    printf("%d", ans);


    return 0;
}