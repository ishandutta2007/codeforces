#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <fstream>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int *v = new int[1111111];
int *c = new int[1111111];
int a[1111111];

struct SegmentTree {
    int *a;

    SegmentTree(int n, int *x) {
        a = new int[4 * n];
        build(0, 0, n, x);
    }

    void build(int i, int l, int r, int *x) {
        if (l + 1 == r) {
            a[i] = x[l];
            return;
        }
        int m = (l + r) >> 1;
        build(i * 2 + 1, l, m, x);
        build(i * 2 + 2, m, r, x);
        a[i] = max(a[i * 2 + 1], a[i * 2 + 2]);
    }

    int get(int i, int l, int r, int ql, int qr) {
        if (l >= qr || r <= ql) {
            return -1e9 - 1;
        }
        if (ql <= l && r <= qr) {
            return a[i];
        }
        int m = (l + r) >> 1;
        return max(get(i * 2 + 1, l, m, ql, qr), get(i * 2 + 2, m, r, ql, qr));
    }
};

void gen() {
    srand(10);
    ofstream out("input.txt");
    int n = rand() % 1000 + 1;
    int k = rand() % n + 1;
    out << n << " " << k << "\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; ++j) {
            out << rand() % 10 << " ";
        }
        out << "\n";
    }
    out.close();
}

long double slow() {
    ifstream in("input.txt");
    int n, k;
    in >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        in >> v[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        in >> c[i];
    }
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        int cmv = 0, cmc = 1e9;
        for (int j = i; j < n; j++) {
            cmv = max(cmv, v[j]);
            cmc = min(cmc, c[j]);
            a[i] = max(a[i], min(cmv * 100, cmc));
        }
    }
    for (int i : a) {
        cerr << i << " ";
    }
    cerr << endl;
    sort(a.begin(), a.end());
    long double ans = 0;
    long double p = (long double) 1.0 * k / n;
    for (int i = 0; i + k <= n; i++) {
        ans += a[i] * p;
        p = p * (n - k - i) / (n - 1 - i);
    }
    in.close();
    return ans;
}

int main() {
//    gen();
//    long double slow_ans = slow();
//    cerr << slow_ans << endl;
//    freopen("input.txt", "r", stdin);
    sciid(n, k);
    for (int i = 0; i < n; i++) {
        sci(v[i]);
        v[i] *= 100;
    }
    for (int i = 0; i < n; i++) {
        sci(c[i]);
        c[i] = -c[i];
    }
    SegmentTree mxv(n, v);
    SegmentTree mnc(n, c);
    a[n - 1] = min(v[n - 1], -c[n - 1]);
    int cur = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        while (cur > i) {
            int t1 = mxv.get(0, 0, n, i, cur + 1);
            int t2 = -mnc.get(0, 0, n, i, cur + 1);
            if (t1 < t2) {
                break;
            }
            cur--;
        }
        int t11 = mxv.get(0, 0, n, i, cur + 1);
        int t21 = -mnc.get(0, 0, n, i, cur + 1);
        int t12 = cur + 2 <= n ? mxv.get(0, 0, n, i, cur + 2) : -1e9;
        int t22 = cur + 2 <= n ? -mnc.get(0, 0, n, i, cur + 2) : -1e9;
        a[i] = max(min(t11, t21), min(t12, t22));
    }
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
    sort(a, a + n);
    long double ans = 0;
    long double p = (long double) 1.0 * k / n;
    for (int i = 0; i + k <= n; i++) {
        ans += a[i] * p;
        p = p * (n - k - i) / (n - 1 - i);
    }
    cout.precision(11);
    cout << fixed << ans << endl;


    return 0;
}