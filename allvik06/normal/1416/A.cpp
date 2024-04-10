#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <vector <int>> kek(n + 1);
        for (int i = 0; i < n; ++i) {
            kek[a[i]].push_back(i);
        }
        vector <int> ans(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            if (kek[i].empty()) continue;
            int minn = max(kek[i].front() + 1, n - kek[i].back());
            for (int j = 0; j < kek[i].size() - 1; ++j) {
                minn = max(minn, kek[i][j + 1] - kek[i][j]);
            }
            for (int j = minn; j <= n; ++j) {
                if (ans[j] == -1) ans[j] = i;
                else break;
            }
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << "\n";
    }
}