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

const int MN = 500005;

int n, k, d, bit[MN], a[MN], dp[MN];

void upd(int x, int val) {
    x++;
    for (int i = x; i < MN; i += i & -i) bit[i] += val;
}

int qry(int x) {
    int ret = 0;
    x++;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

int32_t main() {
    boost();

    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[0] = -0x3f3f3f3f; dp[0] = 1;
    upd(0, 1);
    for (int i = 1; i <= n; i++) {
        int rit = i - k;
        int lo = 1, hi = i, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (a[mid] < a[i] - d) lo = mid + 1;
            else hi = mid;
        }
        int lft = lo - 1;
        if (lft > rit || qry(rit) == qry(lft - 1)) continue;
        dp[i] = 1;
        upd(i, 1);
    }
    if (dp[n]) printf("YES\n");
    else printf("NO\n");

    return 0;
}