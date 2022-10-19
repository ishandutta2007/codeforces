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
#define int long long
const int mod = 998244353;

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
        bool ok = true;
        int ans = 1;
        for (int i = n - k; i < n; ++i) {
            if (a[i] > 0) {
                ok = false;
            }
            ans = ans * (n - i) % mod;
        }
        if (!ok) {
            cout << "0\n";
            continue;
        }
        for (int i = 0; i < n - k; ++i) {
            if (a[i] == -1) ans = ans * (i + k + 1) % mod;
            else if (a[i] == 0) ans = ans * (k + 1) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}