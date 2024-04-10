#include <bits/stdc++.h>

using namespace std;

#define int long long
pair < int, int > a[200005];
int out[200005];
int inf = 1e18;
int dp[200005];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].first;
    for (int i = 1; i <= n; ++i) a[i].second = i;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = inf;
        for (int j = i - 2; j >= max(i - 5, (long long)1); --j) {
            dp[i] = min(dp[i], dp[j - 1] + a[i].first - a[j].first);
        }
    }
    int ans = dp[n], i = n, cur = 1;
    while (i >= 1) {
        for (int j = i - 2; j >= max(i - 5, (long long)1); --j) {
            if (dp[i] == dp[j - 1] + a[i].first - a[j].first) {
                for (int z = j; z <= i; ++z) out[a[z].second] = cur;
                cur++;
                i = j - 1;
                break;
            }
        }
    }
    cout << ans << " " << cur - 1 << '\n';
    for (int i = 1; i <= n; ++i) cout << out[i] << " ";
    return 0;
}