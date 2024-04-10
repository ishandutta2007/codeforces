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

    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] % m << '\n';
        return 0;
    }
    int mid = ((n + 1) / 2);
    vector<int> sums;
    for (int conf = 0; conf < (1 << mid); ++conf) {
        int sum = 0;
        for (int i = 0; i < mid; ++i) {
            if ((conf & (1 << i)) != 0) {
                sum = (sum + a[i]) % m;
            }
        }
        sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());
    int ans = 0;
    for (int64_t conf = 0; conf < (1LL << n); conf += 1LL << mid) {
        int sum = 0;
        for (int i = mid; i < n; ++i) {
            if ((conf & (1LL << i)) != 0) {
                sum = (sum + a[i]) % m;
            }
        }
        int need = (m - 1 - sum + m) % m;
        int pos = upper_bound(sums.begin(), sums.end(), need) - sums.begin() - 1;
        if (pos < 0) {
            pos = SZ(sums) - 1;
        }
        ans = max(ans, (sum + sums[pos]) % m);
    }
    cout << ans << '\n';
}