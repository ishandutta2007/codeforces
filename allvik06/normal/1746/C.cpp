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

inline void solve() {
    int n;
    cin >> n;
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans[n - x] = i;
    }
    for (int i : ans) cout << i + 1 << " ";
    cout << "\n";
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
            solve();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */