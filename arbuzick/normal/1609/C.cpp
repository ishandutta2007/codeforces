#pragma GCC optimize("O3")
//#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <numeric>
#include <random>
#include <chrono>
#include <deque>
#include <map>
#include <queue>
#include <limits.h>
//#include <immintrin.h>

//#define _USE_MATH_DEFINE
using namespace std;
//#define int long long

void solve() {
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> pr(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (i + 1 >= e) {
            pr[i + 1] = pr[i + 1 - e] + a[i];
        } else {
            pr[i + 1] = a[i];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            continue;
        }
        bool ch = true;
        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                ch = false;
                break;
            }
        }
        if (!ch) {
            continue;
        }
        int l = 0, r = i / e + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (i + 1 - e * (m + 1) < 0) {
                if (pr[i + 1 - e] == m) {
                    l = m;
                } else {
                    r = m;
                }
            } else {
                if (pr[i + 1 - e] - pr[i + 1 - e * (m + 1)] == m) {
                    l = m;
                } else {
                    r = m;
                }
            }
        }
        int l2 = 0, r2 = (n - i - 1) / e + 1;
        while (l2 < r2 - 1) {
            int m = (l2 + r2) / 2;
            if (pr[i + 1 + e * m] - pr[i + 1] == m) {
                l2 = m;
            } else {
                r2 = m;
            }
        }
        if (l2 + l > 0) {
            ans += (l2 + 1) * 1LL * (l + 1) - 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}