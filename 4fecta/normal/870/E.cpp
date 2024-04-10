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

const int MN = 100005, MOD = 1e9 + 7;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p % 2) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int n, x, y, ans = 1;
set<int> s;
map<int, vector<int>> mp;

void dfs(int p, int &nodes, int &edges) {
    s.erase(p);
    nodes++;
    for (int nxt : mp[p]) {
        edges++;
        if (s.count(nxt)) dfs(nxt, nodes, edges);
    }
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        x *= 2, y *= 2, y++;
        s.insert(x), s.insert(y);
        mp[x].push_back(y), mp[y].push_back(x);
    }
    while (s.size()) {
        int p = *s.begin();
        int nodes = 0, edges = 0;
        dfs(p, nodes, edges);
        //printf("%d %d\n", nodes, edges);
        if (nodes * 2 - 2 == edges) ans *= fpow(2, nodes) - 1, ans %= MOD; //tree
        else ans *= fpow(2, nodes), ans %= MOD;
    }
    printf("%lld\n", ans);

    return 0;
}