#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct node {
    int sum, pref, npre, nsuf, ppre, psuf, min, max;
};

node push_up(node p, node q) {
    node ret;
    ret.sum = p.sum + q.sum;
    ret.pref = max(p.pref, p.sum + q.pref);
    ret.npre = min(p.npre, p.sum + q.npre);
    //if (p.sum == p.npre) ret.npre = p.sum + q.npre;
    ret.nsuf = min(q.nsuf, q.sum + p.nsuf);
    //if (q.sum == q.nsuf) ret.nsuf = q.sum + p.nsuf;
    ret.ppre = max(p.ppre, p.sum + q.ppre);
    //if (p.sum == p.ppre) ret.ppre = p.sum + q.ppre;
    ret.psuf = max(q.psuf, q.sum + p.psuf);
    //if (q.sum == q.psuf) ret.psuf = q.sum + p.psuf;
    ret.min = min({p.min, q.min, p.nsuf + q.npre});
    ret.max = max({p.max, q.max, p.psuf + q.ppre});
    return ret;
}

const int MN = 100005;

int n, a[MN], b[MN], q, l, r;
node st[MN * 4];

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = {a[l], max(0ll, a[l]), min(0ll, a[l]), min(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), min(0ll, a[l]),
                   max(0ll, a[l])};
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

node qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return {0, 0, 0, 0, 0, 0, 0, 0};
    if (r <= y && l >= x) return st[idx];
    int mid = (l + r) >> 1;
    return push_up(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int32_t main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], a[i] -= b[i];
    build(1, n, 1);
    while (q--) {
        cin >> l >> r;
        node tmp = qry(1, n, l, r, 1);
        if (tmp.sum != 0 || tmp.pref > 0) printf("-1\n");
        else printf("%lld\n", max(tmp.max, -tmp.min));
    }

    return 0;
}