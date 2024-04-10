#include<bits/stdc++.h>

using namespace std;

int const maxn = 105;
bitset < maxn * maxn > dp[maxn];
int a[maxn], b[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        int ans = 0, sum = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            ans += (a[i] * a[i] + b[i] * b[i]) * (n - 2);
            sum += a[i] + b[i];
            dp[i] = ((dp[i - 1] << a[i])|(dp[i - 1] << b[i]));
        }
        int add = 4 * maxn * maxn * maxn * maxn;
        for (int s = 0; s < maxn * maxn; ++s) {
            if (dp[n][s]) add = min(add, s * s + (sum - s) * (sum - s));
        }
        cout << add + ans << '\n';
    }
    return 0;
}