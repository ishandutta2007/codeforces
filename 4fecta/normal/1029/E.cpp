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

int n, vis[MN], depth[MN], pre[MN];
vector<int> a[MN], v;

bool cmp(int x, int y) {
    return depth[x] > depth[y];
}

void dfs(int cur, int par, int d) {
    depth[cur] = d;
    pre[cur] = par;
    v.push_back(cur);
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur, d + 1);
    }
}

int main() {
    boost();

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0, 0);
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    for (int p : v) {
        if (depth[p] <= 2) break;
        if (vis[p]) continue;
        p = pre[p];
        vis[p] = 1;
        for (int nxt : a[p]) vis[nxt] = 1;
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}