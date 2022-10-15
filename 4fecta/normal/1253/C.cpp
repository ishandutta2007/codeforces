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

int n, m, a[200005];
ll psa[200005], ans[200005];

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i - 1] + a[i];
    }

    for (int i = 1; i <= m; i++) {
        ans[i] = psa[i];
        printf("%lld ", ans[i]);
    }

    for (int i = m + 1; i <= n; i++) {
        ans[i] = psa[i] + ans[i - m];
        printf("%lld ", ans[i]);
    }

    return 0;
}