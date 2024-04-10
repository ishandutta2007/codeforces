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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        cout << "0\n";
        return;
    }
    cout << n - 1 << "\n" << 1 << " " << n << "\n";
    if ((a[0] + a[n - 1]) % 2 == 0) a[0] = a[n - 1];
    else a[n - 1] = a[0];
    for (int i = 1; i < n - 1; ++i) {
        if ((a[i] + a[0]) % 2 == 0) cout << i + 1 << " " << n << "\n";
        else cout << 1 << " " << i + 1 << "\n";
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