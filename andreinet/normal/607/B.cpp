#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 505;

int A[NMAX];
int dp[NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    for (int i = n; i > 0; --i) {
        dp[i][i] = 1;
        for (int j = i + 1; j <= n; ++j) {
            dp[i][j] = 0x3f3f3f3f;
            for (int k = i + 1; k <= j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j]);
            if (A[i] == A[j]) {
                if (j == i + 1) dp[i][j] = 1;
                else {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }
            }
        }
    }

    cout << dp[1][n] << '\n';

}