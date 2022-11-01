#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef long double ldouble;

const double eps = 1e-11;

double dp[2][1005][1005];

double solve(int u, int i, int j) {
    if (i <= 0) return 0;
    if (j <= 0) return 1;
    if (abs(dp[u][i][j] - (-1)) > eps) return dp[u][i][j];
    double &ans = dp[u][i][j];
    ans = 0;
    
    if (u == 0) {
        ans += (double) i / (i + j);
        ans += (double) j / (i + j) * (1 - solve(1, i, j - 1));
    } else {
        ans += (double) i / (i + j);
        ans += (double) j / (i + j) * (1 - solve(0, i - 1, j - 1)) * (double) i / (i + j - 1);
        ans += (double) j / (i + j) * (1 - solve(0, i, j - 2)) * (double) (j - 1) / (i + j - 1);
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cout << setprecision(11) << fixed;

    int w, b;
    cin >> w >> b;
    
    for (int i = 0; i <= w; ++i)
        for (int j = 0; j <= b; ++j)
            dp[0][i][j] = dp[1][i][j] = -1;

    cout << solve(0, w, b) << '\n';
}