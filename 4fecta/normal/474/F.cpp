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

const int MN = 100005;

struct node {
    int cnt, gcd, min;
};

int n, a[MN], q, l, r;
node st[3 * MN];

node push_up(node x, node y) {
    if (x.cnt == -1) return y;
    if (y.cnt == -1) return x;
    node ret;
    ret.gcd = __gcd(x.gcd, y.gcd);
    ret.min = min(x.min, y.min);
    if (x.min < y.min) ret.cnt = x.cnt;
    else if (x.min > y.min) ret.cnt = y.cnt;
    else ret.cnt = x.cnt + y.cnt;
    return ret;
}

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = {1, a[l], a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

node qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return {-1, -1 -1};
    if (r <= y && l >= x) return st[idx];
    int mid = (l + r) >> 1;
    return push_up(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    cin >> q;
    while (q--) {
        cin >> l >> r;
        node tmp = qry(1, n, l, r, 1);
        if (tmp.min == tmp.gcd) printf("%d\n", r - l + 1 - tmp.cnt);
        else printf("%d\n", r - l + 1);
    }

    return 0;
}