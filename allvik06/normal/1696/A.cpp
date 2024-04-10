#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, z, x = 0;
        cin >> n >> z;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            x = max(x, v | z);
        }
        cout << x << "\n";
    }
}

/*

 */