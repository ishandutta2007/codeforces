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
const int INF = 1e9;
map <array <int, 4>, int> d;

int calc(int a, int b, int move, int cur) {
    if (d.count({a, b, move, cur})) return d[{a, b, move, cur}];
    if (a == 0 && b == 0) return cur ^ 1;
    if (move == 0) {
        if (a && calc(a - 1, b, 1, cur)) {
            d[{a, b, move, cur}] = 1;
            return 1;
        }
        if (b && calc(a, b - 1, 1, cur ^ 1)) {
            d[{a, b, move, cur}] = 1;
            return 1;
        }
        d[{a, b, move, cur}] = 0;
        return 0;
    } else {
        if (a && calc(a - 1, b, 0, cur) == 0) {
            d[{a, b, move, cur}] = 0;
            return 0;
        }
        if (b && calc(a, b - 1, 0, cur) == 0) {
            d[{a, b, move, cur}] = 0;
            return 0;
        }
        d[{a, b, move, cur}] = 1;
        return 1;
    }
}

inline void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0) ++a;
        else ++b;
    }
    if (calc(a, b, 0, 0)) cout << "Alice\n";
    else cout << "Bob\n";
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