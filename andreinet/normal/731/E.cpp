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
    vector<int> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<int64_t> sums(n);
    sums[0] = A[0];
    for (int i = 1; i < n; ++i) {
        sums[i] = sums[i - 1] + A[i];
    }

    vector<int64_t> dp(n, 0);
    dp[n - 1] = sums[n - 1];
    int64_t maxs = dp[n - 1];
    for (int i = n - 2; i >= 1; --i) {
        dp[i] = -maxs + sums[i];
        maxs = max(maxs, dp[i]);
    }
    cout << maxs << '\n';
}