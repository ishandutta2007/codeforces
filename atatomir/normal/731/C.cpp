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

int n, m, k, i, x, y;
int c[maxN];
vector<int> list[maxN];
bool us[maxN];

vector<int> aux;
int cnt[maxN];
int best;
int ans;

void dfs(int node) {
    us[node] = true;
    aux.pb(node);

    cnt[c[node]]++;
    if (cnt[c[node]] > cnt[best])
        best = c[node];

    for (int to : list[node]) {
        if (us[to]) continue;
        dfs(to);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;

        aux.clear();
        best = 0;

        dfs(i);

        ans += aux.size() - cnt[best];
        for (auto e : aux) cnt[c[e]] = 0;
    }

    printf("%d", ans);

    return 0;
}