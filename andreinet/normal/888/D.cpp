#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int NMAX = 1005;
const int KMAX = 6;

int64_t dp[NMAX][KMAX][KMAX][KMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int bad = 0; bad <= k; ++bad) {
            for (int emp = 0; emp <= k; ++emp) {
                for (int air = 0; air <= k; ++air) {
                    dp[i][bad][emp][air] = dp[i - 1][bad][emp][air];
                    if (air > 0 && bad > 0 && emp > 0) { // Put this in the air
                        dp[i][bad][emp][air] += dp[i - 1][bad - 1][emp - 1][air - 1];
                    }
                    if (air > 0 && bad > 0) { // Put something from before here, this in the air
                        dp[i][bad][emp][air] += dp[i - 1][bad - 1][emp][air] * air;
                    }
                    if (bad > 0) { // Put this on something empty
                        dp[i][bad][emp][air] += dp[i - 1][bad - 1][emp][air] * emp;
                    }
                    if (bad > 0 && emp + 1 <= k && air + 1 <= k) { // Put this on something empty
                                                                   // and some
                                                                   // remaining
                                                                   // here
                        dp[i][bad][emp][air] += dp[i - 1][bad - 1][emp + 1][air + 1] *
                            (air + 1) * (emp + 1);
                    }
                }
            }
        }
    }
    int64_t ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += dp[n][i][0][0];
    }
    cout << ans << '\n';
}