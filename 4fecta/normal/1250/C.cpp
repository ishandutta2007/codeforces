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
#define mid ((l + r) / 2)

const int MN = 200005;

int n, a[MN], q, l, r;
ordered_set st[3 * MN];

void build(int l, int r, int idx) {
    for (int i = l; i <= r; i++) st[idx].insert(i);
    if (l == r) return;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
}

void upd(int l, int r, int x, int val, int idx) {
    st[idx].erase(a[x]);
    if (l == r) return;
    if (x <= mid) upd(l, mid, x, val, idx * 2);
    else upd(mid + 1, r, x, val, idx * 2 + 1);
}

void upd1(int l, int r, int x, int val, int idx) {
    st[idx].insert(val);
    if (l == r) return;
    if (x <= mid) upd1(l, mid, x, val, idx * 2);
    else upd1(mid + 1, r, x, val, idx * 2 + 1);
}

int qry(int l, int r, int x, int y, int val, int idx) {
    if (r < x || l > y || r < l) return 0;
    if (r <= y && l >= x) return st[idx].order_of_key(val);
    return qry(l, mid, x, y, val, idx * 2) + qry(mid + 1, r, x, y, val, idx * 2 + 1);
}

int main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i <= n; i++) a[i] = i;
    build(1, n, 1);
    ll ans = 0;
    for (; q > 0; q--) {
        cin >> l >> r;
        if (l > r) swap(l, r);
        if (l == r) {printf("%lld\n", ans); continue;}
        ans -= qry(1, n, l + 1, r, a[l], 1);
        ans += r - l - qry(1, n, l + 1, r, a[l], 1);
        if (r - l > 1) {
            ans += qry(1, n, l + 1, r - 1, a[r], 1);
            ans -= r - l - 1 - qry(1, n, l + 1, r - 1, a[r], 1);
        }
        upd(1, n, l, a[r], 1); upd(1, n, r, a[l], 1);
        upd1(1, n, l, a[r], 1); upd1(1, n, r, a[l], 1);
        swap(a[l], a[r]);
        printf("%lld\n", ans);
    }

    return 0;
}