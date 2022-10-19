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
    int n, m;
    cin >> n >> m;
    vector<int> used(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        used[b] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    cout << i + 1 << ' ' << j + 1 << '\n';
                }
            }
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}