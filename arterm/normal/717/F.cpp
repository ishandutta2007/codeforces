#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
#define fore(i, b, e) for (int i = b; i <= e; ++i)

struct E {
    i64 a, b;
    i64 minx, maxx;
    int mn;

    E() : a(100) {}

    E(int val) : a(-1), b(val), minx(0), maxx(val), mn(val) {}

    E(const E& l, const E& r) {
        if (l.a == 100) { *this = r; return; }
        if (r.a == 100) { *this = l; return; }
        a = l.a * r.a;
        b = r.a * l.b + r.b;

        if (l.a == 1) {
            minx = max(l.minx, r.minx - l.b);
            maxx = min(l.maxx, r.maxx - l.b);
        } else {
            minx = max(l.minx, l.b - r.maxx);
            maxx = min(l.maxx, l.b - r.minx);
        }

        mn = min(l.mn, r.mn);
    }

    void add(int val) {
        if (a == -1) b += val;
        maxx += val;
        mn += val;
    }

    bool obossan() const {
        return mn < 0 || minx > maxx;
    }
};

const int maxn = 200500;

struct node {
    int l, r;
    node *L, *R;
    E e;
    int add;

    node(int l, int r, int a[]) : l(l), r(r), add(0) {
        if (l == r) {
            L = R = NULL;
            e = E(a[l]);
        } else {
            L = new node(l, (l+r)/2, a);
            R = new node((l+r)/2+1, r, a);
            e = E(L->e, R->e);
        }
    }

    void push() {
        if (add) {
            if (L) {
                L->add += add;
                R->add += add;
            }
            e.add(add);
            add = 0;
        }
    }

    E get() const {
        if (add) {
            E t(e);
            t.add(add);
            return t;
        }
        return e;
    }

    E get(int lq, int rq) {
        if (lq <= l && rq >= r) {
            return get();
        } else if (lq > r || rq < l) {
            return E();
        } else {
            push();
            return E(L->get(lq, rq), R->get(lq, rq));
        }
    }

    void paint(int lq, int rq, int val) {
        if (lq <= l && rq >= r) {
            add += val;
        } else if (lq > r || rq < l) {
        } else {
            push();
            L->paint(lq, rq, val);
            R->paint(lq, rq, val);
            e = E(L->get(), R->get());
        }
    }
};

int n;
int a[maxn];
node *t;

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]), --a[i];
    t = new node(0, n-1, a);
}

void paintstupid(int l, int r, int val) {
    for (int i = l; i <= r; ++i) a[i] += val;
}

void solve() {
    int q;
    scanf("%d", &q);
    forn(i, q) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            t->paint(l, r, k);
#ifdef LOCAL
            //paintstupid(l, r, k);
#endif
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            E e = t->get(l, r);
            //cerr << l << " " << r << endl;
            //fore(i, l, r) cerr << a[i] << " "; cerr << endl;
            //cerr << e.a << " " << e.b << " " << e.minx << " " << e.maxx << " " << e.mn << endl;
            printf("%d\n", (!e.obossan() && e.b == 0) ? 1 : 0);
        }
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif

                    scan();
        solve();

}