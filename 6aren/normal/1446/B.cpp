#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 5005;
int dp[N][N], n, m;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;

    for (int i = 1; i < N; i++) {
        dp[0][i] = dp[i][0] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) dp[i][j] = max(dp[i - 1][j - 1] + 2, 2);
            else dp[i][j] = max({dp[i - 1][j] - 1, dp[i][j - 1] - 1, -2});
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) mx = max(mx, dp[i][j]);
    }

    cout << mx << '\n';

    return 0;
}