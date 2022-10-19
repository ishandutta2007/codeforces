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
    int n, k;
    cin >> n >> k;
    vector <int> cnt(26);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        ++cnt[c - 'a'];
    }
    string ans;
    for (int i = 0; i < k; ++i) {
        int cur = 0;
        int c = n / k;
        while (cnt[cur] && c) {
            --cnt[cur];
            ++cur;
            c--;
        }
        ans.push_back((char)('a' + cur));
    }
    cout << ans << "\n";
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