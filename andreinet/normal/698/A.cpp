#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int dp[4] = {0};
    int ndp[4] = {0};

    const int INF = 0x3f3f3f3f;

    memset(dp, -INF, sizeof dp);
    memset(ndp, -INF, sizeof ndp);
    dp[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        memset(ndp, -INF, sizeof ndp);
        int x;
        cin >> x;
        for (int j = 0; j < 4; ++j) {
            if (j ^ (j & x)) {
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                if (k & j) {
                    continue;
                }
                ndp[j] = max(ndp[j], dp[k]);
            }
            if (j != 0 && ndp[j] != -INF) {
                ndp[j]++;
            }
        }
        memcpy(dp, ndp, sizeof dp);
    }
    cout << n - *max_element(dp, dp + 4) << '\n';
}