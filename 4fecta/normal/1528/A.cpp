#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int n, u, v, l[MN], r[MN], dp[MN][2];
vector<int> a[MN];

void dfs(int cur, int par) {
    dp[cur][0] = dp[cur][1] = 0;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        dp[cur][0] += max(abs(l[cur] - l[nxt]) + dp[nxt][0], abs(l[cur] - r[nxt]) + dp[nxt][1]);
        dp[cur][1] += max(abs(r[cur] - l[nxt]) + dp[nxt][0], abs(r[cur] - r[nxt]) + dp[nxt][1]);
    }
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1, 0);
        printf("%lld\n", max(dp[1][0], dp[1][1]));
        for (int i = 1; i <= n; i++) a[i].clear();
    }

    return 0;
}