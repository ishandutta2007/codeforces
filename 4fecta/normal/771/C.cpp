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

int n, k, sub[MN], dp[MN][10], tmp[MN][10], ans;
vector<int> a[MN];

int cmp(int x) {
    if (x % k == 0) return 0;
    return k - (x % k);
}

void dfs(int cur, int par) {
    sub[cur] = 1;
    dp[cur][0] = 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        sub[cur] += sub[nxt];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int len = (i + j + 2) % k;
                int cnt = dp[nxt][i] * tmp[cur][j];
                ans += cmp(len) * cnt;
            }
        }
        for (int i = 0; i < k; i++) dp[cur][(i + 1) % k] += dp[nxt][i], tmp[cur][i] += dp[nxt][i];
    }
    ans += sub[cur] * (n - sub[cur]);
    for (int i = 0; i < k; i++) ans += cmp(i) * dp[cur][i];
}

int32_t main() {
    boost();

    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n", ans / k);

    return 0;
}