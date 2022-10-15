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
#define mid ((l + r) / 2)

const int MN = 100005;

int n, m, l, r, x, t, a[MN], st[4 * MN][22], lzy[4 * MN][22];

void push_down(int l, int r, int idx, int s) {
    if (!lzy[idx][s]) return;
    st[idx][s] = r - l + 1 - st[idx][s];
    if (l ^ r) {
        lzy[idx * 2][s] ^= 1;
        lzy[idx * 2 + 1][s] ^= 1;
    }
    lzy[idx][s] = 0;
}

void build(int l, int r, int idx, int s) {
    if (l == r) {
        if (a[l] & (1 << s)) st[idx][s] = 1;
        else st[idx][s] = 0;
        return;
    }
    build(l, mid, idx * 2, s);
    build(mid + 1, r, idx * 2 + 1, s);
    st[idx][s] = st[idx * 2][s] + st[idx * 2 + 1][s];
}

void upd(int l, int r, int x, int y, int idx, int s) {
    push_down(l, r, idx, s);
    if (r < x || l > y) return;
    if (r <= y && l >= x) {
        st[idx][s] = r - l + 1 - st[idx][s];
        if (l ^ r) {
            lzy[idx * 2][s] ^= 1;
            lzy[idx * 2 + 1][s] ^= 1;
        }
        return;
    }
    upd(l, mid, x, y, idx * 2, s);
    upd(mid + 1, r, x, y, idx * 2 + 1, s);
    st[idx][s] = st[idx * 2][s] + st[idx * 2 + 1][s];
}

int qry(int l, int r, int x, int y, int idx, int s) {
    push_down(l, r, idx, s);
    if (r < x || l > y) return 0;
    if (r <= y && l >= x) return st[idx][s] << s;
    return qry(l, mid, x, y, idx * 2, s) + qry(mid + 1, r, x, y, idx * 2 + 1, s);
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= 20; i++) build(1, n, 1, i);
    cin >> m;
    for (; m > 0; m--) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r;
            int ret = 0;
            for (int i = 0; i <= 20; i++) ret += qry(1, n, l, r, 1, i);
            printf("%lld\n", ret);
        }
        if (t == 2) {
            cin >> l >> r >> x;
            for (int i = 0; i <= 20; i++) {
                if (x & (1 << i)) upd(1, n, l, r, 1, i);
            }
        }
    }

    return 0;
}