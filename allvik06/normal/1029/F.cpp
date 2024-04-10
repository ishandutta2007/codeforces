#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <iomanip>
#include <array>
#include <deque>
#include <cmath>
#include <complex>
#include <queue>
#include <iomanip>

using namespace std;
#define int long long
const int INF = 2e7;
const int BINF = 1e16;

inline int solve(int a, int b) {
    vector <int> bl(INF, -1);
    for (int i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            bl[i] = i;
        }
    }
    for (int i = 1; i < INF; ++i) {
        if (bl[i] == -1) bl[i] = bl[i - 1];
    }
    int s = a + b;
    int minn = BINF;
    for (int i = 1; i * i <= s; ++i) {
        if (s % i == 0) {
            if (bl[i] != -1 && a / bl[i] <= s / i) minn = min(minn, 2 * (i + s / i));
        }
    }
    return minn;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int a, b;
    cin >> a >> b;
    cout << min(solve(a, b), solve(b, a));
}

/*

 */