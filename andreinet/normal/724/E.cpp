#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int64_t LINF = 1LL << 62;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    vector<int64_t> dp(n + 1, LINF);
    dp[0] = 0;
    vector<int64_t> ndp(n + 1, LINF);
    for (int i = 0; i < n; ++i) {
        fill(ndp.begin(), ndp.end(), LINF);
        ndp[0] = dp[0] + B[i];
        for (int j = 1; j <= i + 1; ++j) {
            ndp[j] = min(dp[j] + B[i],
                    dp[j - 1] + (int64_t) (i - (j - 1)) * c + A[i]);
            ndp[j] = min(ndp[j], LINF);
        }
        dp.swap(ndp);
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}