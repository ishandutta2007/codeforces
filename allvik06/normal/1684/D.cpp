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
#include <iomanip>

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
        vector <pair <int, int>> b;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            b.emplace_back(a[i] + i, i);
        }
        sort(b.rbegin(), b.rend());
        vector <int> used(n);
        for (int i = 0; i < k; ++i) used[b[i].second] = 1;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                sum -= a[i];
                sum += n - i - 1 - (k - cur - 1);
                ++cur;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}