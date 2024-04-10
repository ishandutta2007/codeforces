#pragma GCC optimize("O3")
//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <numeric>
#include <cmath>

//#define _USE_MATH_DEFINES
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = n; i >= 1; --i) {
        if (i == 1) {
            ans[n - 1] = 1;
            break;
        }
        cout << "? ";
        for (int j = 0; j < n - 1; ++j) {
            cout << i << ' ';
        }
        cout << 1 << endl;
        int c;
        cin >> c;
        if (c == 0) {
            continue;
        }
        ans[n - 1] = i;
        break;
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[n - 1] == i) {
            continue;
        }
        cout << "? ";
        for (int j = 0; j < n - 1; ++j) {
            cout << n + 1 - i << ' ';
        }
        cout << n + 1 - ans[n - 1] << endl;
        int c;
        cin >> c;
        c--;
        ans[c] = i;
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}