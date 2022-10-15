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

int n, m, val[MN], in[MN], out[MN], bit[2 * MN][2], u, v, t, x, id = 1, depth[MN];
vector<int> a[MN];

int qry(int x, int t) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i][t];
    return ret;
}

void upd(int x, int val, int t) {
    for (int i = x; i < 2 * MN; i += i & -i) bit[i][t] += val;
}

void dfs(int cur, int par) {
    depth[cur] = depth[par] + 1;
    in[cur] = id++;
    for (int nxt : a[cur]) if (nxt != par) dfs(nxt, cur);
    out[cur] = id++;
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    for (; m > 0; m--) {
        cin >> t;
        if (t == 1) {
            cin >> x >> v;
            if (depth[x] % 2) {
                upd(in[x], v, 1); upd(out[x] + 1, -v, 1);
                upd(in[x], -v, 0); upd(out[x] + 1, v, 0);
            } else {
                upd(in[x], v, 0); upd(out[x] + 1, -v, 0);
                upd(in[x], -v, 1); upd(out[x] + 1, v, 1);
            }
        } else {
            cin >> x;
            if (depth[x] % 2) printf("%lld\n", val[x] + qry(in[x], 1));
            else printf("%lld\n", val[x] + qry(in[x], 0));
        }
    }

    return 0;
}