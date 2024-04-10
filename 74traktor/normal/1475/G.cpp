#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
int dp[maxn];
int cnt[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a + 1, a + n + 1);
        for (int i = n; i >= 1; --i) {
            if (i != n && a[i] == a[i + 1]) continue;
            dp[a[i]] = cnt[a[i]];
            for (int val = 2 * a[i]; val < maxn; val += a[i]) {
                dp[a[i]] = max(dp[a[i]], dp[val] + cnt[a[i]]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dp[a[i]]);
            dp[a[i]] = 0;
            cnt[a[i]] = 0;
        }
        cout << n - ans << '\n';
    }
    return 0;
}