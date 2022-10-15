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

const int MN = 105;

int n, a[MN], mx;

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
    int g = a[1];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) g = __gcd(g, __gcd(a[i], a[j]));
    }
    int sz = mx / g;
    if ((sz - n) % 2) cout << "Alice";
    else cout << "Bob";

    return 0;
}