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

const int MN = 100005, MK = 105;

int n, m, u, v, k, s, dist[MN], t[MN], vis[MN];
vector<int> a[MN], d[MN];

int main() {
    boost();

    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int type = 1; type <= k; type++) {
        queue<int> q;
        memset(dist, 0, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) if (t[i] == type) q.push(i), vis[i] = 1;
        while (q.size()) {
            int cur = q.front(); q.pop();
            for (int nxt : a[cur]) {
                if (vis[nxt]) continue;
                dist[nxt] = dist[cur] + 1;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
        for (int i = 1; i <= n; i++) d[i].push_back(dist[i]);
    }
    for (int i = 1; i <= n; i++) {
        sort(d[i].begin(), d[i].end());
        int ans = 0;
        for (int j = 0; j < s; j++) ans += d[i][j];
        printf("%d ", ans);
    }

    return 0;
}