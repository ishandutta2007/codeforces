#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            a.emplace_back(l, -1);
            a.emplace_back(r, 1);
        }
        sort(a.begin(), a.end());
        int l = -1, r = -1, flagl = 0, cnt = 0, flagr = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (a[i].second == -1) {
                ++cnt;
            }
            if ((a[i].second == 1 || cnt == n) && !flagl) {
                l = a[i].first;
                flagl = 1;
            }
            if (cnt == n && !flagr) {
                flagr = 1;
                r = a[i].first;
            }
        }
        cout << r - l << "\n";
    }
}