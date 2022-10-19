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

using namespace std;
#define int long long

inline void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cur = 0;
    vector <int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        if (cur >= a[i]) {
            ans[i] = true;
        } else if (cur < q) {
            ++cur;
            ans[i] = true;
        }
    }
    for (int i : ans) cout << i;
    cout << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    } else {

    }
}

/*

 */