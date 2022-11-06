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

const int maxN = 1000011;

int n, i, x, y, cnt;
vector<int> list[maxN], data[maxN];
int ans[maxN], id[maxN];

void solve(int node, int root) {
    pair<int, int> best = mp(0, 0);

    for (auto to : list[node]) {
        if (to == root) continue;
        solve(to, node);
        best = max(best, mp((int)data[ id[to] ].size(), to));
    }

    if (best == mp(0, 0)) {
        id[node] = ++cnt;
        data[ id[node] ] = {1};
        ans[node] = 0;
        return;
    }

    ans[node] = ans[best.second] + 1;
    id[node] = id[best.second];
    data[ id[node] ].pb(1);

    int sz = data[ id[node] ].size() - 1;
    if (data[ id[node] ][sz - ans[node]] == 1) ans[node] = 0;
   
    for (auto to : list[node]) {
        if (to == root || to == best.second) continue;
        
        data[ id[to] ].pb(0);

        for (int i = 0; i < data[ id[to] ].size(); i++) {
            data[ id[node] ][sz - i] += data[ id[to] ][ data[ id[to] ].size() - 1 - i ];
            if ( mp(data[ id[node] ][sz - i], -i) > mp(data[ id[node] ][ sz - ans[node] ], -ans[node]))
                ans[node] = i;
        }

        data[id[to]].clear();
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

    solve(1, 0);
    for (i = 1; i <= n; i++) printf("%d\n", ans[i]);

    return 0;
}