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
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 2; i * i <= sum; ++i) {
        if (sum % i == 0) {
            cout << n << '\n';
            for (int j = 0; j < n; ++j) {
                cout << j + 1 << ' ';
            }
            cout << '\n';
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) {
            cout << n - 1 << '\n';
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    cout << j + 1 << ' ';
                }
            }
            cout << '\n';
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