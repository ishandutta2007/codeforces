#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

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

    vector<int64_t> cost(30, 1LL << 62);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    n = 30;
    for (int i = 1; i < n; ++i) {
        cost[i] = min(cost[i], 2 * cost[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        cost[i] = min(cost[i], cost[i + 1]);
    }
    int64_t ans = 1LL << 62;
    int64_t curr = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (k & (1 << i)) {
            if (i + 1 < n) {
                ans = min(ans, curr + cost[i + 1]);
            }
            curr += cost[i];
        }
    }
    ans = min(ans, curr);
    cout << ans << '\n';
}