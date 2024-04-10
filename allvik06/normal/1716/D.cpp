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
    int n, k;
    cin >> n >> k;
    vector <int> dp1(n + 1), dp2(n + 1), ans(n + 1);
    dp1[0] = 1;
    for (int j = k;; ++j) {
        bool ok = false;
        for (int i = 0; i <= n; ++i) {
            if ((dp1[i] || dp2[i]) && i + j <= n) {
                dp2[i + j] = add(add(dp2[i + j], dp1[i]), dp2[i]);
                ok = true;
            }
            ans[i] = add(ans[i], dp2[i]);
            dp1[i] = dp2[i];
            dp2[i] = 0;
        }
        if (!ok) break;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        // cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */