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

const int MN = 50005;

int n, k, dp[MN][505], u, v;
vector<int> a[MN];
ll ans = 0;

void dfs(int cur, int par) {
    dp[cur][0] = 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        for (int i = 0; i <= k; i++) {
            ans += dp[cur][i] * dp[nxt][k - i];
            dp[cur][i] += dp[nxt][i];
        }
    }
    for (int i = k; i > 0; i--) dp[cur][i] = dp[cur][i - 1];
    dp[cur][0] = 0;
}

int main() {
    boost();

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0);
    printf("%lld\n", ans);

    return 0;
}