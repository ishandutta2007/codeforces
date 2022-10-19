#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 205;

int r, g, t;
int dp[N][N][N];
int a[N], b[N], c[N];

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> r >> g >> t;
    for (int i = 1; i <= r; i++) cin >> a[i + 1];
    for (int i = 1; i <= g; i++) cin >> b[i + 1];
    for (int i = 1; i <= t; i++) cin >> c[i + 1];
    sort(a + 1, a + r + 2);
    sort(b + 1, b + g + 2);
    sort(c + 1, c + t + 2);

    for (int i = 1; i <= r + 1; i++) {
        for (int j = 1; j <= g + 1; j++) {
            for (int k = 1; k <= t + 1; k++) {
                dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i] * b[j]);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + b[j] * c[k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i] * c[k]);
            }
        }
    }

    int ans = 0;
    
    for (int i = 1; i <= r + 1; i++) {
        for (int j = 1; j <= g + 1; j++) {
            for (int k = 1; k <= t + 1; k++) {
                ans = max(ans, dp[i][j][k]);
            }
        }
    }

    cout << ans;

    return 0;
}