#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
#define int long long
const int MAXP = 5000;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(n);
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            --x;
            ++cnt[x];
        }
        int l = 0, r = 2 * m;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int cnt_free = 0;
            int cnt_tasks = 0;
            for (int i = 0; i < n; ++i) {
                if (cnt[i] > mid) {
                    cnt_tasks += cnt[i] - mid;
                } else {
                    cnt_free += (mid - cnt[i]) / 2;
                }
            }
            if (cnt_free >= cnt_tasks) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }
}

/*

 */