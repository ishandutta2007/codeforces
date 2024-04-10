#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> loc;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            loc.push_back(i);
        }
    }
    if (loc.size() == 0) {
        for (int i = 0; i <= n * (n - 1) / 2; i++) {
            cout << 0 << " ";
        }
        cout << '\n';
        return 0;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n * (n - 1) / 2 + 1, 1e9)));
    for (int i = 0; i < n; i++) {
        dp[0][i][abs(loc[0] - i)] = i * (i - 1) / 2;
    }
    for (int i = 0; i < loc.size() - 1; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= n * (n - 1) / 2; k++) {
                if (dp[i][j][k] == 1e9) {
                    continue;
                }
                for (int l = j + 1; l < n; l++) {
                    if (k + abs(l - loc[i + 1]) >= n * (n - 1) / 2 + 1) {
                        continue;
                    }
                    dp[i + 1][l][k + abs(l - loc[i + 1])] = min(dp[i + 1][l][k + abs(l - loc[i + 1])], dp[i][j][k] + (l - j - 1) * (l - j - 2) / 2);
                }
            }
        }
    }
    int ans = 1e9;
    int tot = (n - loc.size()) * (n - loc.size() - 1) / 2;
    for (int i = 0; i <= n * (n - 1) / 2; i++) {
        for (int j = 0; j < n; j++) {
            int val = dp[loc.size() - 1][j][i];
            if (val == 1e9) {
                continue;
            }
            ans = min(ans, val + (n - 1 - j) * (n - 1 - j - 1) / 2);
        }
        cout << tot - ans << " ";
    }
    cout << '\n';
    return 0;
}