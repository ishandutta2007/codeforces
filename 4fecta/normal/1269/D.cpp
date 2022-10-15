#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 300005;

int n, a[MN], o = 0, e = 0;

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            if (i % 2) {
                o += a[i] / 2;
                e += a[i] / 2 + 1;
            } else {
                o += a[i] / 2 + 1;
                e += a[i] / 2;
            }
        } else {
            o += a[i] / 2;
            e += a[i] / 2;
        }
    }
    printf("%lld\n", min(o, e));

    return 0;
}