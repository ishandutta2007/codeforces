#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>

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
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int now = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) ++now;
        }
        if (now <= 1) {
            cout << "0\n";
            continue;
        }
        int mn = n, mx = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                mn = min(mn, i);
                mx = max(mx, i + 1);
            }
        }
        cout << max(1LL, mx - mn - 2) << "\n";
    }
    return 0;
}