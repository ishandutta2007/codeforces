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

const int MN = 100005;

int n, q, k, a[MN], d[MN], psa[MN];

int32_t main() {
    boost();

    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) d[i] = (a[i] - a[i - 1] - 1) * 2, psa[i] = d[i] + psa[i - 1];
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ret = 0;
        ret += a[l] - 1;
        ret += k - a[r];
        //for (int i = l + 1; i <= r; i++) ret += d[i] * 2;
        ret += psa[r] - psa[l];
        printf("%lld\n", ret);
    }

    return 0;
}