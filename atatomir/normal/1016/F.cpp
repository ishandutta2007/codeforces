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

const int maxN = 300011;

int n, m, i, x, y, z, cnt;
vector< pair<int, int> > list[maxN];
vector<int> way, d;
bool on_way[maxN];
int last;
ll dist, aux;
ll down[maxN];

ll sum[maxN], sol;
ll best[maxN];
ll ans = -(1LL << 60);

void dfs(int node, int root) {
    way.pb(node);
    if (node == n) return;

    for (auto to : list[node]) {
        if (to.first == root) continue;

        dist += 1LL * to.second;
        d.pb(to.second);
        dfs(to.first, node);

        if (way.back() == n) return;

        dist -= 1LL * to.second;
        d.pop_back();
    }


    way.pop_back();
}

void dfs2(int node, int root) {
    for (auto to : list[node]) {
        if (to.first == root) continue;
        if (on_way[to.first]) continue;
        cnt++;
        last = to.second;
        dfs2(to.first, node);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));
    }

    dfs(1, 0);
    for (auto e : way) on_way[e] = true;

    for (auto e : way) {
        cnt = last = 0;
        dfs2(e, 0);
        down[e] = last;

        if (cnt > 1) {
            for (i = 1; i <= m; i++)
                printf("%lld\n", dist);
            return 0;
        }
    }

    sum[0] = 0;
    for (i = 1; i < way.size(); i++) sum[i] = sum[i - 1] + d[i - 1];

    best[0] = down[1];
    for (i = 1; i < way.size(); i++) {
        best[i] = max(best[i - 1], down[way[i]] + sum[i]);
    }

    for (i = 2; i < way.size(); i++) {
        ans = max(ans, down[way[i]] - sum[i] + best[i - 2]);
    }

    for (i = 1; i < way.size(); i++) {
        if (down[way[i - 1]] == 0 && down[way[i]] == 0) continue;
        ans = max(ans, down[way[i - 1]] + down[way[i]] - d[i - 1]);
    }

    for (i = 1; i <= m; i++) {
        scanf("%lld", &aux);
        sol = dist + min(0LL, ans + aux);
        printf("%lld\n", sol);
    }


    return 0;
}