#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}


//-----------------------------------------------------------------------------

struct MV {
    vector<pair<ll, int>> v;
    ll add;
    MV() {
        add = 0;
    }

    MV(int id) {
        v.pb(mp(0, id));
        add = 0;
    }
};

MV *merge(MV *a, MV *b) {
    if (a->v.size() > b->v.size()) {
        swap(a, b);
    }

    for (auto p : a->v) {
        b->v.pb(mp(p.fst + a->add - b->add, p.snd));
    }

    delete a;
    return b;
}

struct node {
    ll key;
    int pr;
    MV *v;
    node *l, *r;
    node() {
        pr = rand();
        l = r = nullptr;
    }
};

typedef node* pnode;

pnode merge(pnode l, pnode r) {
    if (!l || !r) {
        return l ? l : r;
    }

    if (l->pr < r->pr) {
        l->r = merge(l->r, r);
        return l;
    } else {
        r->l = merge(l, r->l);
        return r;
    }
}

void split(pnode v, pnode &l, pnode &r, ll key) {
    if (!v) {
        l = r = nullptr;
        return;
    }

    if (v->key <= key) {
        l = v;
        split(v->r, l->r, r, key);
    } else {
        r = v;
        split(v->l, l, r->l, key);
    }
}


pnode root = nullptr;

void insert(pnode v) {
    v->l = v->r = nullptr;
    pnode l, c, r;
    split(root, l, r, v->key - 1);
    split(r, c, r, v->key);

    if (c) {
        c->v = merge(c->v, v->v);
    } else {
        c = v;
    }

    root = merge(l, merge(c, r));
}

vector<pnode> get(ll lb, ll ub) {
    pnode l, c, r;
    split(root, l, r, lb - 1);
    split(r, c, r, ub);

    vector<pnode> res;
    queue<pnode> q;
    q.push(c);
    while (!q.empty()) {
        pnode v = q.front();
        q.pop();
        if (!v) {
            continue;
        }

        res.pb(v);
        q.push(v->l);
        q.push(v->r);
    }

    root = merge(l, r);

    return res;
}


int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif



    int n;
    ll g, r;
    cin >> n >> g >> r;

    vector<ll> a;
    for (int i = 0; i < n + 1; i++) {
        int x;
        scanf("%d", &x);
        a.pb(x);
    }

    int q;
    scanf("%d", &q);
    vector<ll> s;
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        s.pb(x);
        x %= g + r;
        pnode v = new node();
        v->v = new MV(i);
        v->key = x;
        insert(v);
    }

    const ll mod = g + r;

    ll sl = 0;
    for (int i = 0; i < n; i++) {
        sl += a[i];

        ll l = g, rr = g + r - 1;

        l = (l - sl) % mod;
        if (l < 0) {
            l += mod;
        }

        rr = (rr - sl) % mod;
        if (rr < 0) {
            rr += mod;
        }

        vector<pnode> cu;

        if (l <= rr) {
            cu = get(l, rr);
        } else {
            cu = get(0, rr);
            auto cu2 = get(l, mod - 1);
            for (auto x : cu2) {
                cu.pb(x);
            }
        }

        for (auto x : cu) {
            ll add = mod - ((x->key + sl) % mod);
            x->v->add += add;
            x->key = (mod - (sl % mod)) % mod;
            insert(x);
        }
    }

    sl += a.back();

    auto cu = get(-1e18, 1e18);

    for (auto x : cu) {
        for (auto y : x->v->v) {
            s[y.snd] += sl + y.fst + x->v->add;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << s[i] << endl;
    }

    return 0;
}