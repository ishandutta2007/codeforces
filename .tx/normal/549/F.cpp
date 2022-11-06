#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

struct SegmentTree {
    pair<int, int> * a;
    int n;

    SegmentTree(int n, int* x) : n(n) {
        a = new pair<int, int>[4 * n];
        build(0, 0, n, x);
    }

    void build(int i, int l, int r, int* x) {
        if (l + 1 == r) {
            a[i] = {x[l], l};
            return;
        }
        int m = (l + r) >> 1;
        build(i * 2 + 1, l, m, x);
        build(i * 2 + 2, m, r, x);
        a[i] = max(a[i * 2 + 1], a[i * 2 + 2]);
    }

    pair<int, int> get(int i, int l, int r, int ql, int qr) {
        if (r <= ql || l >= qr) {
            return {-1, -1};
        }
        if (ql <= l && r <= qr) {
            return a[i];
        }
        int m = (l + r) >> 1;
        return max(get(i * 2 + 1, l, m, ql, qr), get(i * 2 + 2, m, r, ql, qr));
    };

    pair<int, int> get(int l, int r) {
        return get(0, 0, n, l, r);
    };
};

int* a = new int[333333];
int* s = new int[333333];
vector<int> b[1111111];
int n, k;

lint go(int l, int r, SegmentTree& st) {
    if (l + 1 >= r) {
        return 0;
    }
    auto mx = st.get(l, r);
    lint res = go(l, mx.second, st) + go(mx.second + 1, r, st);
    if (2 * mx.second < l + r) {
        for (int i = l; i < mx.second; i++) {
            int lf = (s[i - 1] + mx.first) % k;
            res += lower_bound(b[lf].begin(), b[lf].end(), r) - lower_bound(b[lf].begin(), b[lf].end(), mx.second);
        }
        int lf = (s[mx.second - 1] + mx.first) % k;
        res += lower_bound(b[lf].begin(), b[lf].end(), r) - lower_bound(b[lf].begin(), b[lf].end(), mx.second + 1);
    } else {
        for (int i = mx.second + 1; i < r; i++) {
            int lf = ((s[i] - mx.first) % k + k) % k;
            res += upper_bound(b[lf].begin(), b[lf].end(), mx.second - 1) - lower_bound(b[lf].begin(), b[lf].end(), l - 1);
        }
        int lf = ((s[mx.second] - mx.first) % k + k) % k;
        res += upper_bound(b[lf].begin(), b[lf].end(), mx.second - 2) - lower_bound(b[lf].begin(), b[lf].end(), l - 1);
    }
    return res;
}

int main() {
    scii(n, k);
    s[0] = 0;
    b[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        sci(a[i]);
        s[i] = (a[i] + s[i - 1]) % k;
        b[s[i]].push_back(i);
    }
    SegmentTree st(n + 1, a);
    cout << go(1, n + 1, st);

    return 0;
}