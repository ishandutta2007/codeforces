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
#define maxLog 19

int n, i, j, x;
ll a[maxN], c;
vector< pair<int, ll> > list[maxN];
int dad[maxLog][maxN];

ll lvl[maxN];
int ans[maxN];

void dfs(int node) {
    for (auto to : list[node]) {
        lvl[to.first] = lvl[node] + to.second;
        dfs(to.first);
    }
}

void dfs2(int node) {
    for (auto to : list[node]) {
        dfs2(to.first);
        ans[node] += ans[to.first];
    }
}

int get_last(int node) {
    int ans = node;

    for (int i = maxLog - 1; i >= 0; i--)
        if (lvl[node] - lvl[ dad[i][ans] ] <= a[node])
            ans = dad[i][ans];

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (i = 2; i <= n; i++) {
        scanf("%d%lld", &x, &c);
        list[x].pb(mp(i, c));
        dad[0][i] = x;
    }

    for (i = 1; i < maxLog; i++)
        for (j = 1; j <= n; j++)
            dad[i][j] = dad[i - 1][dad[i - 1][j]];

    lvl[0] = - 1LL << 50;
    dfs(1);

    for (i = 1; i <= n; i++) {
        ans[dad[0][i]]++;
        ans[dad[0][get_last(i)]]--;
    }

    dfs2(1);
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}