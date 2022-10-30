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

const int maxn = 3e5 + 5;
const int inf = 1e9 + 5;

int sz[maxn], dsu[maxn];
int oddCnt;

vector<pair<int,int>> dsuHistory, szHistory;
vector<int> oddCntHistory;

void init() {
    for (int i = 0; i < maxn; i++) {
        dsu[i] = i;
        sz[i] = 1;
    }
    oddCnt = 0;
}

int find(int v) {
    if (dsu[v] == v) {
        return v;
    }

    int r = find(dsu[v]);
    if (r != dsu[v]) {
        dsuHistory.pb(mp(v, dsu[v]));
        dsu[v] = r;
    }

    return r;
}

void unite(int u, int v) {
    u = find(u), v = find(v);

    if (u == v) {
        return;
    }

    if ((sz[u] & 1) && (sz[v] & 1)) {
        oddCntHistory.pb(oddCnt);
        oddCnt += 2;
    }

    if (sz[u] > sz[v]) {
        swap(u, v);
    }

    dsuHistory.pb(mp(u, dsu[u]));
    dsu[u] = v;

    szHistory.pb(mp(v, sz[v]));
    sz[v] += sz[u];
}

void rollback(tuple<int, int, int> lim) {
    while (dsuHistory.size() > get<0>(lim)) {
        dsu[dsuHistory.back().fst] = dsuHistory.back().snd;
        dsuHistory.pop_back();
    }

    while (szHistory.size() > get<1>(lim)) {
        sz[szHistory.back().fst] = szHistory.back().snd;
        szHistory.pop_back();
    }

    while (oddCntHistory.size() > get<2>(lim)) {
        oddCnt = oddCntHistory.back();
        oddCntHistory.pop_back();
    }
}

struct edge {
    int u, v, cost, id;
    bool operator < (const edge &rhs) const {
        return cost < rhs.cost;
    }
};

tuple<int,int,int> stamp() {
    return make_tuple(dsuHistory.size(), szHistory.size(), oddCntHistory.size());
};

vector<edge> edgesByCost[maxn];
vector<edge> edges;
int ans[maxn];
int n, m;

void rec(int l, int r, int lb, int ub) {
    if (l > r || lb > ub) {
        return;
    }

    int c = (l + r) >> 1;

    int cb = -1;

    auto lim = stamp();

    for (int i = l; i <= c; i++) {
        if (edges[i].cost < lb) {
            unite(edges[i].u, edges[i].v);
        }
    }

    auto lim2 = stamp();

    for (int i = lb; i <= ub && cb == -1; i++) {
        for (auto e : edgesByCost[i]) {
            if (e.id > c) {
                break;
            }

            unite(e.u, e.v);

            if (oddCnt == n) {
                cb = i;
                break;
            }
        }
    }

    if (cb == -1) {
        rollback(lim2);
        rec(c + 1, r, lb, ub);
        return;
    }


    ans[c] = cb;

    rollback(lim2);

    rec(c + 1, r, lb, cb - 1);

    rollback(lim);

    for (int i = lb; i <= cb; i++) {
        for (auto e : edgesByCost[i]) {
            if (e.id >= l) {
                break;
            }

            unite(e.u, e.v);
        }
    }

    rec(l, c - 1, cb, ub);


}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    scanf("%d %d", &n, &m);

    init();

    vector<int> cc({inf});
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.pb({u, v, w, i});
        cc.pb(w);
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    for (auto &e : edges) {
        e.cost = lower_bound(cc.begin(), cc.end(), e.cost) - cc.begin();
        edgesByCost[e.cost].pb(e);
    }

    fill(ans, ans + maxn, cc.size() - 1);

    rec(0, m - 1, 0, cc.size() - 1);

    int f = cc.size() - 1;

    for (int i = 0; i < m; i++) {
        chmin(f, ans[i]);
        printf("%d\n", cc[f] == inf ? -1 : cc[f]);
    }

    return 0;
}