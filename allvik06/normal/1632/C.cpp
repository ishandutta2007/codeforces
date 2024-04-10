#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <random>
#include <array>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = b - a;
        for (int i = 0; i < b - a; ++i) {
            int x = b + i;
            int aa = a;
            ans = min(ans, i + (a | x) - x + 1);
            int cur = 0;
            for (int j = 0; j < 25; ++j) {
                if ((aa >> j) & 1) {
                    cur += (1 << j);
                    aa += (1 << j);
                    ans = min(ans, i + cur + (aa | x) - x + 1);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
3 4
0 0 0
+ 1
+ 2
+ 2
- 1
 */