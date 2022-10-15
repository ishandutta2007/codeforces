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

const int MN = 100005;

int n, k, u, v, m, vis[MN], depth[MN], pre[MN];
vector<int> a[MN], ans;

void collect(int cur, int par) {
    ans.push_back(cur);
    if (cur == par) return;
    collect(pre[cur], par);
}

void dfs(int cur, int par, int d) {
    depth[cur] = d;
    vis[cur] = 1;
    pre[cur] = par;
    int best = 0;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        if (vis[nxt]) if (depth[nxt] >= depth[best]) best = nxt;
    }
    if (best) {
        collect(cur, best);
        if (ans.size() <= k) {
            printf("2\n%llu\n", ans.size());
            for (int p : ans) printf("%d ", p);
        } else {
            printf("1\n");
            for (int i = 0; i < (k + 1) / 2 * 2; i += 2) printf("%d ", ans[i]);
        }
        exit(0);
    }
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur, d + 1);
    }
}

void dfs(int cur, int par) {
    pre[cur] = par;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
    }
    if (!vis[cur]) ans.push_back(cur), vis[pre[cur]] = 1;
}

int main() {
    boost();

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if (m >= n) dfs(1, 0, 0);
    else dfs(1, 0);
    printf("1\n");
    for (int i = 0; i < (k + 1) / 2; i++) printf("%d ", ans[i]);

    return 0;
}