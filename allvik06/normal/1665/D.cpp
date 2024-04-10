#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
#define int long long
const int INF = 1e9;

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int cur = 0;
        for (int i = 0; i < 30; ++i) {
            int x = (1 << i) - cur;
            cout << "? " << x << " " << x + (1 << (i + 1)) << endl;
            int res;
            cin >> res;
            if (res == (1 << (i + 1))) cur += (1 << i);
        }
        cout << "! " << cur << endl;
    }
}