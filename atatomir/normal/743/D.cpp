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
#define inf (1LL << 55)

int n, i, x, y;
ll val[maxN], best[maxN];
vector<int> list[maxN];
ll ans = -inf;

void dfs(int node, int root) {
    best[node] = -inf;
    for (auto to : list[node]) {
        if (to == root) continue;
        dfs(to, node);
        val[node] += val[to];
        best[node] = max(best[node], best[to]);
    }

    best[node] = max(best[node], val[node]);
}

void solve(int node, int root, ll up) {
    ans = max(ans, val[node] + up);

    for (int i = 0; i < list[node].size(); i++) {
        if (list[node][i] == root) {
            list[node][i] = list[node].back();
            list[node].pop_back();
            break;
        }
    }

    sort(list[node].begin(), list[node].end(), [](const int a, const int b)->bool const {
        return best[a] > best[b];
    });

    if (list[node].size() == 0) return;
    if (list[node].size() == 1) {
        solve(list[node][0], node, up);
        return;
    }

    solve(list[node][0], node, max(up, best[list[node][1]]));
    for (int i = 1; i < list[node].size(); i++)
        solve(list[node][i], node, max(up, best[list[node][0]]));
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &val[i]);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1, 0);
    solve(1, 0, -4 * inf);

    if (ans <= -inf) {
        printf("Impossible");
    } else {
        printf("%lld", ans);
    }


    return 0;
}