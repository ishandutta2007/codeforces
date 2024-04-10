#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <vector<int>> dp(n + 1, vector<int>(26));
    vector <int> ans(n);
    int MAX = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (j != s[i - 1] - 'a') {
                dp[i][j] = dp[i - 1][j];
            } else {
                int MX = 0;
                for (int j1 = j + 1; j1 < 26; j1++) {
                    MX = max(MX, dp[i - 1][j1]);
                }
                dp[i][j] = MX + 1;
                MAX = max(MAX, MX + 1);
                ans[i - 1] = MX + 1;
            }
        }
    }
    cout << MAX << "\n";
    for (auto &c : ans) {
        cout << c << " ";
    }
    return 0;
}