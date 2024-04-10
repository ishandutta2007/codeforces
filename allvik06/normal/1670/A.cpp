#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>

using namespace std;

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
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] < 0) ++cnt;
        }
        bool ok = true;
        for (int i = 0; i < cnt - 1; ++i) {
            if (-abs(a[i]) > -abs(a[i + 1])) ok = false;
        }
        for (int i = cnt; i < n - 1; ++i) {
            if (abs(a[i]) > abs(a[i + 1])) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}