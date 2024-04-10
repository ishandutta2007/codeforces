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

using namespace std;
#define int long long
const int INF = 2e9;

inline void solve1() {
    int n, x;
    cin >> n >> x;
    pair <int, int> now(-INF, INF);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        int l = a - x, r = a + x;
        if (r < now.first || l > now.second) {
            ++cnt;
            now = make_pair(l, r);
        } else {
            now.first = max(now.first, l);
            now.second = min(now.second, r);
        }
    }
    cout << cnt << "\n";
}

signed main() {
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
    } else {
        mt19937 rnd(228);
        int t;
        cin >> t;
        while (t--) {

        }
    }
}

/*

 */