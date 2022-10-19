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

const int R = 1 << 19;

const long long inf = 1e17;

vector<long long> t[2][R * 2];

void build(int ql, int qr, int node = 1, int nl = 0, int nr = R) {
    if (nl == nr - 1) {
        return;
    }
    if (nr <= ql || qr <= nl) {
        return;
    }
    int nm = (nl + nr) / 2;
    build(ql, qr, node * 2, nl, nm);
    build(ql, qr, node * 2 + 1, nm, nr);
    merge(t[0][node * 2].begin(), t[0][node * 2].end(), t[0][node * 2 + 1].begin(), t[0][node * 2 + 1].end(), back_inserter(t[0][node]));
    merge(t[1][node * 2].begin(), t[1][node * 2].end(), t[1][node * 2 + 1].begin(), t[1][node * 2 + 1].end(), back_inserter(t[1][node]));
}

long long get_mn(int ql, int qr, int t1) {
    ql += R;
    qr += R;
    long long mn = inf;
    while (ql < qr) {
        if (ql & 1) {
            if (!t[t1][ql].empty()) {
                mn = min(mn, t[t1][ql][0]);
            }
            ql++;
        }
        if (qr & 1) {
            qr--;
            if (!t[t1][qr].empty()) {
                mn = min(mn, t[t1][qr][0]);
            }
        }
        ql >>= 1;
        qr >>= 1;
    }
    return mn;
}

int get_cnt(int ql, int qr, int t1, long long x) {
    ql += R;
    qr += R;
    int ans = 0;
    while (ql < qr) {
        if (ql & 1) {
            ans += lower_bound(t[t1][ql].begin(), t[t1][ql].end(), x + 1) - lower_bound(t[t1][ql].begin(), t[t1][ql].end(), x);
            ql++;
        }
        if (qr & 1) {
            qr--;
            ans += lower_bound(t[t1][qr].begin(), t[t1][qr].end(), x + 1) - lower_bound(t[t1][qr].begin(), t[t1][qr].end(), x);
        }
        ql >>= 1;
        qr >>= 1;
    }
    return ans;
}

void clear(int ql, int qr, int node = 1, int nl = 0, int nr = R) {
    t[0][node] = t[1][node] = {};
    if (nl == nr - 1) {
        return;
    }
    if (nr <= ql || qr <= nl) {
        return;
    }
    int nm = (nl + nr) / 2;
    clear(ql, qr, node * 2, nl, nm);
    clear(ql, qr, node * 2 + 1, nm, nr);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = a[i] - pr[i];
    }
    for (int i = 0; i <= n; ++i) {
        t[i % 2][i + R] = {pr[i]};
        t[1 - i % 2][i + R] = {inf};
    }
    build(0, n + 5);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = i, r = n + 2;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (get_mn(i + 1, m, i % 2) - pr[i] < 0 || get_mn(i + 1, m, 1 - i % 2) + pr[i] < 0) {
                r = m;
            } else {
                l = m;
            }
        }
        ans += get_cnt(i + 1, l, i % 2, pr[i]) + get_cnt(i + 1, l, 1 - i % 2, -pr[i]);
    }
    cout << ans << '\n';
    clear(0, n + 5);
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