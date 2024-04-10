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

int n, vis[MN], hvy[MN];
vector<int> a[MN];

void dfs(int cur, int par) {
    if (a[cur].size() > 2) return;
    vis[cur] = 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
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
    for (int i = 1; i <= n; i++) if (a[i].size() == 1) dfs(i, 0);
    for (int i = 1; i <= n; i++) for (int nxt : a[i]) if (vis[nxt]) hvy[i]++, hvy[i] = min(hvy[i], 2);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cnt = 0;
        for (int nxt : a[i]) {
            if (vis[nxt]) continue;
            if (a[nxt].size() - hvy[nxt] > 1) cnt++;
        }
        if (cnt > 2) return 0 * printf("No\n");
    }
    printf("Yes\n");

    return 0;
}