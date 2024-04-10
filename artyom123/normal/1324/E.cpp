#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector <int> a(n);
    for (auto &c : a) {
        cin >> c;
    }
    vector <vector<int>> dp(n + 1, vector<int>(h, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            int cnt = 0;
            if ((j + a[i]) % h >= l && (j + a[i]) % h <= r) {
                cnt = 1;
            }
            dp[i + 1][(j + a[i]) % h] = max(dp[i + 1][(j + a[i]) % h], dp[i][j] + cnt);
            cnt = 0;
            if ((j + a[i] - 1) % h >= l && (j + a[i] - 1) % h <= r) {
                cnt = 1;
            }
            dp[i + 1][(j + a[i] - 1) % h] = max(dp[i + 1][(j + a[i] - 1) % h], dp[i][j] + cnt);
        }
    }
    int ans = 0;
    for (int j = 0; j < h; j++) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans;
    return 0;
}