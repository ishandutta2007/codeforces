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

const int MN = 105, MQ = 10005;

int n, a[MN], dp[MN][MQ], ans, freq[MN], tmp[MQ];

int32_t main() {
    boost();

    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) cin >> a[i], freq[a[i]]++, s.insert(a[i]);
    if (s.size() <= 2) return 0 * printf("%d\n", n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            for (int sum = a[i]; sum <= 10000; sum++) {
                dp[j][sum] += dp[j - 1][sum - a[i]];
            }
        }
    }
    for (int i = 1; i <= 100; i++) {
        memset(tmp, 0, sizeof(tmp));
        tmp[0] = 1;
        for (int k = 1; k <= freq[i]; k++) {
            for (int j = 10000; j >= i; j--) {
                tmp[j] += tmp[j - i];
            }
        }
        for (int k = 1; k <= freq[i]; k++) {
            if (dp[k][i * k] == tmp[i * k]) {
                ans = max(ans, k);
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}