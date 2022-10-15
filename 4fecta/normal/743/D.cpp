#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, val[MN], u, v, sum[MN], mx[MN], ans = LLONG_MIN;
vector<int> a[MN];

void dfs(int cur, int par) {
    sum[cur] = val[cur];
    //if (a[cur].size() == 1) mx[cur] = val[cur];
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        sum[cur] += sum[nxt];
        mx[cur] = max(mx[cur], mx[nxt]);
    }
    mx[cur] = max(mx[cur], sum[cur]);
}

void calc(int cur, int par) {
    if (a[cur].size() > 2 || (cur == 1 && a[cur].size() > 1)) {
        vector<int> v;
        for (int nxt : a[cur]) {
            if (nxt == par) continue;
            v.push_back(mx[nxt]);
        }
        sort(v.begin(), v.end(), greater<int>());
        ans = max(ans, v[0] + v[1]);
        //printf("%d %d %d\n", cur, v[0], v[1]);
    }
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        calc(nxt, cur);
    }
}

int32_t main() {
    boost();

    memset(mx, -0x3f, sizeof(mx));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    calc(1, 0);
    if (ans == LLONG_MIN) printf("Impossible\n");
    else printf("%lld\n", ans);

    return 0;
}