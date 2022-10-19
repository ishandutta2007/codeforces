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

bool check(long long x, int n) {
    long long l = 0, r = n;
    while (l < r - 1) {
        long long m = (l + r) / 2;
        if (m * (m + 1) / 2 <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return (l * (l + 1) / 2 == x);
}

int get(long long x, int n) {
    long long l = 0, r = n;
    while (l < r - 1) {
        long long m = (l + r) / 2;
        if (m * (m + 1) / 2 <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    int n;
    cin >> n;
    int l = 0, r = n;
    bool ch = false;
    long long sum;
    cout << "? " << 1 << ' ' << n << endl;
    cin >> sum;
    int i = -1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        cout << "? " << 1 << ' ' << m + 1 << endl;
        long long val;
        cin >> val;
        if (val == 0) {
            l = m;
            continue;
        }
        if (val != 0 && check(val, n) && val != sum) {
            if (!ch) {
                cout << "? " << 1 << ' ' << m << endl;
                long long vl;
                cin >> vl;
                if (check(vl, n) && get(vl, n) + 1 == get(val, n)) {
                    ch = true;
                    i = m - get(val, n);
                    l = m;
                } else {
                    int add = val - vl;
                    l = m - add - 1;
                    r = l + 1;
                    break;
                }
            } else if (m - get(val, n) == i) {
                l = m;
            } else {
                r = m;
            }
        } else {
            r = m;
        }
    }
    long long vl;
    cout << "? " << 1 << ' ' << l + 1 << endl;
    cin >> vl;
    cout << "! " << l + 1 - get(vl, n) << ' ' << l + 2 << ' ' << l + 2 + get(sum - vl, n) << endl;
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