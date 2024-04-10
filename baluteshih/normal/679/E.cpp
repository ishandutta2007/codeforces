#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MAXC = 1e14;
ll pw42[10] = {1};

ll distance(ll k) {
    return *lower_bound(pw42, pw42 + 10, k) - k;
}

struct node {
    ll mx, mi, midis, lazy_add, lazy_md;
    node(ll k = 0): mx(k), mi(k), midis(distance(k)), lazy_add(0), lazy_md(0){}
    node operator+(const node &a) const {
        node rt;
        rt.mx = max(mx, a.mx);
        rt.mi = min(mi, a.mi);
        rt.midis = min(midis, a.midis);
        rt.lazy_add = rt.lazy_md = 0;
        return rt;
    }
} seg[400005];

int a[100005];

void give_tag_md(int rt, ll x) {
    seg[rt].lazy_add = 0;
    seg[rt].mx = seg[rt].mi = seg[rt].lazy_md = x;
    seg[rt].midis = distance(x); 
}

void give_tag_add(int rt, ll x) {
    seg[rt].lazy_add += x;
    seg[rt].mx += x;
    seg[rt].mi += x;
    seg[rt].midis -= x; 
}

void tag_down(int rt) {
    if (seg[rt].lazy_md != 0) {
        give_tag_md(rt << 1, seg[rt].lazy_md);
        give_tag_md(rt << 1 | 1, seg[rt].lazy_md);
        seg[rt].lazy_md = 0;
    }
    if (seg[rt].lazy_add != 0) {
        give_tag_add(rt << 1, seg[rt].lazy_add);
        give_tag_add(rt << 1 | 1, seg[rt].lazy_add);
        seg[rt].lazy_add = 0;
    }
}

void build(int l, int r, int rt) {
    if (l == r)
        return seg[rt] = node(a[l]), void();
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void modify(int L, int R, int l, int r, int rt, int x) {
    if (L <= l && R >= r)
        return give_tag_md(rt, x);
    if (l != r) tag_down(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) modify(L, R, l, mid, rt << 1, x);
    if (R > mid) modify(L, R, mid + 1, r, rt << 1 | 1, x);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void addition(int L, int R, int l, int r, int rt, int x) {
    if (L <= l && R >= r)
        return give_tag_add(rt, x);
    if (l != r) tag_down(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) addition(L, R, l, mid, rt << 1, x);
    if (R > mid) addition(L, R, mid + 1, r, rt << 1 | 1, x);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void release(int l, int r, int rt) {
    if (seg[rt].midis > 0) return;
    if (seg[rt].mx == seg[rt].mi)
        return give_tag_md(rt, seg[rt].mx);
    if (l != r) tag_down(rt);
    int mid = (l + r) >> 1;
    release(l, mid, rt << 1); 
    release(mid + 1, r, rt << 1 | 1); 
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

ll query(int x, int l, int r, int rt) {
    if (l == r)
        return seg[rt].mx;
    if (l != r) tag_down(rt);
    int mid = (l + r) >> 1;
    if (x <= mid) return query(x, l, mid, rt << 1);
    return query(x, mid + 1, r, rt << 1 | 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i < 10; ++i)
        pw42[i] = pw42[i - 1] * 42;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, n, 1);
    while (q--) {
        int k, l, r, x;
        cin >> k;
        if (k == 1)
            cin >> x, cout << query(x, 1, n, 1) << "\n";
        else if (k == 2)
            cin >> l >> r >> x, modify(l, r, 1, n, 1, x);
        else {
            cin >> l >> r >> x;
            do {
                addition(l, r, 1, n, 1, x);
                release(1, n, 1);
            } while (seg[1].midis == 0);
        }
    }
}