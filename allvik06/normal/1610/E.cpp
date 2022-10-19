#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
//#define int long long

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
        int ans = 2;
        for (int l = 0; l < n; ++l) {
            if (l && a[l] == a[l - 1]) continue;
            int cur = l + 1, cur_cnt = 2;
            while (cur + 1 < n) {
                auto it = lower_bound(a.begin(), a.end(), 2 * a[cur] - a[l]);
                if (it != a.end()) {
                    ++cur_cnt;
                    cur = max((int)(it - a.begin()), cur + 1);
                } else break;
            }
            ans = max(ans, cur_cnt);
        }
        cout << n - ans << "\n";
    }
}

/*

 */