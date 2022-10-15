#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 31;

int n, deg[MN];
vector<int> a[MN];
pii pos[MN], donk[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int cur, int par, int dir, int dist) {
    int d = (dir + 1) % 4;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        pos[nxt] = {pos[cur].f + donk[d].f * dist, pos[cur].s + donk[d].s * dist};
        dfs(nxt, cur, d + 2, dist >> 1);
        d = (d + 1) % 4;
    }
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u]++; deg[v]++;
        if (max(deg[u], deg[v]) > 4) return 0 * printf("NO\n");
    }
    dfs(1, 0, 0, 1LL << 32);
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%lld %lld\n", pos[i].f, pos[i].s);

    return 0;
}