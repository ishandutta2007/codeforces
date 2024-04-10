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

const int MN = 200005;

int n, m, u, v, w, val[MN];
vector<pii> a[MN];

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        q.push({val[i], i});
    }
    while (q.size()) {
        pii p = q.top(); q.pop();
        if (p.f > val[p.s]) continue;
        int cur = p.s;
        for (pii nxt : a[cur]) {
            int o = val[nxt.f];
            val[nxt.f] = min(val[nxt.f], 2 * nxt.s + val[cur]);
            if (val[nxt.f] != o) q.push({val[nxt.f], nxt.f});
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", val[i]);
    printf("\n");

    return 0;
}