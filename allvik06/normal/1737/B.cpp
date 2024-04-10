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
    int ans = 3 * (x - 1);
    if (x * x <= a) ++ans;
    if (x * x + x <= a) ++ans;
    if (x * x + x + x <= a) ++ans;
    return ans;
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
            int l, r;
            cin >> l >> r;
            cout << solve(l, r) << "\n";
        }
        //  while (true) {}
    } else {
        int t;
        cin >> t;
        while (t--) {
            int l = rand() % 1000 + 1, r = rand() % 1000 + 1;
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