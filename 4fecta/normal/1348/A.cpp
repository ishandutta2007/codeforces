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

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int half = n / 2;
        int p1 = 0, p2 = 0;
        for (int i = 1; i < half; i++) p1 += 1 << i;
        for (int i = half; i < n; i++) p2 += 1 << i;
        p1 += 1 << n;
        printf("%lld\n", abs(p1 - p2));
    }

    return 0;
}