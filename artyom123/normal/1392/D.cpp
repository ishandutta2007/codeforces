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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') a[i] = 0;
            else a[i] = 1;
        }
        int ans = INF;
        for (int c1 = 0; c1 < 2; c1++) {
            for (int c2 = 0; c2 < 2; c2++) {
                vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, INF)));
                dp[1][c2][c1] = (c1 != a[0]) + (c2 != a[1]);
                for (int i = 2; i < n; i++) {
                    dp[i][0][0] = (a[i] != 0) + dp[i - 1][0][1];
                    dp[i][0][1] = (a[i] != 0) + min(dp[i - 1][1][0], dp[i - 1][1][1]);
                    dp[i][1][0] = (a[i] != 1) + min(dp[i - 1][0][0], dp[i - 1][0][1]);
                    dp[i][1][1] = (a[i] != 1) + dp[i - 1][1][0];
                }
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        int to1 = j + (1 - c2);
                        int ton = (1 - c1) + k;
                        bool f = true;
                        if (to1 == 1) {
                            if (c2 == 0 && c1 == 0) f = false;
                            if (j == 1 && c1 == 1) f = false;
                        }
                        if (ton == 1) {
                            if (c1 == 0 && j == 0) f = false;
                            if (k == 1 && j == 1) f = false;
                        }
                        if (f) ans = min(ans, dp[n - 1][j][k]);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}