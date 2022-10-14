#include <bits/stdc++.h>
using namespace std;

struct op {
    int a, p;
    char c;
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector <vector <int>> dp(n + 1, vector <int> (m + 1, 1 << 30));
    vector <vector <int>> x(n + 1, vector <int> (m + 1, -10));
    vector <vector <int>> y(n + 1, vector <int> (m + 1, -10));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
        x[i][0] = -1;
        y[i][0] = 0;
    }
    for (int i = 0; i <= m; ++i) {
        dp[0][i] = i;
        x[0][i] = 0;
        y[0][i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j];
                x[i + 1][j + 1] = y[i + 1][j + 1] = -1;
            } else {
                dp[i + 1][j + 1] = min({dp[i + 1][j], dp[i][j + 1], dp[i][j]});
                if (dp[i + 1][j + 1] == dp[i + 1][j]) x[i + 1][j + 1] = 0, y[i + 1][j + 1] = -1;
                if (dp[i + 1][j + 1] == dp[i][j + 1]) x[i + 1][j + 1] = -1, y[i + 1][j + 1] = 0;
                if (dp[i + 1][j + 1] == dp[i][j]) x[i + 1][j + 1] = -1, y[i + 1][j + 1] = -1;
                dp[i + 1][j + 1]++;
            }
        }
    }
    int i = n, j = m;
    vector <op> ans;
    while (i > 0 || j > 0) {
        int xx = x[i][j], yy = y[i][j];
        if (xx == -1 && yy == -1) {
            if (s[i - 1] != t[j - 1]) ans.push_back({1, i, t[j - 1]});
        } else if (xx == -1) {
            ans.push_back({2, i});
        } else {
            ans.push_back({3, i + 1, t[j - 1]});
        }
        i += xx, j += yy;
    }
    cout << ans.size() << endl;
    for (auto A : ans) {
        if (A.a == 1) cout << "REPLACE " << A.p << ' ' << A.c << endl;
        else if (A.a == 2) cout << "DELETE " << A.p << endl;
        else cout << "INSERT " << A.p << ' ' << A.c << endl;
    }
}