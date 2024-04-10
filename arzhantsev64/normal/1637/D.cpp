#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int bias = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i] + b[i];
        bias += (a[i] * a[i] + b[i] * b[i]) * (n - 2);
    }
    vector<vector<int>> dp(n + 1, vector<int> (20000));
    dp[0][10000] = 1;
    for (int i = 0; i < n; ++i)
        for (int d = 0; d < 20000; ++d) {
            if (d + a[i] - b[i] >= 0 && d + a[i] - b[i] < 20000)
                dp[i + 1][d] |= dp[i][d + a[i] - b[i]];
            if (d - a[i] + b[i] >= 0 && d - a[i] + b[i] < 20000)
                dp[i + 1][d] |= dp[i][d - a[i] + b[i]];
        }
    // cout << "ABOAB " << endl;
    int ans = 1e18;
    for (int d = 0; d < 20000; ++d)
        if (dp[n][d])
            ans = min(ans, abs(d - 10000));
    int A = (s - ans) / 2;
    int B = (s - ans) / 2 + ans;
    // cout << ans << ' ' << A << ' ' << B << '\n';
    cout << A * A + B * B + bias << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();


    return 0;
}