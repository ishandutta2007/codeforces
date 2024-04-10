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
#include <limits>
#include <tuple>
#include <complex>

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

const ld pi = acos(-1.0l);

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

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

struct node {
    map<char, node*> nxt;
    node *lnk;
    node *parent;
    char pch;
    ll s;
    node() {
        lnk = nullptr;
        s = 0;
    }
};

node *root = new node();
map<node*, int> o({mp(root, 0)});
void add(const string &s, ll score) {
    node *v = root;
    for (char c : s) {
        if (!v->nxt.count(c)) {
            v->nxt[c] = new node();
            v->nxt[c]->parent = v;
            v->nxt[c]->pch = c;
            int n = o.size();
            o[v->nxt[c]] = n;
        }
        v = v->nxt[c];
    }
    v->s += score;
}

node *go(node *v, char c);

node *getLnk(node *v) {
    if (!v->lnk) {
        if (v == root || v->parent == root) {
            v->lnk = root;
        } else {
            v->lnk = go(getLnk(v->parent), v->pch);
            getLnk(v->lnk);
            v->s += v->lnk->s;
        }
    }
    return v->lnk;
}

node *go(node *v, char c) {

    if (!v->nxt.count(c)) {

        if (v == root) {
            v->nxt[c] = root;
        } else {
            v->nxt[c] = go(getLnk(v), c);
        }
    }
    return v->nxt[c];
}


const int maxn = 205;
const ll inf = 3e18;

struct M {
    ll a[maxn][maxn];
    M() {
        for (int i = 0; i < maxn; i++) {
            fill(a[i], a[i] + maxn, 0);
        }
    }
    M operator * (const M &rhs) const {
        M res;
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                ll x = -inf;
                for (int h = 0; h < maxn; h++) {
                    chmax(x, a[i][h] + rhs.a[h][j]);
                }
                res.a[i][j] = x;
            }
        }
        return res;
    }
};

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif

    int n;
    ll m;
    cin >> n >> m;
    vector<ll> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        //cout << x << endl;
        add(x, cost[i]);
    }


    M x;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            x.a[i][j] = -inf;
        }
    }
    map<int, node*> io;
    for (auto kv : o) {
        io[kv.snd] = kv.fst;
    }

    for (int i = 0; i < o.size(); i++) {
        {
            for (char c = 'a'; c <= 'z'; c++) {
                //cout << i << " " << c << endl;
                auto to = go(io[i], c);
                getLnk(to);
                chmax(x.a[o[to]][i], to->s);
            }
        }
    }


    M res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.a[i][j] = i == j ? 0 : -inf;
        }
    }

    while (m) {
        if (m & 1) {
            res = res * x;
        }
        x = x * x;
        m >>= 1;
    }

    ll ans = -inf;
    for (int i = 0; i < o.size(); i++) {
        chmax(ans, res.a[i][0]);
    }

    cout << ans << endl;



    return 0;
}