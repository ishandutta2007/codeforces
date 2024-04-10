#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
#define int long long

inline int flex(int a) {
    if (a == 0) return 0;
    int x = (int)sqrt(a);
    return 3 * (x - 1) + (x * x <= a) + (x * x + x <= a) + (x * x + 2 * x <= a);
}

inline int solve(int l, int r) {
    return flex(r) - flex(l - 1);
}

inline int solve2(int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; ++i) {
        if (i % (int)sqrt(i) == 0) ans++;
    }
    return ans;
}
signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            map <int, int> cnt_x, cnt_y;
            bool lol = false;
            for (int i = 0; i < 3; ++i) {
                int x, y;
                cin >> x >> y;
                ++cnt_x[x];
                ++cnt_y[y];
            }
            int xx, yy;
            for (auto i : cnt_x) {
                if (i.second > 1) xx = i.first;
            }
            for (auto i : cnt_y) {
                if (i.second > 1) yy = i.first;
            }
            int x, y;
            cin >> x >> y;
            if (x == xx || y == yy) {
                cout << "YES\n";
                continue;
            }
            if ((xx == 1 || xx == n) && (yy == 1 || yy == n)) {
                cout << "NO\n";
                continue;
            }
            if (x % 2 == xx % 2 || y % 2 == yy % 2) cout << "YES\n";
            else cout << "NO\n";
        }
        //  while (true) {}
    } else {
        int t;
        cin >> t;
        while (t--) {
            int l = 1e17 + rand() % 1000 + 1, r = 1e17 + rand() % 1000 + 1;
            if (l > r) swap(l, r);
            if (solve(l, r) != solve2(l, r)) {
                cout << l << " " << r;
                return 0;
            }
        }
    }
}

/*

 */