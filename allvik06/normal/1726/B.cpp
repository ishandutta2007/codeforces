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

void solve1() {
    int n, m;
    cin >> n >> m;
    if (m < n) cout << "No\n";
    else {
        if (n % 2 == 1) {
            cout << "Yes\n";
            for (int i = 0; i < n - 1; ++i) cout << "1 ";
            cout << m - (n - 1) << "\n";
        } else {
            if (m % 2 == 1) {
                cout << "No\n";
                return;
            }
            cout << "Yes\n";
            for (int i = 0; i < n - 2; ++i) cout << "1 ";
            int x = (m - (n - 2)) / 2;
            cout << x << " " << x << "\n";
        }
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