#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

int x[MAXN], h[MAXN];

int dp[MAXN + 1][3];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }
    x[n] = INT_MAX;
    for (int i = 0; i < MAXN + 1; i++) {
        for (int t = 0; t < 3; t++) {
            dp[i][t] = INT_MIN;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 1;
    if (x[0] + h[0] < x[1]) {
        dp[0][2] = 1;
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        if (x[i] - h[i] > x[i - 1]) {
            dp[i][1] = max(dp[i][1], 1 + dp[i - 1][0]);
            dp[i][1] = max(dp[i][1], 1 + dp[i - 1][1]);
            if (x[i] - h[i] > x[i - 1] + h[i - 1]) {
                dp[i][1] = max(dp[i][1], 1 + dp[i - 1][2]);
            }
        }
        if (x[i] + h[i] < x[i + 1]) {
            dp[i][2] = max(dp[i][2], 1 + dp[i - 1][0]);
            dp[i][2] = max(dp[i][2], 1 + dp[i - 1][1]);
            dp[i][2] = max(dp[i][2], 1 + dp[i - 1][2]);
        }
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
}