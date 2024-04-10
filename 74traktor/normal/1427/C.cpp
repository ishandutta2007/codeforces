#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int t[maxn], x[maxn], y[maxn];
int dp[maxn];
int pref[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, n;
    cin >> r >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = -n - 1;
        if (abs(x[i] - 1) + abs(y[i] - 1) <= t[i]) dp[i] = 1;
        for (int j = i - 1; j >= max(1, i - 2 * r); --j) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        if (i - 2 * r >= 1) dp[i] = max(dp[i], pref[i - 2 * r] + 1);
        pref[i] = max(pref[i - 1], dp[i]);
    }
    cout << pref[n] << '\n';
    return 0;
}