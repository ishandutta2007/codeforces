#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;
#define int long long
const int INF = 1e10;

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
        vector <int> a(n), all;
        for (int i = 0; i < n; ++i) cin >> a[i];
        all = a;
        sort(all.begin(), all.end());
        int cnt = k + (n % 2 != k % 2);
        int val = (n + cnt + 1) / 2;
        int ans_x = -INF, ans_y = INF;
        for (int i = 0; i + val - 1 < n; ++i) {
            if (ans_y - ans_x > all[i + val - 1] - all[i]) {
                ans_x = all[i];
                ans_y = all[i + val - 1];
            }
        }
        cout << ans_x << " " << ans_y << "\n";
        int l = 0, r = -1;
        int cur_bal = 0;
        while (k > 1) {
            ++r;
            if (a[r] >= ans_x && a[r] <= ans_y) ++cur_bal;
            else --cur_bal;
            if (cur_bal > 0) {
                cout << l + 1 << " " << r + 1 << "\n";
                cur_bal = 0;
                k--;
                l = r + 1;
            }
        }
        cout << r + 2 << " " << n << "\n";
    }
}

/*

 */