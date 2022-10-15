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

const int MN = 1005;

int n, m, a[MN][MN], ans[MN];

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];

        }
    }
    ans[1] = sqrt(a[1][2] * a[1][3] / a[2][3]);
    for (int i = 2; i <= n; i++) ans[i] = a[1][i] / ans[1];
    for (int i = 1; i <= n; i++ ) printf("%lld ", ans[i]);

    return 0;
}