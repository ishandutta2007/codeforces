#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 100005;

pair<int, int> A[NMAX];
int a[NMAX], b[NMAX];
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
    for (int i = 1; i <= n; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = A[i].first;
        b[i] = A[i].second;
    }

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        int pos = 0;
        for (int step = 1 << 20; step > 0; step >>= 1) {
            if (pos + step < i && a[pos + step] < a[i] - b[i]) {
                pos += step;
            }
        }
        dp[i] = dp[pos] + i - pos - 1;
        ans = min(ans, dp[i] + n - i);
    }

    cout << ans << '\n';
}