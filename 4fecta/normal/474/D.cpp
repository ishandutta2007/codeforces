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

const int MN = 100005, MOD = 1e9 + 7;

ll t, k, dp[MN], psa[MN], a, b;

int main() {
    boost();

    cin >> t >> k;
    dp[0] = 1;
    for (int i = 1; i < MN; i++) {
        dp[i] = dp[i - 1];
        if (i - k >= 0) dp[i] += dp[i - k];
        dp[i] %= MOD;
        psa[i] = psa[i - 1] + dp[i];
        psa[i] %= MOD;
    }

    while (t--) {
        cin >> a >> b;
        printf("%lld\n", (psa[b] - psa[a - 1] + MOD) % MOD);
    }

    return 0;
}