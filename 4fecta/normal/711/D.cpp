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

const int MN = 200005, MOD = 1e9 + 7;

int n, u, vis[MN], pow2[MN], dist[MN], num = 1, cmp[MN];
vector<int> a[MN];
ll ans = 1;
int rem;

void dfs(int cur, int d) {
    if (cmp[cur] && cmp[cur] != num) return;
    cmp[cur] = num;
    if (vis[cur]) {
        int len = d - dist[cur];
        rem -= len;
        //printf("%d\n", len);
        ans *= (pow2[len] - 2 + MOD) % MOD;
        ans %= MOD;
        return;
    }
    vis[cur] = true;
    dist[cur] = d;
    for (int nxt : a[cur]) {
        dfs(nxt, d + 1);
    }
}

int main() {
    boost();

    pow2[0] = 1;
    for (int i = 1; i < MN; i++) pow2[i] = pow2[i - 1] * 2 % MOD;

    cin >> n;
    rem = n;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        a[i].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, 0);
        num++;
    }
    ans *= pow2[rem];
    printf("%lld\n", ans % MOD);

    return 0;
}