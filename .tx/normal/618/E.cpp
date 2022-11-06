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
typedef long double ldouble;

using namespace std;

struct SegmentTree {
    ldouble* len;
    ldouble* ang;
    ldouble* addAng;

    SegmentTree(int n) {
        len = new ldouble[4 * n];
        ang = new ldouble[4 * n];
        addAng = new ldouble[4 * n];
        build(0, 0, n);
    }

    void recalc(int i) {
        int ls = i * 2 + 1, rs = i * 2 + 2;
        ldouble x = len[ls] * cos(ang[ls]) + len[rs] * cos(ang[rs]);
        ldouble y = len[ls] * sin(ang[ls]) + len[rs] * sin(ang[rs]);
        len[i] = sqrt(x * x + y * y);
        ang[i] = atan2(y, x);
    }

    void build(int i, int l, int r) {
        addAng[i] = 0;
        if (l + 1 == r) {
            len[i] = 1;
            ang[i] = 0;
            return;
        }
        int m = (l + r) >> 1;
        build(i * 2 + 1, l, m);
        build(i * 2 + 2, m, r);
        recalc(i);
    }

    void push(int i, int l, int r) {
        ang[i] += addAng[i];
        if (l + 1 != r) {
            addAng[i * 2 + 1] += addAng[i];
            addAng[i * 2 + 2] += addAng[i];
        }
        addAng[i] = 0;
    }

    void add(int i, int l, int r, int ql, int qr, ldouble x) {
        push(i, l, r);
        if (r <= ql || l >= qr) {
            return;
        }
        if (ql <= l && r <= qr) {
            addAng[i] += x;
            push(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        add(i * 2 + 1, l, m, ql, qr, x);
        add(i * 2 + 2, m, r, ql, qr, x);
        recalc(i);
    }

    void addLen(int i, int l, int r, int q, ldouble x) {
        push(i, l, r);
        if (l + 1 == r) {
            len[i] += x;
            return;
        }
        int m = (l + r) >> 1;
        if (q < m) {
            addLen(i * 2 + 1, l, m, q, x);
        } else {
            addLen(i * 2 + 2, m, r, q, x);
        }
        push(i * 2 + 1, l, m);
        push(i * 2 + 2, m, r);
        recalc(i);
    }

    void get(ldouble& rLen, ldouble& rAng) {
        rLen = len[0];
        rAng = ang[0];
    }
};

const ldouble PI = acos(-1.0);

int main() {
    sciid(n, m);
    SegmentTree st(n);
    while (m-- > 0) {
        sciiid(x, y, z);
        if (x == 1) {
            st.addLen(0, 0, n, y - 1, z);
        } else {
            st.add(0, 0, n, y - 1, n, -PI * z / 180.0);
        }
        ldouble len, ang;
        st.get(len, ang);
        printf("%.11f %.11f\n", (double) (len * cos(ang)), (double) (len * sin(ang)));
    }

    return 0;
}