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

const int MN = 30005;

int n, d, u, val[MN], dp[MN][500];

int rec(int cur, int dist) {
    int msk = dist - d + 250;
    if (cur >= MN) return 0;
    if (dp[cur][msk] != -1) return dp[cur][msk];
    dp[cur][msk] = max(rec(cur + dist, dist), rec(cur + dist + 1, dist + 1)) + val[cur];
    if (dist > 1) dp[cur][msk] = max(dp[cur][msk], rec(cur + dist - 1, dist - 1) + val[cur]);
    return dp[cur][msk];
}

int main() {
    boost();

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> u;
        val[u]++;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(d, d));

    return 0;
}