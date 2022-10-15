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

const int MN = 200005;

int n, u, v, dp[MN], delta[MN];
vector<pii> a[MN];

void dfs(int cur, int par) {
    for (pii nxt : a[cur]) {
        if (nxt.f == par) continue;
        dfs(nxt.f, cur);
        dp[cur] += dp[nxt.f];
        if (!nxt.s) dp[cur]++;
    }
    int sum = dp[cur];
    for (pii nxt : a[cur]) {
        if (nxt.f == par) continue;
        delta[nxt.f] += sum - dp[nxt.f];
        if (nxt.s) delta[nxt.f]++;
        else delta[nxt.f]--;
    }
}

void dfs(int cur, int par, int sum) {
    sum += delta[cur];
    dp[cur] += sum;
    for (pii nxt : a[cur]) {
        if (nxt.f == par) continue;
        dfs(nxt.f, cur, sum);
    }
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back({v, 1});
        a[v].push_back({u, 0});
    }
    dfs(1, 0);
    dfs(1, 0, 0);
    int mn = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, dp[i]);
    }
    printf("%d\n", mn);
    for (int i = 1; i <= n; i++) {
        if (dp[i] == mn) printf("%d ", i);
    }

    return 0;
}
/*
 9
 1 4
 1 3
 2 1
 9 3
 4 8
 5 2
 2 6
 7 6
 */