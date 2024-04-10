#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, u, v, w; ll par[MN][2], sz[MN][2]; //valid pairs with start at i, last elem j
ll ans = 0;

int find(int x, int t) {
    if (par[x][t] == x) return par[x][t];
    return par[x][t] = find(par[x][t], t);
}

bool merge(int x, int y, int t) {
    x = find(x, t); y = find(y, t);
    if (x == y) return false;
    ans += 2 * sz[x][t] * sz[y][t];
    par[y][t] = par[x][t];
    sz[x][t] += sz[y][t];
    return true;
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) par[i][0] = par[i][1] = i, sz[i][0] = sz[i][1] = 1;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        merge(u, v, w);
    }
    for (int i = 1; i <= n; i++) ans += (sz[find(i, 0)][0] - 1) * (sz[find(i, 1)][1] - 1);
    printf("%lld\n", ans);

    return 0;
}