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

    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int f, s;
        if (a < c) f = 1;
        else f = -1;
        if (a * b > c) s = b;
        else s = -1;
        printf("%lld %lld\n", f, s);
    }

    return 0;
}