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
    vector <int> a(n);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) ++cnt0;
        else ++cnt1;
    }
    int cur_pl = 0, ln = 0, ans = cnt1;
    for (int i : a) {
        if (i == 0) {
            ln++;
            cnt0--;
        } else {
            cur_pl++;
            cnt1--;
        }
        ans = max(ans, ln + cnt1 + min(cur_pl, cnt0));
    }
    cout << n - ans << "\n";
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