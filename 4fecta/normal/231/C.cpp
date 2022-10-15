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

int n, k, a[MN], mx, ans, delta, lft;

int32_t main() {
    boost();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    mx = 1, ans = a[1], delta = 0, lft = 1;
    for (int i = 2; i <= n; i++) {
        delta += (a[i] - a[i - 1]) * (i - lft);
        while (delta > k) delta -= a[i] - a[lft++];
        if (i - lft + 1 > mx) mx = i - lft + 1, ans = a[i];
    }
    printf("%lld %lld\n", mx, ans);

    return 0;
}