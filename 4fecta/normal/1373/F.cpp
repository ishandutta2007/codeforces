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

const int MN = 2000005;

int t, n, a[MN], b[MN], psa[2 * MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum1 += a[i];
        for (int i = 1; i <= n; i++) cin >> b[i], sum2 += b[i];
        for (int i = 1; i <= 4 * n; i++) {
            int idx = (i + 1) / 2;
            if (i > 2 * n) idx -= n;
            if (i % 2) psa[i] = -a[idx];
            else psa[i] = b[idx];
            //printf("%lld\n", psa[i]);
            psa[i] += psa[i - 1];
        }
        int mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
        for (int i = 1; i <= 4 * n; i++) {
            if (i % 2) mx = max(mx, psa[i]);
            else mn = min(mn, psa[i] - mx);
        }
        if (mn < 0 || sum1 > sum2) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}