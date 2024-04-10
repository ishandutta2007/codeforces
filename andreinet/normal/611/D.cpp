#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 5005, MOD = 1e9 + 7;

char A[NMAX];
int dp[NMAX][NMAX];
int supr[NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n >> (A + 1);

    for (int i = n; i > 0; --i) {
        for (int j = n; j > i; --j) {
            if (A[i] == A[j])
                supr[i][j] = supr[i + 1][j + 1] + 1;
            else
                supr[i][j] = 0;
        }
    }

    for (int i = 0; i <= n; ++i)
        dp[0][i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i - j >= 0 && A[i - j + 1] != '0') {
                if (i - 2 * j >= 0) {
                    int p1 = i - 2 * j + 1, p2 = i - j + 1;
                    int c = supr[p1][p2];
                    if (c < j && A[p1 + c] < A[p2 + c]) {
                        dp[i][j] = (dp[i - j][j] + dp[i][j - 1]) % MOD;
                    } else {
                        dp[i][j] = (dp[i - j][j - 1] + dp[i][j - 1]) % MOD;
                    }
                } else {
                    dp[i][j] = (dp[i - j][j - 1] + dp[i][j - 1]) % MOD;
                }
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << dp[n][n] << '\n';
}