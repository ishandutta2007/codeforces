#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

struct state {
    ll ans;
    int best;
    map<int, int> M;

    state() {
        ans = best = 0;
        M.clear();
    }
};

int n, i, x, y;
int v[maxN], down[maxN];
vector<int> list[maxN];
state *dp[maxN];
bool us[maxN];
ll ans[maxN];

void add_to(state* act, int v, int cnt) {
    int new_cnt = (act->M[v] += cnt);

    if (act->best > new_cnt) return;
    if (act->best < new_cnt) act->ans = 0;

    act->best = max(act->best, new_cnt);
    act->ans += 1LL * v;
}

void dfs(int node) {
    int root = -1;

    us[node] = true;
    down[node] = 1;

    if (list[node].size() == 1 && us[list[node][0]]) {
        dp[node] = new state();
        add_to(dp[node], v[node], 1);
        ans[node] = v[node];
        return;
    }

    pair<int, int> best = {-1, -1};
    for (int to : list[node]) {
        if (us[to]) {root = to; continue;}

        dfs(to);
        down[node] += down[to];

        best = max(best, mp(down[to], to));
    }

    dp[node] = dp[best.second];
    add_to(dp[node], v[node], 1);

    for (int to : list[node]) {
        if (to == root || to == best.second) continue;

        for (auto e : dp[to]->M)
            add_to(dp[node], e.first, e.second);
    }

    ans[node] = dp[node]->ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    if (n == 1) {
        printf("%d", v[1]);
        return 0;
    }

    dfs(1);
    for (i = 1; i <= n; i++)
        printf("%lld ", ans[i]);


    return 0;
}