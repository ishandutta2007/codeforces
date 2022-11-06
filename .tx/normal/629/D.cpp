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

struct Treap {
    Treap *l, *r;
    lint x, v, mx;
    int y;

    Treap(lint x, lint v) : x(x), v(v) {
        mx = v;
        y = rand();
        l = r = 0;
    }
};

typedef Treap* ptreap;

lint getMax(ptreap t) {
    if (t) {
        return t->mx;
    }
    return 0;
}

void recalc(ptreap t) {
    if (t) {
        t->mx = max(t->v, max(getMax(t->l), getMax(t->r)));
    }
}

ptreap* split(ptreap t, lint x) {
    if (!t) {
        return new ptreap[2] {0, 0};
    }
    ptreap* r = 0;
    if (x <= t->x) {
        r = split(t->l, x);
        t->l = r[1];
        r[1] = t;
    } else {
        r = split(t->r, x);
        t->r = r[0];
        r[0] = t;
    }
    recalc(r[0]);
    recalc(r[1]);
    return r;
}

ptreap merge(ptreap l, ptreap r) {
    if (!l || !r) {
        return l ? l : r;
    }
    ptreap t;
    if (l->y < r->y) {
        l->r = merge(l->r, r);
        t = l;
    } else {
        r->l = merge(l, r->l);
        t = r;
    }
    recalc(t);
    return t;
}

ptreap insert(ptreap t, lint x, lint v) {
    ptreap* a = split(t, x);
    a[0] = merge(a[0], new Treap(x, v));
    return t = merge(a[0], a[1]);
}

int main() {
    scid(n);
    ptreap t = 0;
    for (int i = 0; i < n; i++) {
        sciid(r, h);
        lint x = 1LL * r * r * h;
        ptreap* a = split(t, x);
        lint cm = getMax(a[0]) + x;
        t = merge(a[0], a[1]);
        t = insert(t, x, cm);
    }
    printf("%.11f", acos(-1.0) * getMax(t));

    return 0;
}