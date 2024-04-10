#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int INF = 1e9 + 1;

vector <int> di = {1, 0, -1, 0};
vector <int> dj = {0, 1, 0, 1};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<long long>> a(2, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }
    if (n == 1) {
        cout << a[1][0];
        return 0;
    }
    vector<vector<long long>> dp(n, vector<long long>(2));
    dp[n - 1][0] = a[1][n - 1];
    dp[n - 1][1] = a[0][n - 1];
    vector<long long> sum(n);
    sum[n - 1] = a[0][n - 1] + a[1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        dp[i][0] = dp[i + 1][0] + sum[i + 1] + a[1][i] * (2 * (n - 1 - i) + 1);
        dp[i][1] = dp[i + 1][1] + sum[i + 1] + a[0][i] * (2 * (n - 1 - i) + 1);
        sum[i] = sum[i + 1] + a[1][i] + a[0][i];
    }
    vector<vector<int>> usd(2, vector<int>(n));
    int i = 0, j = 0;
    long long ans = 0;
    long long now = 0;
    for (int it = 0; j < n - 1; it++) {
        now += a[i][j] * it;
        long long p = 0;
        usd[i][j] = 1;
        if (i == 0) {
            p = dp[j + 1][0] + sum[j + 1] * (it + 1);
            if (!usd[1][j]) {
                p += a[1][j] * (2 * (n - j - 1) + it + 1);
            }
        } else {
            p = dp[j + 1][1] + sum[j + 1] * (it + 1);
            if (!usd[0][j]) {
                p += a[0][j] * (2 * (n - j - 1) + it + 1);
            }
        }
        ans = max(ans, now + p);
        i += di[it % 4];
        j += dj[it % 4];
    }
    cout << ans;
    return 0;
}