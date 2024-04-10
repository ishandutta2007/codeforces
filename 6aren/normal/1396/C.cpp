#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 1000005;

int n, r1, r2, r3, d;
int a[N];
int dp[N][3];

int clear(int u) {
    int ans = min(r1, r3) * u + r3;
    return ans;
}

int noclear(int u) {
    return min({clear(u), r2 + min({r1, r2, r3}), min(r1, r3) * u + r1 * 2});
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[1][0] = clear(a[1]) + d;
    dp[1][1] = dp[1][2] = noclear(a[1]);
    dp[1][1] += 2 * d;
    dp[1][2] += 3 * d;

    for (int i = 2; i < n; i++) {
        dp[i][0] = dp[i - 1][2] + noclear(a[i]) + d;
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + clear(a[i]) + d);
        dp[i][1] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + noclear(a[i]) + 2 * d;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][2]) + noclear(a[i]) + 3 * d;
    }

    int ans = dp[n - 1][0] + clear(a[n]);
    ans = min(ans, dp[n - 1][1] + clear(a[n]));
    ans = min(ans, dp[n - 1][2] + noclear(a[n]));

    cout << ans << endl;
    // cout << dp[1][0] << endl;

    // cout << clear(3) << endl;

    return 0;
}