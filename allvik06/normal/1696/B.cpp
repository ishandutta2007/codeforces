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
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        bool ok = true;
        for (int i : a) {
            if (i > 0) ok = false;
        }
        if (ok) {
            cout << "0\n";
            continue;
        }
        int l = -1, r = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) {
                if (l == -1) l = i;
                r = i;
            }
        }
        ok = true;
        for (int i = l; i <= r; ++i) {
            if (a[i] == 0) ok = false;
        }
        if (ok) cout << "1\n";
        else cout << "2\n";
    }
}

/*

 */