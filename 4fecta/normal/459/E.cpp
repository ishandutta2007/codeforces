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

struct edge {
    int u, v, w;
};

const int MN = 300005;

int n, m, u, v, w;
edge a[MN];
pair<pii, pii> dp[MN];

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 0; i < MN; i++) dp[i] = {{0, 0}, {0, 0}};
    for (int i = 0; i < m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a, a + m, cmp);
    for (int i = 0; i < m; i++) {
        u = a[i].u, v = a[i].v, w = a[i].w;
        if (dp[u].f.s < w && dp[v].f.f < dp[u].f.f + 1) {
            dp[v].s.f = dp[v].f.f, dp[v].s.s = dp[v].f.s;
            dp[v].f.f = dp[u].f.f + 1, dp[v].f.s = w;
        } else if (dp[v].f.f < dp[u].s.f + 1) {
            dp[v].s.f = dp[v].f.f, dp[v].s.s = dp[v].f.s;
            dp[v].f.f = dp[u].s.f + 1, dp[v].f.s = w;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i].f.f);
    printf("%d\n", ans);

    return 0;
}