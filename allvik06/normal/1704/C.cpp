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
    int n, m;
    cin >> n >> m;
    vector <int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i]; --a[i];
    }
    sort(a.begin(), a.end());
    vector <int> all;
    for (int i = 0; i < m; ++i) {
        if (i < m - 1) all.push_back(a[i + 1] - a[i] - 1);
        else all.push_back(n - a[i] + a[0] - 1);
    }
    sort(all.rbegin(), all.rend());
    int cur = 0, ans = 0;
    for (int i : all) {
        if (2 * cur >= i) {
            ans += i;
            continue;
        }
        if (2 * cur + 1 == i) {
            ans += 2 * cur;
            cur++;
            continue;
        }
        int cnt = 2 * cur;
        ++cur;
        ++cnt;
        ++cur;
        ans += cnt;
    }
    cout << ans + m << "\n";
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