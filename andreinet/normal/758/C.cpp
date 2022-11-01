#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int64_t solve(int n, int m, int64_t k, int x, int y) {
    if (n == 1) {
        return k / m + (k % m >= y ? 1: 0);
    }
    if (k <= m) {
        return (x == 1 && k >= y ? 1: 0);
    }
    k -= m;
    int64_t cnt = k / (2 * (n - 1) * m);
    int64_t ans = cnt;
    if (1 < x && x < n) {
        ans *= 2;
    }
    if (x == 1) {
        ans++;
    }
    k -= cnt * 2 * (n - 1) * m;
    if (x == 1 && (2 * (n - 1) - 1) * m + y <= k) {
        ans++;
    } else if (x == n && (x - 2) * m + y <= k) {
       ans++;
    } else if (1 < x && x < n && (x - 2) * m + y <= k) {
        ans++;
        k -= (n - 1) * m;
        if ((n - x - 1) * m + y <= k) {
            ans++;
        }
    }
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y;
    int64_t k;
    cin >> n >> m >> k >> x >> y;

    int64_t vmax = 0, vmin = 1LL << 62;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int64_t val = solve(n, m, k, i, j);
            vmin = min(vmin, val);
            vmax = max(vmax, val);
        }
    }
    cout << vmax << ' ' << vmin << ' ' << solve(n, m, k, x, y) << '\n';
}