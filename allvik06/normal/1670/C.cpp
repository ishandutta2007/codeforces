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
const int mod = 1e9 + 7;

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
        vector <int> a(n), b(n), pos(n), d(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; --a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i]; --b[i];
            pos[b[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> d[i]; --d[i];
        }
        vector <bool> used(n);
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (used[i] || a[i] == b[i]) continue;
            int cur = i;
            bool one = false, two = false;
            while (!used[cur]) {
                used[cur] = true;
                if (d[cur] != -1) {
                    if (d[cur] == a[cur]) one = true;
                    else two = true;
                }
                cur = pos[a[cur]];
            }
            if (one && two) {
                cnt = 0;
            } else if (!one && !two) {
                cnt = (cnt * 2) % mod;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}