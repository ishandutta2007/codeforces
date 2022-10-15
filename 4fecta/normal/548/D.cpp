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

const int MN = 200005, LOG = 20;

int n, a[MN], st[MN][LOG], ans[MN];

int mn(int l, int r) {
    int lvl = 31 - __builtin_clz(r - l + 1);
    return min(st[l][lvl], st[r - (1 << lvl) + 1][lvl]);
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], st[i][0] = a[i];
    for (int d = 1; d < 20; d++) {
        for (int i = 1; i <= n - (1 << d) + 1; i++) {
            st[i][d] = min(st[i][d - 1], st[i + (1 << (d - 1))][d - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = i;
        for (int j = LOG; j >= 0; j--) {
            int lft = l - (1 << j);
            if (lft < 1) continue;
            if (mn(lft, i) == a[i]) l = lft;
        }
        for (int j = LOG; j >= 0; j--) {
            int rit = r + (1 << j);
            if (rit > n) continue;
            if (mn(i, rit) == a[i]) r = rit;
        }
        ans[r - l + 1] = max(ans[r - l + 1], a[i]);
        //printf("%d %d\n", l, r);
    }
    int mx = 0;
    for (int i = n; i > 0; i--) {
        mx = max(mx, ans[i]);
        ans[i] = mx;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}