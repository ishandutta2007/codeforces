#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)
#define mid ((l + r) / 2)

struct node {
    int min, max, ok;
};

const int MN = 400005;

int n, m, q, r, c;
set<int> lft[MN], rit[MN];
node st[3 * MN];

node push_up(node x, node y) {
    return {min(x.min, y.min), max(x.max, y.max), x.ok && y.ok && x.min > y.max};
}

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = {0x3f3f3f3f, 0, 1};
        return;
    }
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

void upd(int l, int r, int x, int val, int t, int idx) {
    if (l == r) {
        if (t) st[idx].max = val;
        else st[idx].min = val;
        st[idx].ok = st[idx].max < st[idx].min;
        return;
    }
    if (x <= mid) upd(l, mid, x, val, t, idx * 2);
    else upd(mid + 1, r, x, val, t, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

int32_t main() {
    boost();

    cin >> n >> m >> q;
    build(1, n, 1);
    while (q--) {
        cin >> r >> c;
        bool up = r % 2;
        r = (r + 1) / 2, c = (c + 1) / 2;
        //printf("%d %d\n", r, c);
        if (up) {
            if (lft[r].count(c)) lft[r].erase(c);
            else lft[r].insert(c);
            int val = lft[r].empty() ? 0x3f3f3f3f : *lft[r].begin();
            upd(1, n, r, val, 0, 1);
        } else {
            if (rit[r].count(c)) rit[r].erase(c);
            else rit[r].insert(c);
            int val = rit[r].empty() ? 0 : *rit[r].rbegin();
            upd(1, n, r, val, 1, 1);
        }
        if (st[1].ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}