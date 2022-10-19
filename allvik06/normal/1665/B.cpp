#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
#define int long long
const int INF = 1e9;

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
        map <int, int> d;
        for (int i : a) ++d[i];
        int ans = INF;
        for (auto i : d) {
            int cur = i.second, tmp = 0;
            while (cur < n) {
                ++tmp;
                tmp += min(n - cur, cur);
                cur *= 2;
            }
            ans = min(ans, tmp);
        }
        cout << ans << "\n";
    }
}