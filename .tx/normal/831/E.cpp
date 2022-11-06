#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

struct treap {
    int sz, y, v, mn;
    treap* l, *r;

    treap(int v) : sz(1), y(rand()), v(v), mn(v), l(0), r(0) {}
};

using ptreap = treap*;

int get_sz(ptreap t) {
    if (!t) {
        return 0;
    }
    return t->sz;
}

int get_mn(ptreap t) {
    if (!t) {
        return 1e9;
    }
    return t->mn;
}

void recalc(ptreap t) {
    if (t) {
        t->sz = get_sz(t->l) + get_sz(t->r) + 1;
        t->mn = min(t->v, min(get_mn(t->l), get_mn(t->r)));
    }
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

ptreap* split(ptreap t, int x) {
    if (!t) {
        return new ptreap[2] {0, 0};
    }
    int q = get_sz(t->l);
    ptreap* r;
    if (x <= q) {
        r = split(t->l, x);
        t->l = r[1];
        r[1] = t;
    } else {
        r = split(t->r, x - q - 1);
        t->r = r[0];
        r[0] = t;
    }
    recalc(t);
    return r;
}

int pmn(ptreap t, int mn) {
    if (!t) {
        return -1;
    }
    if (get_mn(t->l) == mn) {
        return pmn(t->l, mn);
    }
    if (t->v == mn) {
        return get_sz(t->l);
    }
    return pmn(t->r, mn) + get_sz(t->l) + 1;
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    ptreap t = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t = merge(t, new treap(x));
    }

    lint ans = 0;
    for (int i = 0; i < n; i++) {
        int p = pmn(t, get_mn(t));
        ans += p + 1;
        ptreap* a = split(t, p);
        ptreap* b = split(a[1], 1);
        t = merge(b[1], a[0]);
    }
    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//fejybk