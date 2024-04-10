#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

long long dp[N][6][2];
int a[N];

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= z; j++) dp[i][j][0] = dp[i][j][1] = -1e18;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0][0] = a[1];

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= min(i / 2, z); j++) {
            dp[i][j][0] = dp[i - 1][j][0] + a[1 + i - 2 * j];
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1] + a[1 + i - 2 * j]);
            if (j > 0) {
                dp[i][j][1] = dp[i - 1][j - 1][0] + a[1 + i - 2 * j];
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= z; i++) ans = max({ans, dp[k][i][0], dp[k][i][1]});
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}