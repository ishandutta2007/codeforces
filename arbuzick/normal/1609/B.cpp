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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i + 3 <= n; ++i) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
            cnt++;
        }
    }
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        for (int i = max(0, pos - 2); i + 3 <= n && i <= pos; ++i) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                cnt--;
            }
        }
        s[pos] = c;
        for (int i = max(0, pos - 2); i + 3 <= n && i <= pos; ++i) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                cnt++;
            }
        }
        cout << cnt << '\n';
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