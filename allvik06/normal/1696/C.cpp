#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

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
        int n, m, k;
        cin >> n >> m;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cin >> k;
        vector <int> b(k);
        for (int i = 0; i < k; ++i) cin >> b[i];
        vector <pair <int, int>> all;
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            while (a[i] % m == 0) {
                a[i] /= m;
                cnt *= m;
            }
            if (!all.empty() && all.back().first == a[i]) all.back().second += cnt;
            else all.emplace_back(a[i], cnt);
        }
        int cur = 0;
        bool ok = true;
        for (int i = 0; i < k; ++i) {
            if (cur == (int)all.size()) {
                ok = false;
                break;
            }
            if (b[i] < all[cur].first) {
                ok = false;
                break;
            }
            int cnt = 1, x = all[cur].first;
            while (b[i] > x) {
                cnt *= m;
                x *= m;
            }
            if (b[i] != x || all[cur].second < cnt) {
                ok = false;
                break;
            }
            all[cur].second -= cnt;
            if (all[cur].second == 0) ++cur;
        }
        if (ok && all.back().second == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}

/*

 */