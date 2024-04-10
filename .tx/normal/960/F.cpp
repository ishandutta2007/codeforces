#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

struct treap {
    int x, y, v, mx;
    treap *l, *r;

    treap(int x, int v) : x(x), y(rand()), v(v), mx(v), l(0), r(0) {}
};

using ptreap = treap*;

int get_mx(ptreap t) {
    return t ? t-> mx : 0;
}

void recalc(ptreap t) {
    if (t) {
        t->mx = max(t->v, max(get_mx(t->l), get_mx(t->r)));
    }
}

ptreap* split(ptreap t, int x) {
    if (!t) {
        return new ptreap[2] {0, 0};
    }
    ptreap* r;
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

ptreap insert(ptreap t, int x, int v) {
    ptreap* a = split(t, x);
    a[0] = merge(a[0], new treap(x, v));
    return merge(a[0], a[1]);
}

int get(ptreap t, int x) {
    ptreap* a = split(t, x);
    int res = get_mx(a[1]);
    merge(a[0], a[1]);
    return res;
}

struct edge {
    int f, t, w;
};

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    vector<ptreap> v(n);
    vector<edge> es(m);
    rep(i, 0, m) {
        cin >> es[i].f >> es[i].t >> es[i].w;
        --es[i].f;
        --es[i].t;
    }
    reverse(es.begin(), es.end());
    int ans = 0;
    for (auto e : es) {
        int x = get(v[e.t], e.w + 1) + 1;
        ans = max(ans, x);
        v[e.f] = insert(v[e.f], e.w, x);
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
}