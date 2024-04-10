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
#include <cstring>

using namespace std;
const int mod = 998244353;

inline int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

void solve1() {
    int n, m;
    cin >> n >> m;
    vector <int> g(10);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x] |= (1 << y);
        g[y] |= (1 << x);
    }
    vector <int> and_mask(10), or_mask(10);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == j || ((g[i] >> j) & 1)) and_mask[i] |= (1 << j);
            if (((g[i] >> j) & 1) && j < i) or_mask[i] |= (1 << j);
        }
    }
    vector <int> dp1(1 << 10), dp2(1 << 10);
    dp1[0] = 1;
    while (n--) {
        for (int mask = 0; mask < (1 << 10); ++mask) {
            for (int i = 0; i < 10; ++i) {
                if ((mask >> i) & 1) continue;
                dp2[(mask & and_mask[i]) | or_mask[i]] = add(dp2[(mask & and_mask[i]) | or_mask[i]], dp1[mask]);
            }
        }
        dp1.swap(dp2);
        for (int i = 0; i < (1 << 10); ++i) dp2[i] = 0;
    }
    int ans = 0;
    for (int i : dp1) ans = add(ans, i);
    cout << ans;
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */