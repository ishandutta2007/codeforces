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

struct node {
    int f, s, idx;
};

const int MN = 300005;

int n, m, u, v, ans[MN], psa[MN][2];
node seg[MN], ori[MN];
vector<int> a[MN];

bool cmp(node x, node y) {
    return x.f - x.s > y.f - y.s;
}

int mn(int i1, int i2) {
    return min(ori[i1].f + ori[i2].s, ori[i1].s + ori[i2].f);
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> u >> v;
        seg[i] = ori[i] = {u, v, i};
    }
    sort(seg + 1, seg + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        psa[i][0] = psa[i - 1][0] + seg[i].f;
        psa[i][1] = psa[i - 1][1] + seg[i].s;
        //printf("%d %d %d\n", seg[i].f, seg[i].s, seg[i].idx);
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        int cnt_l = i - 1, cnt_r = n - i;
        int sum_l = psa[i - 1][1], sum_r = psa[n][0] - psa[i][0];
        //printf("%d %d %d %d\n", cnt_l, cnt_r, sum_l, sum_r);
        ans[seg[i].idx] = sum_l + seg[i].f * cnt_l + sum_r + seg[i].s * cnt_r;
        for (int nxt : a[seg[i].idx]) {
            ans[seg[i].idx] -= mn(seg[i].idx, nxt);
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);

    return 0;
}