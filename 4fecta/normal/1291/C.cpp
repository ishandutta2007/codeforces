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

const int MN = 3505;

int t, n, m, k, a[MN], pre[MN], suf[MN];
vector<int> vals;

int main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        k = min(k, m - 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = max(pre[i - 1], a[i]);
        }
        for (int i = n; i > 0; i--) suf[i] = max(suf[i + 1], a[i]);
        int ans = 0;
        for (int take = 0; take <= k; take++) {
            int back = n - k + take;
            //printf("%d %d\n", take, back);
            int mn = 0x3f3f3f3f;
            for (int i = 1 + take, j = n - m + 1 + take; j <= back; i++, j++) {
                //printf("%d %d\n", i, j);
                mn = min(mn, max(a[i], a[j]));
            }
            ans = max(ans, mn);
        }
        printf("%d\n", ans);
    }

    return 0;
}