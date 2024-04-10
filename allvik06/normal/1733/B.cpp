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

void solve1() {
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> ans(n - 1);
    if (x != 0 && y != 0) {
        cout << "-1\n";
        return;
    }
    if (x == 0 && y == 0) {
        cout << "-1\n";
        return;
    }
    int v = (x ^ y);
    int cur = 0, prv = 1;
    for (int i = 1; i < n; ++i) {
        if (cur == v) {
            prv = i + 1;
            ans[i - 1] = i + 1;
            cur = 1;
        } else {
            ans[i - 1] = prv;
            ++cur;
        }
    }
    if (cur == v) {
        for (int i : ans) cout << i << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
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
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */