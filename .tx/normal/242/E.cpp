#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

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

int a[111111];

struct SegmentTree {
    int *t;
    bool *inv;

    SegmentTree() {}

    SegmentTree(int n, int p) {
        t = new int[4 * n];
        inv = new bool[4 * n];
        memset(t, 0, sizeof(int) * 4 * n);
        memset(inv, 0, sizeof(bool) * 4 * n);
        build(0, 0, n, p);
    }

    void build(int i, int l, int r, int p) {
        if (l + 1 == r) {
            t[i] = (a[l] >> p) & 1;
        } else {
            int m = (l + r) >> 1;
            build(i * 2 + 1, l, m, p);
            build(i * 2 + 2, m, r, p);
            t[i] = t[i * 2 + 1] + t[i * 2 + 2];
        }
    }

    void push(int i, int l, int r) {
        if (inv[i]) {
            t[i] = r - l - t[i];
            if (l + 1 != r) {
                inv[i * 2 + 1] ^= true;
                inv[i * 2 + 2] ^= true;
            }
            inv[i] = false;
        }
    }

    int getSum(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (r <= ql || l >= qr) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return t[i];
        }
        int m = (l + r) >> 1;
        return getSum(i * 2 + 1, l, m, ql, qr) + getSum(i * 2 + 2, m, r, ql, qr);
    }

    void doInv(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (r <= ql || l >= qr) {
            return;
        }
        if (ql <= l && r <= qr) {
            inv[i] ^= true;
            push(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        doInv(i * 2 + 1, l, m, ql, qr);
        doInv(i * 2 + 2, m, r, ql, qr);
        t[i] = t[i * 2 + 1] + t[i * 2 + 2];
    }
};

SegmentTree* st[22];

int main() {
    scid(n);
    rea(a, n);
    for (int i = 0; i < 22; i++) {
        st[i] = new SegmentTree(n, i);
    }

    scid(m);
    while (m-- > 0) {
        sciiid(t, l, r);
        --l; --r;
        if (t == 1) {
            lint res = 0;
            lint cp = 1;
            for (int i = 0; i < 22; i++) {
                res += st[i]->getSum(0, 0, n, l, r + 1) * cp;
                cp *= 2;
            }
            cout << res << "\n";
        } else {
            scid(x);
            for (int i = 0; i < 22; i++) {
                if (x & (1 << i)) {
                    st[i]->doInv(0, 0, n, l, r + 1);
                }
            }
        }
    }


    return 0;
}