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

int n, a[MN], idx[MN], st[MN][LOG], ans = 0;

int qry(int l, int r) {
    int lvl = 31 - __builtin_clz(r - l + 1);
    return max(st[l][lvl], st[r - (1 << lvl) + 1][lvl]);
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], idx[a[i]] = i, st[i][0] = a[i];
    for (int d = 1; d < LOG; d++) {
        for (int i = 1; i <= n - (1 << d) + 1; i++) {
            st[i][d] = max(st[i][d - 1], st[i + (1 << (d - 1))][d - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = i;
        for (int s = LOG - 1; s >= 0; s--) {
            if (l - (1 << s) < 0) continue;
            if (qry(l - (1 << s), i) == a[i]) l -= (1 << s);
        }
        for (int s = LOG - 1; s >= 0; s--) {
            if (r + (1 << s) > n) continue;
            if (qry(i, r + (1 << s)) == a[i]) r += (1 << s);
        }
        if (r - i < i - l) {
            for (int j = i + 1; j <= r; j++) {
                if (idx[a[i] - a[j]] < i && idx[a[i] - a[j]] >= l) ans++;
            }
        } else {
            for (int j = i - 1; j >= l; j--) {
                if (idx[a[i] - a[j]] > i && idx[a[i] - a[j]] <= r) ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}