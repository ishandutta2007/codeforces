#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, x, y;
    cin >> n >> x >> y;
    int s = x + y, l = max(x, y);
    vector <int> dp1((1 << l)), dp2(1 << l);
    for (int i = 0; i < s; ++i) {
        for (int mask = 0; mask < (1 << l); ++mask) {
            dp2[mask >> 1] = max(dp2[mask >> 1], dp1[mask]);
            if ((mask >> (l - x)) & 1) continue;
            if ((mask >> (l - y)) & 1) continue;
            dp2[(mask >> 1) | (1 << (l - 1))] = max(dp2[(mask >> 1) | (1 << (l - 1))], dp1[mask] + (n - i + s - 1) / s);
        }
        dp1.swap(dp2);
    }
    cout << *max_element(dp1.begin(), dp1.end());
}