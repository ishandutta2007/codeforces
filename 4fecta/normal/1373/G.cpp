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

const int MN = 400005, N = 400000;

int n, m, k, x, y, st[6 * MN], lzy[6 * MN];
multiset<int> s;
set<pii> pts;

void push_down(int idx) {
    if (!lzy[idx]) return;
    st[idx] += lzy[idx];
    lzy[idx * 2] += lzy[idx];
    lzy[idx * 2 + 1] += lzy[idx];
    lzy[idx] = 0;
}

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = l - n - 1;
        return;
    }
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx] = max(st[idx * 2], st[idx * 2 + 1]);
}

void upd(int l, int r, int x, int y, int val, int idx) {
    push_down(idx);
    if (r < x || l > y) return;
    if (r <= y && l >= x) {
        st[idx] += val;
        lzy[idx * 2] += val;
        lzy[idx * 2 + 1] += val;
        return;
    }
    upd(l, mid, x, y, val, idx * 2);
    upd(mid + 1, r, x, y, val, idx * 2 + 1);
    st[idx] = max(st[idx * 2], st[idx * 2 + 1]);
}

int qry(int l, int r, int x, int y, int idx) {
    push_down(idx);
    if (r < x || l > y) return -0x3f3f3f3f;
    if (r <= y && l >= x) return st[idx];
    return max(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int main() {
    boost();

    cin >> n >> k >> m;
    build(1, N, 1);
    while (m--) {
        cin >> x >> y;
        int pos = abs(x - k) + y;
        if (pts.count({x, y})) {
            pts.erase({x, y});
            s.erase(s.find(pos));
            upd(1, N, 1, pos, -1, 1);
        } else {
            pts.insert({x, y});
            s.insert(pos);
            upd(1, N, 1, pos, 1, 1);
        }
        if (s.size()) printf("%d\n", max(0, qry(1, N, 1, *s.rbegin(), 1)));
        else printf("0\n");
    }

    return 0;
}