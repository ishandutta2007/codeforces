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

struct Treap {
    int x, y;
    Treap *l, *r;
    int sz;

    Treap(int x) : x(x), y(rand()), l(0), r(0), sz(1) {
    }
};

typedef Treap *ptreap;

int get_sz(ptreap t) {
    if (!t) {
        return 0;
    }
    return t->sz;
}

void recalc(ptreap t) {
    if (t != 0) {
        t->sz = get_sz(t->l) + get_sz(t->r) + 1;
    }
}

ptreap *split(ptreap t, int x) {
    if (!t) {
        return new ptreap[2]{0, 0};
    }
    ptreap *r;
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

ptreap insert(ptreap t, int x) {
    ptreap *a = split(t, x);
    a[0] = merge(a[0], new Treap(x));
    return t = merge(a[0], a[1]);
}

struct seg {
    int st, en, id;

    bool operator<(const seg &r) const {
        return en < r.en;
    }
};

seg a[222222];
int ans[222222];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = seg{x, y, i};
    }
    sort(a, a + n);
    ptreap t = 0;
    for (int i = 0; i < n; i++) {
        seg s = a[i];
        ptreap *x = split(t, s.st);
        ans[s.id] = get_sz(x[1]);
        t = merge(x[0], x[1]);
        t = insert(t, s.st);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}