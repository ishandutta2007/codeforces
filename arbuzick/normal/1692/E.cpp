#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pos(n + 1, -1);
    pos[0] = 0;
    int ans = -1, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum >= s && pos[sum - s] != -1) {
            if (ans == -1 || ans > pos[sum - s] + n - i - 1) {
                ans = pos[sum - s] + n - i - 1;
            }
        }
        if (pos[sum] == -1) {
            pos[sum] = i + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}