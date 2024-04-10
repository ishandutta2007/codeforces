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

const int MN = 400005;

int n, k, dp[MN], bg[MN], st[3 * MN];
string s;

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = 1LL << 60;
        return;
    }
    build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
    st[idx] = min(st[idx * 2], st[idx * 2 + 1]);
}

void upd(int l, int r, int x, int val, int idx) {
    if (l == r) {
        st[idx] = val;
        return;
    }
    if (x <= mid) upd(l, mid, x, val, idx * 2);
    else upd(mid + 1, r, x, val, idx * 2 + 1);
    st[idx] = min(st[idx * 2], st[idx * 2 + 1]);
}

int qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return 1LL << 60;
    if (r <= y && l >= x) return st[idx];
    return min(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int32_t main() {
    boost();

    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) if (s[i - 1] == '1') bg[i + k] = 1;
    build(0, n + k, 1);
    upd(0, n + k, 0, 0, 1);
    for (int i = 1; i <= n + k; i++) {
        dp[i] = dp[i - 1] + i;
        if (bg[i]) {
            int l = max(0ll, i - 2 * k - 1), r = i - 1;
            dp[i] = min(dp[i], qry(0, n + k, l, r, 1) + i - k);
        }
        upd(0, n + k, i, dp[i], 1);
    }
    printf("%lld\n", qry(0, n + k, n, n + k, 1));

    return 0;
}