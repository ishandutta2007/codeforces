#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <int> p(n + 1);
        for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];
        if (k <= n) {
            int ans = 0;
            for (int i = 0; i + k - 1 < n; ++i) {
                ans = max(ans, p[i + k] - p[i]);
            }
            ans += k * (k - 1) / 2;
            cout << ans << "\n";
        } else {
            int ans = p[n] + k * n - n * (n + 1) / 2;
            cout << ans << "\n";
        }
    }
}