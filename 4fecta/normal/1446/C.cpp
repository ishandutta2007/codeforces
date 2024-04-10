#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

int n, a[MN], ans = 0x3f3f3f3f;
map<int, int> tr[32];

void dfs(int lvl, int key, int cost) {
    if (lvl <= 0 || (lvl <= 30 && tr[lvl][key] <= 2)) {
        ans = min(ans, cost);
        return;
    }
    if (tr[lvl - 1][key << 1 | 1] > 0) dfs(lvl - 1, key << 1 | 1, cost + max(0ll, tr[lvl - 1][key << 1] - 1));
    if (tr[lvl - 1][key << 1] > 0) dfs(lvl - 1, key << 1, cost + max(0ll, tr[lvl - 1][key << 1 | 1] - 1));
}

int32_t main() {
    boost();

    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
        for (int s = 0; s <= 30; s++) tr[s][a[i] >> s]++;
    }
    dfs(31, 0, 0);
    printf("%lld\n", ans);

    return 0;
}