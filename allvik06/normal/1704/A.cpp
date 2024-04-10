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

inline void solve1() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int cnt = n - m;
    for (int i = 1; i < m; ++i) {
        if (b[i] != a[cnt + i]) {
            cout << "NO\n";
            return;
        }
    }
    int c0 = 0, c1 = 0;
    for (int i = 0; i <= cnt; ++i) {
        if (a[i] == '0') c0 = 1;
        else c1 = 1;
    }
    if ((b[0] == '0' && c0) || (b[0] == '1' && c1)) cout << "YES\n";
    else cout << "NO\n";
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