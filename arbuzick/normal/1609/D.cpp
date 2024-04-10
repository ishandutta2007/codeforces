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

struct DSU {
    int n;
    vector<int> h, sz, p;

    DSU(int _n) {
        n = _n;
        h.assign(n, 1);
        sz.assign(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int pr(int a) {
        if (p[a] == a) {
            return a;
        }
        return p[a] = pr(p[a]);
    }

    void unite(int a, int b) {
        a = pr(a), b = pr(b);
        if (h[a] > h[b]) {
            p[b] = a;
            sz[a] += sz[b];
        } else if (h[a] < h[b]) {
            p[a] = b;
            sz[b] += sz[a];
        } else {
            p[b] = a;
            h[a]++;
            sz[a] += sz[b];
        }
    }
};

void solve() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(d);
    for (int i = 0; i < d; ++i) {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
    }
    for (int i = 0; i < d; ++i) {
        DSU kek(n);
        int cnt = 0;
        for (int j = 0; j <= i; ++j) {
            if (kek.pr(a[j].first) != kek.pr(a[j].second)) {
                kek.unite(a[j].first, a[j].second);
            } else {
                cnt++;
            }
        }
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (kek.pr(j) == j) {
                v.push_back(kek.sz[j]);
            }
        }
        sort(v.rbegin(), v.rend());
        int ans = 0;
        for (int j = 0; j <= cnt && j < (int) v.size(); ++j) {
            ans += v[j];
        }
        cout << ans - 1 << '\n';
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