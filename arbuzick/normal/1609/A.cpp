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
    int n;
    cin >> n;
    vector<long long> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            cnt++;
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < cnt; ++i) {
        a.back() *= 2;
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    cout << sum << '\n';
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