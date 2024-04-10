#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

struct treap {
    int x, y;
    lint v, mx;
    treap *l, *r;
    treap(int x, lint v) : x(x), y(rand()), v(v), mx(v), l(0), r(0) {}
};

typedef treap* ptreap;

lint get_mx(ptreap t) {
    return t ? t->mx : 0;
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
        recalc(r[1]);
    } else {
        r = split(t->r, x);
        t->r = r[0];
        r[0] = t;
        recalc(r[0]);
    }
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

ptreap insert(ptreap t, int x, lint v) {
    ptreap* a = split(t, x);
    a[0] = merge(a[0], new treap(x, v));
    return merge(a[0], a[1]);
}

lint suf_mx(ptreap t, int x) {
    ptreap* a = split(t, x);
    lint res = get_mx(a[1]);
    merge(a[0], a[1]);
    return res;
}

struct item {
    int a, b, h;
};

item is[111111];

int main() {
    srand(31);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(is[i].a, is[i].b, is[i].h);
    }

    sort(is, is + n, [](auto x, auto y) {
        return x.b == y.b ? x.a < y.a : x.b < y.b;
    });

    ptreap t = 0;

    for (int i = 0; i < n; i++) {
        lint mx = suf_mx(t, is[i].a + 1);
        t = insert(t, is[i].b, is[i].h + mx);
    }

    cout << get_mx(t);


    return 0;
}