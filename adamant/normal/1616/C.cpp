#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == 1 || n == 2) {
        cout << 0 << "\n";
        return;
    }
    vector<vector<int>> dp(n, vector<int>(n));
    // dp[i][j] = max arythmetic base with last two elements aj, ai
    // a[i] = k * i + b
    // a[j] = k * j + b -> (a[j] - a[i]) / (j - i) = k
    int ans = n - 2;
    for(int i = 0; i < n; i++) {
        assert(!dp[i][i]);
        dp[i][i] = 1;
        for(int j = 0; j < i; j++) {
            assert(!dp[i][j]);
            dp[i][j] = 2;
            for(int k = 0; k < j; k++) {
                if((a[i] - a[j]) * (j - k) == (a[j] - a[k]) * (i - j)) {
                    dp[i][j] = max(dp[i][j], dp[j][k] + 1);
                    ans = min(ans, n - dp[i][j]);
                }
            }
        }
    }
    cout << ans << "\n";
}

// a[k] - a[k - 1] = a[k - 1] - a[k - 2] <=> arythmetic progression

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}