#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 10;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <vector <int>> d(n + 1);
        for (int i = 0; i < n; ++i) {
            d[a[i]].push_back(i);
        }
        vector <bool> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            int sum = a[i];
            for (int j = i + 1; j < n; ++j) {
                sum += a[j];
                if (sum > n) break;
                ans[sum] = true;
            }
        }
        int res = 0;
        for (int j = 0; j <= n; ++j) {
            if (ans[j]) res += d[j].size();
        }
        cout << res << "\n";
    }
    return 0;
}