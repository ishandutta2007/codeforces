#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)
#define mid ((l + r) / 2)

struct node {
    int open, closed, len;
};

const int MN = 1000005;

int n, q, l, r, a[MN];
string s;
node st[MN * 3];

node push_up(node x, node y) {
    int merge = min(x.open, y.closed);
    node ret;
    ret.open = x.open + y.open - merge;
    ret.closed = x.closed + y.closed - merge;
    ret.len = x.len + y.len + 2 * merge;
    return ret;
}

void build(int l, int r, int idx) {
    if (l == r) {
        if (a[l]) st[idx] = {1, 0, 0};
        else st[idx] = {0, 1, 0};
        return;
    }
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

void upd(int l, int r, int x, int idx) {
    if (l == r) {
        if (st[idx].open) st[idx] = {0, 1, 0};
        else st[idx] = {1, 0, 0};
        return;
    }
    if (x > mid) upd(mid + 1, r, x, idx * 2 + 1);
    else upd(l, mid, x, idx * 2);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

node qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return {0, 0, 0};
    if (r <= y && l >= x) return st[idx];
    return push_up(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int main() {
    boost();

    cin >> s >> q;
    n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') a[i + 1] = 1;
    }
    build(1, n, 1);
    for (; q > 0; q--) {
        cin >> l >> r;
        node ans = qry(1, n, l, r, 1);
        printf("%d\n", ans.len);
    }

    return 0;
}