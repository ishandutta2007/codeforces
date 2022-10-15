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

struct node {
    int v, d, i;
};

int n, m, u, v, dp[MN], ans = 0;
vector<node> a[MN];

void dfs(int cur, int lim) {
    dp[cur] = 0;
    for (node nxt : a[cur]) {
        if (nxt.d == 0 || nxt.i > lim) continue;
        if (dp[nxt.v] == -1) dfs(nxt.v, lim);
        dp[cur] = max(dp[cur], dp[nxt.v] + 1);
    }
    ans = max(ans, dp[cur]);
}

bool check(int lim) {
    memset(dp, -1, sizeof(dp));
    ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == -1) dfs(i, lim);
    }
    //printf("%d %d %d\n", lim, d1, d2);
    return ans >= n - 1;
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back({v, 1, i});
        a[v].push_back({u, 0, i});
    }
    int lo = 1, hi = m + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%d\n", lo == m + 1 ? -1 : lo);

    return 0;
}