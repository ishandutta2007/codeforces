#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)
#define mid ((l + r) / 2)

struct node {
    int omin, ocnt, emin, ecnt;
};

const int MN = 300005;

int t, n, a[MN], lzy[MN * 4];
node st[MN * 4];

node push_up(node p, node q) {
    node ret;
    if (p.omin < q.omin) ret.omin = p.omin, ret.ocnt = p.ocnt;
    else if (p.omin > q.omin) ret.omin = q.omin, ret.ocnt = q.ocnt;
    else ret.omin = p.omin, ret.ocnt = p.ocnt + q.ocnt;
    if (p.emin < q.emin) ret.emin = p.emin, ret.ecnt = p.ecnt;
    else if (p.emin > q.emin) ret.emin = q.emin, ret.ecnt = q.ecnt;
    else ret.emin = p.emin, ret.ecnt = p.ecnt + q.ecnt;
    return ret;
}

void push_down(int l, int r, int idx) {
    if (!lzy[idx]) return;
    st[idx].omin += lzy[idx];
    st[idx].emin -= lzy[idx];
    if (l != r) lzy[idx * 2] += lzy[idx], lzy[idx * 2 + 1] += lzy[idx];
    lzy[idx] = 0;
}

void build(int l, int r, int idx) {
    lzy[idx] = 0;
    if (l == r) {
        if (l & 1) st[idx] = {0, 1, (int) 1e18, 0};
        else st[idx] = {(int) 1e18, 0, 0, 1};
        return;
    }
    build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

void upd(int l, int r, int x, int y, int val, int idx) {
    push_down(l, r, idx);
    if (r < x || l > y) return;
    if (r <= y && l >= x) {
        lzy[idx] += val;
        push_down(l, r, idx);
        return;
    }
    upd(l, mid, x, y, val, idx * 2), upd(mid + 1, r, x, y, val, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

node qry(int l, int r, int x, int y, int idx) {
    push_down(l, r, idx);
    if (r < x || l > y) return {(int) 1e18, 0, (int) 1e18, 0};
    if (r <= y && l >= x) return st[idx];
    return push_up(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int noneg(int l, int r, int idx) {
    push_down(l, r, idx);
    if (l == r) {
        if ((st[idx].omin < 0 && st[idx].ocnt > 0) || (st[idx].emin < 0 && st[idx].ecnt > 0)) {
            return -0x3f3f3f3f;
        } else {
            return l;
        }
    }
    push_down(l, mid, idx * 2);
    if (!(st[idx * 2].omin < 0 && st[idx * 2].ocnt > 0) && !(st[idx * 2].emin < 0 && st[idx * 2].ecnt > 0)) {
        return max(mid, noneg(mid + 1, r, idx * 2 + 1));
    } else return noneg(l, mid, idx * 2);
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        build(1, n, 1);
        int ans = 0;
        for (int i = n; i > 0; i--) {
            if (i & 1) upd(1, n, i, n, a[i], 1);
            else upd(1, n, i, n, -a[i], 1);
            int lo = noneg(1, n, 1);
            node tmp = qry(1, n, i, lo, 1);
            if (tmp.omin == 0) ans += tmp.ocnt;
            if (tmp.emin == 0) ans += tmp.ecnt;
        }
        printf("%lld\n", ans);
    }

    return 0;
}