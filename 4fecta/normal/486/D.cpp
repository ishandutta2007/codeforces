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

const int MN = 2005, MOD = 1e9 + 7;

int n, d, u, v, val[MN];
bool in[MN];
vector<int> a[MN];
ll ans = 0;

void dfs(int cur, int par, int rt) {
    in[cur] = 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        if (val[nxt] < val[rt] || val[nxt] > val[rt] + d) continue;
        if (val[nxt] == val[rt] && nxt < rt) continue;
        dfs(nxt, cur, rt);
    }
}

ll count(int cur, int par) {
    ll ret = 1;
    for (int nxt : a[cur]) {
        if (nxt == par || !in[nxt]) continue;
        ret *= count(nxt, cur) + 1;
        ret %= MOD;
    }
    return ret;
}

int main() {
    boost();

    cin >> d >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        memset(in, 0, sizeof(in));
        dfs(i, 0, i);
        ans += count(i, 0);
        ans %= MOD;
    }
    printf("%lld\n", ans);

    return 0;
}