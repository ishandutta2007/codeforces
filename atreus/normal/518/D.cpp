#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3;
double dp[maxn + 100][maxn + 100];

int main(){
    int n, t;
    double p;
    cin >> n >> p >> t;
    for (int i = 0; i <= t; i++){
        dp[i][0] = pow((1 - p), i);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= t; j++){
            dp[j][i] = 1.0 * dp[j - 1][i] * (1.0 - p) + (1.0 * dp[j - 1][i - 1] * p);
            if (i == n)
                dp[j][i] += dp[j - 1][i] * p;
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++){
        ans += 1.0 * dp[t][i] * i;
    }
    cout << fixed << setprecision(6) << ans << endl;
}