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
        int n;
        cin >> n;
        int x = 1;
        while (x * 2 < n) x *= 2;
        for (int i = n - 1; i >= x; --i) cout << i << " ";
        for (int i = 0; i < x; ++i) cout << i << " ";
        cout << "\n";
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