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

struct frnd {
    ll x, k;
    int msk;
};

bool cmp(frnd a, frnd b) {
    return a.k < b.k;
}

const int MN = 105, MM = 22;

int n, m, c, u; ll b, dp[1 << MM];
frnd a[MN];

int main() {
    boost();

    for (int i = 1; i < 1 << MM; i++) dp[i] = LLONG_MAX >> 1;
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].k >> c;
        for (int j = 0; j < c; j++) {
            cin >> u;
            a[i].msk |= 1 << (u - 1);
        }
    }
    sort(a, a + n, cmp);
    ll ans = LLONG_MAX >> 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 << m; j++) {
            int msk = j | a[i].msk;
            dp[msk] = min(dp[msk], dp[j] + a[i].x);
        }
        ans = min(ans, dp[(1 << m) - 1] + a[i].k * b);
    }
    printf("%lld\n", ans == LLONG_MAX >> 1 ? -1 : ans);

    return 0;
}