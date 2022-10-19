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
#define ll long long

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
        vector <int> a(n), b(n), pos(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; --a[i];
            pos[a[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i]; --b[i];
        }
        vector <bool> used(n);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            int now = i;
            int cnt = 0;
            while (!used[now]) {
                used[now] = true;
                ++cnt;
                now = pos[b[now]];
            }
            cur += (cnt & 1);
        }
        ll ans = 0;
        int l, r;
        if (n % 2 == 1) {
            l = (n + 1) / 2 - cur / 2;
            r = l + cur - 1;
        } else {
            l = n / 2 - cur / 2 + 1;
            r = l + cur - 1;
        }
        for (int i = 1; i < l; ++i) ans -= 2 * i;
        for (int i = r + 1; i <= n; ++i) ans += 2 * i;
        cout << ans << "\n";
    }
    return 0;
}