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

const int MN = 300005;

struct node {
    int min, gcd;
};

int n, a[MN];
node st[3 * MN];
vector<int> v;

int gcd(int a, int b) {
    if (a == 1 || b == 1) return 1;
    if (a == 0x3f3f3f3f) return b;
    if (b == 0x3f3f3f3f) return a;
    return b == 0 ? a : gcd(b, a % b);
}

node push_up(node x, node y) {
    node ret;
    ret.min = min(x.min, y.min);
    ret.gcd = gcd(x.gcd, y.gcd);
    return ret;
}

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx].min = st[idx].gcd = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

node qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return {INT_MAX, 0x3f3f3f3f};
    if (r <= y && l >= x) return st[idx];
    int mid = (l + r) >> 1;
    return push_up(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

bool check(int len) {
    int l = 1, r = l + len;
    for (; r <= n; l++, r++) {
        node ans = qry(1, n, l, r, 1);
        if (ans.min == ans.gcd) return 1;
    }
    return 0;
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    int lo = 0, hi = n - 1, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        mid += (lo + hi) & 1;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    int l = 1, r = l + lo, cnt = 0;
    for (; r <= n; l++, r++) {
        node ans = qry(1, n, l, r, 1);
        if (ans.min == ans.gcd) v.push_back(l), cnt++;
    }
    printf("%d %d\n", cnt, lo);
    for (int i : v) printf("%d ", i);

    return 0;
}