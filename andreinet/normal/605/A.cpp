#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 100005;

int A[NMAX];
int dp[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> A[i];

    for (int i = 1; i <= n; ++i) {
        dp[A[i]] = dp[A[i] - 1] + 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);

    cout << n - ans << '\n';
}