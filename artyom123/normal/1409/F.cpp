#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t;
    cin >> t;
    int dp[n][k + 1][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= n; l++) {
                dp[i][j][l] = -INF;
            }
        }
    }
    for (int c = 0; c < 26; c++) {
        if (c + 'a' == s[0]) dp[0][0][c + 'a' == t[0]] = 0;
        else if (k >= 1) dp[0][1][c + 'a' == t[0]] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= n; l++) {
                for (int c = 0; c < 26; c++) {
                    if (s[i] != c + 'a' && j == 0) continue;
                    if (t[0] == c + 'a' && l == 0) continue;
                    dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - (s[i] != c + 'a')][l - (c + 'a' == t[0])] + (c + 'a' == t[1]) * (l - (c + 'a' == t[0])));
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= k; j++) {
        for (int l = 0; l <= n; l++) {
            ans = max(ans, dp[n - 1][j][l]);
        }
    }
    cout << ans;
    return 0;
}