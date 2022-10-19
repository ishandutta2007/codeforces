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
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int max_p = 0, x = 1;
        while (x <= (int)1e16) {
            ++max_p;
            x *= k;
        }
        vector <int> p(max_p + 1, -1);
        bool ok = true;
        for (int i = max_p; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (a[j] >= x) {
                    a[j] -= x;
                    if (p[i] != -1) {
                        ok = false;
                    }
                    p[i] = j;
                }
            }
            x /= k;
        }
        if (*max_element(a.begin(), a.end()) > 0) ok = false;
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

/*

 */