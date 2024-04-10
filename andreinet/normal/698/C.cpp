#include <bits/stdc++.h>
#define double long double
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int bitCount(int x) {
    int ret = 0;
    while (x) {
        ret++;
        x &= x - 1;
    }
    return ret;
}

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

    vector<double> P(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
        if (P[i] < 1e-9) {
            cnt++;
        }
    }
    int r = k;
    if (n - cnt < k) {
        r = n - cnt;
    }

    vector<double> dp(1 << n, 0);
    dp[0] = 1;

    vector<double> ans(n, 0);
    for (int conf = 0; conf < (1 << n); ++conf) {
        if (bitCount(conf) > r) {
            continue;
        }
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            if (!(conf & (1 << i))) {
                sum += P[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (conf & (1 << i)) {
                continue;
            }
            dp[conf | (1 << i)] += dp[conf] * (P[i] / sum);
        }
        if (bitCount(conf) == r) {
            for (int i = 0; i < n; ++i) {
                if (conf & (1 << i)) {
                    ans[i] += dp[conf];
                }
            }
        }
    }
    cout << setprecision(14) << fixed;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}