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

struct node {
    ll pre, suf, max, sum;
};

const int MN = 250005;

int n, m, k, u;
node a[MN], cmp[55], st[3 * MN];

node push_up(node x, node y) {
    node ret;
    ret.pre = max(x.pre, x.sum + y.pre);
    ret.suf = max(y.suf, y.sum + x.suf);
    ret.max = max(max(x.max, y.max), x.suf + y.pre);
    ret.sum = x.sum + y.sum;
    return ret;
}

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> u;
            a[j] = {u, u, u, u};
        }
        build(1, k, 1);
        cmp[i] = st[1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> u;
        a[i] = cmp[u];
    }
    build(1, m, 1);
    printf("%lld\n", st[1].max);

    return 0;
}