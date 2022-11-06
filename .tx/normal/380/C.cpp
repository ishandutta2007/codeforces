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

static const int N = 1111111;

char s[N];

struct SegmentTree {
    int* co;
    int* cc;
    int* cr;
    int n;

    SegmentTree(int n) : n(n) {
        co = new int[4 * n];
        cc = new int[4 * n];
        cr = new int[4 * n];

        build(0, 0, n);
    }

    void build(int i, int l, int r) {
        if (l + 1 == r) {
            if (s[l] == '(') {
                co[i] = 1;
                cc[i] = 0;
            } else {
                co[i] = 0;
                cc[i] = 1;
            }
            cr[i] = 0;
            return;
        }
        int m = (l + r) >> 1;
        build(i * 2 + 1, l, m);
        build(i * 2 + 2, m, r);
        int t = min(co[i * 2 + 1], cc[i * 2 + 2]);
        cr[i] = cr[i * 2 + 1] + cr[i * 2 + 2] + t;
        co[i] = co[i * 2 + 1] - t + co[i * 2 + 2];
        cc[i] = cc[i * 2 + 1] + cc[i * 2 + 2] - t;
    }

    int get(int i, int l, int r, int ql, int qr, int& o, int& c) {
        if (l >= qr || r <= ql) {
            o = c = 0;
            return 0;
        }
        if (ql <= l && r <= qr) {
            o = co[i];
            c = cc[i];
            return cr[i];
        }
        int m = (l + r) >> 1;
        int lo, ro, lc, rc;
        int lr = get(i * 2 + 1, l, m, ql, qr, lo, lc);
        int rr = get(i * 2 + 2, m, r, ql, qr, ro, rc);

        int t = min(lo, rc);
        int ir = lr + rr + t;
        o = lo - t + ro;
        c = lc + rc - t;
        return ir;
    }
};

int main() {
    scanf("%s", s);
    int n = strlen(s);
    SegmentTree st(n);
    scid(m);
    int t1, t2;
    while (m-- > 0) {
        sciid(x, y);
        cout << st.get(0, 0, n, --x, y, t1, t2) * 2 << "\n";
    }


    return 0;
}