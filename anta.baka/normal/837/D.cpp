#include <bits/stdc++.h>

using namespace std;

int n, k, x[201], y[201], dp[201][5001], dp1[201][5001], ans;
bool can[201][5001], can1[201][5001];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        long long num;
        cin >> num;
        while(num % 5 == 0) {
            x[i]++;
            num /= 5;
        }
        while(num % 2 == 0) {
            y[i]++;
            num /= 2;
        }
    }
    can[0][0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min(i, k); j++)
            for(int r = 0; r <= 25 * j; r++) {
                if(can[j][r]) {
                    can1[j][r] = true;
                    dp1[j][r] = dp[j][r];
                }
                if(r - x[i] >= 0 && can[j - 1][r - x[i]]) {
                    can1[j][r] = true;
                    dp1[j][r] = max(dp1[j][r], dp[j - 1][r - x[i]] + y[i]);
                }
            }
        for(int j = 1; j <= min(i, k); j++)
            for(int r = 0; r <= 25 * j; r++) {
                can[j][r] = can1[j][r];
                dp[j][r] = dp1[j][r];
            }
    }
    for(int i = 0; i <= 25 * k; i++)
        ans = max(ans, min(i, dp[k][i]));
    cout << ans;
}