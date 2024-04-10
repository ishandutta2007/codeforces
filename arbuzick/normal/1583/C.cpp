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
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ch(m), pr(m + 1);
    for (int j = 1; j < m; ++j) {
        for (int i = 1; i < n; ++i) {
            if (a[i - 1][j] != '.' && a[i][j - 1] != '.') {
                ch[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        pr[i + 1] = pr[i] + ch[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (pr[y] - pr[x]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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