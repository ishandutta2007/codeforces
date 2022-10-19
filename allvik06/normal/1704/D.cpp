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

inline void solve1() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    map <int, int> d;
    map <int, int> num;
    for (int i = 0; i < n; ++i) {
        int flex = 0;
        for (int j = 0; j < m; ++j) {
            flex += a[i][j] * j;
        }
        d[flex]++;
        num[flex] = i;
    }
    int kek = 0;
    for (auto i : d) {
        if (i.second == n - 1) {
            kek = i.first;
        }
    }
    for (auto i : d) {
        if (i.second == 1) {
            cout << num[i.first] + 1 << " " << i.first - kek << "\n";
            return;
        }
    }
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