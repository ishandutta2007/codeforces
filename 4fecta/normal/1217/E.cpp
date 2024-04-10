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

struct node {
    int c[10][2]; //idx, smallest 2 nums with that set bit.
};

const int MN = 200005;

int n, m, t, l, r;
string a[MN], s;
node st[3 * MN], waste;

node push_up(node x, node y) {
    node ret = node();
    for (int i = 0; i < 9; i++) {
        if (x.c[i][0] < y.c[i][0]) {
            ret.c[i][0] = x.c[i][0];
            ret.c[i][1] = min(x.c[i][1], y.c[i][0]);
        } else {
            ret.c[i][0] = y.c[i][0];
            ret.c[i][1] = min(y.c[i][1], x.c[i][0]);
        }
    }
    return ret;
}

void build(int l, int r, int idx) {
    if (l == r) {
        for (int i = 0; i < 9; i++) {
            st[idx].c[i][0] = st[idx].c[i][1] = 0x3f3f3f3f;
            if (a[l][i] != '0') st[idx].c[i][0] = stoi(a[l]);
        }
        return;
    }
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

void upd(int l, int r, int x, string &val, int idx) {
    if (l == r) {
        for (int i = 0; i < 9; i++) {
            st[idx].c[i][0] = st[idx].c[i][1] = 0x3f3f3f3f;
            if (val[i] != '0') st[idx].c[i][0] = stoi(val);
        }
        return;
    }
    if (x <= mid) upd(l, mid, x, val, idx * 2);
    else upd(mid + 1, r, x, val, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

node qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return waste;
    if (r <= y && l >= x) return st[idx];
    return push_up(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int main() {
    boost();
    for (int i = 0; i < 9; i++) waste.c[i][0] = waste.c[i][1] = 0x3f3f3f3f;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (a[i].size() < 9) a[i] = "0" + a[i];
    }
    build(1, n, 1);
    while (m--) {
        cin >> t;
        if (t == 1) {
            cin >> l >> s;
            while (s.size() < 9) s = "0" + s;
            upd(1, n, l, s, 1);
        } else {
            cin >> l >> r;
            node tmp = qry(1, n, l, r, 1);
            int ans = INT_MAX;
            for (int i = 0; i < 9; i++) {
                if (tmp.c[i][1] == 0x3f3f3f3f) continue;
                ans = min(ans, tmp.c[i][0] + tmp.c[i][1]);
            }
            if (ans == INT_MAX) printf("-1\n");
            else printf("%d\n", ans);
        }
    }

    return 0;
}