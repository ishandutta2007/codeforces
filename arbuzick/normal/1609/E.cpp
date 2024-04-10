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

const int R = 1 << 17;

struct s {
    int a, b, c, ab, bc, abc;

    s() { a = b = c = ab = bc = abc = R; }

    s(int n0) {
        a = b = c = ab = bc = abc = 0;
    }
};

s t[R * 2];

void relax(s &nw, s &l, s &r) {
    nw.a = l.a + r.a;
    nw.b = l.b + r.b;
    nw.c = l.c + r.c;
    nw.ab = min(l.a + r.ab, l.ab + r.b);
    nw.bc = min(l.b + r.bc, l.bc + r.c);
    nw.abc = min({l.a + r.abc, l.ab + r.bc, l.abc + r.c});
}

void build() {
    for (int i = R - 1; i > 0; --i) {
        relax(t[i], t[i * 2], t[i * 2 + 1]);
    }
}

void change(int pos, char c) {
    pos += R;
    t[pos].a = t[pos].b = t[pos].c = t[pos].ab = t[pos].bc = 0;
    if (c == 'a') {
        t[pos].a = 1;
    } else if (c == 'b') {
        t[pos].b = 1;
    } else {
        t[pos].c = 1;
    }
    for (pos /= 2; pos > 0; pos /= 2) {
        relax(t[pos], t[pos * 2], t[pos * 2 + 1]);
    }
}

s get(int ql, int qr, int node = 1, int nl = 0, int nr = R) {
    if (ql <= nl && nr <= qr) {
        return t[node];
    }
    if (qr <= nl || nr <= ql) {
        return s(0);
    }
    int nm = (nl + nr) / 2;
    auto l = get(ql, qr, node * 2, nl, nm), r = get(ql, qr, node * 2 + 1, nm, nr);
    s ans(0);
    relax(ans, l, r);
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        int pos = i + R;
        char c = s[i];
        t[pos].a = t[pos].b = t[pos].c = t[pos].ab = t[pos].bc = 0;
        if (c == 'a') {
            t[pos].a = 1;
        } else if (c == 'b') {
            t[pos].b = 1;
        } else {
            t[pos].c = 1;
        }
    }
    build();
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        change(pos, c);
        auto ans = get(0, n);
        cout << min({ans.a, ans.b, ans.c, ans.ab, ans.bc, ans.abc}) << '\n';
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