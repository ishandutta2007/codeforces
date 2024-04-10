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

inline void solve() {
    int n;
    cin >> n;
    vector <int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector <vector <int>> all(n + 2);
    for (int i = 0; i < n; ++i) all[b[i]].push_back(i);
    int cur_val = 0;
    if (all[0].empty()) cur_val = n + 1;
    int cnt0 = 0, cnt1 = 0;
    vector <int> a;
    for (int i = 0; cur_val != -1; ++i) {
        if (i % 2 == 0) cnt0 += (int)all[cur_val].size();
        else cnt1 += (int)all[cur_val].size();
        int num = -1;
        for (int j : all[cur_val]) {
            if (!all[j + 1].empty()) num = j + 1;
        }
        for (int j : all[cur_val]) {
            if (j + 1 != num) a.push_back(j + 1);
        }
        if (num != -1) {
            a.push_back(num);
        }
        cur_val = num;
    }
    if (!all[0].empty()) {
        cout << n - cnt0 << "\n";
    } else {
        cout << cnt0 << "\n";
    }
    for (int i : a) cout << i  << " ";
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
    }
}

/*

 */