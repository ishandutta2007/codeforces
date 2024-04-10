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

const int MN = 2000005, MOD = 1e9 + 7;

int n, k, dp[MN], lst[26];
string s;

int32_t main() {
    boost();

    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) s += "?";
    n = s.size();
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * 2, dp[i] %= MOD;
        if (s[i - 1] == '?') {
            int p = 0x3f3f3f3f, id = -1;
            for (int j = 0; j < k; j++) if (lst[j] < p) p = lst[j], id = j;
            if (p) dp[i] -= dp[p - 1];
            lst[id] = i;
        } else {
            int p = lst[s[i - 1] - 'a'];
            if (p) dp[i] -= dp[p - 1];
            lst[s[i - 1] - 'a'] = i;
        }
    }
    dp[n] %= MOD, dp[n] += MOD, dp[n] %= MOD;
    printf("%lld\n", dp[n]);

    return 0;
}