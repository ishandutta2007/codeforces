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

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int len = n + 1;
        vector <int> cur(n + 1, -n);
        for (int i = 0; i < n; ++i) {
            len = min(len, i - cur[a[i]] + 1);
            cur[a[i]] = i;
        }
        if (len == n + 1) cout << "-1\n";
        else cout << len << "\n";
    }
}

/*

 */