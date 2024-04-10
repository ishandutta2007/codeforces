#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <int> pref(n), suf(n);
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + abs(a[i] - a[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = suf[i + 1] + abs(a[i] - a[i + 1]);
        }
        int ans = min(pref[n - 2], suf[1]);
        for (int i = 1; i < n - 1; ++i) {
            ans = min(ans, pref[i - 1] + suf[i + 1] + abs(a[i + 1] - a[i - 1]));
        }
        cout << ans << "\n";
    }
}