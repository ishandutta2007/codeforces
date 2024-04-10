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

int n, k, q, a[MN][5], t, u, l, r, up[5]; pii st[3 * MN][32];

void build(int l, int r, int idx, int msk) {
    if (l == r) {
        st[idx][msk] = {0, 0};
        for (int i = 0; i < k; i++) {
            if (msk & (1 << i)) st[idx][msk].f += a[l][i];
            else st[idx][msk].f -= a[l][i];
        }
        st[idx][msk].s = st[idx][msk].f;
        return;
    }
    build(l, mid, idx * 2, msk);
    build(mid + 1, r, idx * 2 + 1, msk);
    st[idx][msk] = {max(st[idx * 2][msk].f, st[idx * 2 + 1][msk].f), min(st[idx * 2][msk].s, st[idx * 2 + 1][msk].s)};
}

void upd(int l, int r, int x, int idx, int msk) {
    if (l == r) {
        st[idx][msk] = {0, 0};
        for (int i = 0; i < k; i++) {
            if (msk & (1 << i)) st[idx][msk].f += up[i];
            else st[idx][msk].f -= up[i];
        }
        st[idx][msk].s = st[idx][msk].f;
        return;
    }
    if (x <= mid) upd(l, mid, x, idx * 2, msk);
    else upd(mid + 1, r, x, idx * 2 + 1, msk);
    st[idx][msk] = {max(st[idx * 2][msk].f, st[idx * 2 + 1][msk].f), min(st[idx * 2][msk].s, st[idx * 2 + 1][msk].s)};
}

pii qry(int l, int r, int x, int y, int idx, int msk) {
    if (r < x || l > y) return {-0x3f3f3f3f, 0x3f3f3f3f};
    if (r <= y && l >= x) return st[idx][msk];
    pii p1 = qry(l, mid, x, y, idx * 2, msk); pii p2 = qry(mid + 1, r, x, y, idx * 2 + 1, msk);
    return {max(p1.f, p2.f), min(p1.s, p2.s)};
}

int main() {
    boost();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) cin >> a[i][j];
    }
    for (int msk = 0; msk < 1 << k; msk++) build(1, n, 1, msk);
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> l;
            for (int i = 0; i < k; i++) cin >> up[i];
            for (int msk = 0; msk < 1 << k; msk++) upd(1, n, l, 1, msk);
        }
        if (t == 2) {
            int ans = 0;
            cin >> l >> r;
            for (int msk = 0; msk < 1 << k; msk++) {
                pii p = qry(1, n, l, r, 1, msk);
                ans = max(ans, p.f - p.s);
                //printf("%d %d\n", p.f, p.s);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}