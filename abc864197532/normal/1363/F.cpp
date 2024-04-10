#include <bits/stdc++.h>
using namespace std;

const int N = 100005, mod = 1e9 + 7;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector <vector <int>> cnt1(n + 1, vector <int> (26, 0));
        vector <vector <int>> cnt2(n + 1, vector <int> (26, 0));
        vector <vector <int>> dp(n + 1, vector <int>(n + 1, 0));
        s = '_' + s, t = '_' + t;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                cnt1[i][j] = cnt1[i - 1][j];
                cnt2[i][j] = cnt2[i - 1][j];
            }
            cnt1[i][s[i] - 'a']++;
            cnt2[i][t[i] - 'a']++;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s[i] == t[j]) {
                    bool is = true;
                    for (int k = 0; k < 26; ++k) {
                        is &= cnt1[i][k] <= cnt2[j][k];
                    }
                    if (is) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s != t) cout << -1 << endl;
        else cout << n - dp[n][n] << endl;
    }
}