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
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
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

const int maxn = 405;
const int maxe = 1000000;
const ll inf = 1e18;
ll f[maxe], c[maxe], p[maxe];
ll ph[maxn];

ll dist[maxn];
int s, t;

int ecnt;
vector<pair<int, int>> g[maxn];

int prV[maxn], prE[maxn];

int newS = maxn - 3, newT = maxn - 4;

void add(int u, int v, int cc, int pp) {
    g[u].pb(mp(v, ecnt));
    c[ecnt] = cc;
    g[v].pb(mp(u, ecnt + 1));
    p[ecnt] = pp;
    p[ecnt + 1] = -pp;
    ecnt += 2;
}

void ford() {
    fill(dist, dist + maxn, inf);
    dist[newS] = 0;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            for (auto to : g[i]) {
                if (dist[to.fst] > dist[i] + p[to.snd] && f[to.snd] < c[to.snd]) {
                    dist[to.fst] = dist[i] + p[to.snd];
                }
            }
        }
    }

    for (int i = 0; i < maxn; i++) {
        ph[i] = dist[i];
    }
}

void djkstra() {
    fill(dist, dist + maxn, inf);
    dist[newS] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(mp(0, newS));

    while (!q.empty()) {
        int v = q.top().snd;
        ll cd = q.top().fst;
        q.pop();

        if (dist[v] != cd) {
            continue;
        }

        for (auto to : g[v]) {
            if (f[to.snd] == c[to.snd]) {
                continue;
            }

            ll nd = dist[v] + ph[v] - ph[to.fst] + p[to.snd];
            if (nd < dist[to.fst]) {
                dist[to.fst] = nd;
                prV[to.fst] = v;
                prE[to.fst] = to.snd;
                q.push(mp(nd, to.fst));
            }
        }
    }

    for (int i = 0; i < maxn; i++) {
        ph[i] += (dist[i] == inf ? 0 : dist[i]);
    }
}

ll flow() {
    ford();
    while (true) {
        djkstra();
        if (dist[newT] == inf) {
            break;
        }

        int v = newT;
        ll rr = inf;
        while (v != newS) {
            rr = min(rr, c[prE[v]] - f[prE[v]]);
            v = prV[v];
        }
        //cout << " rr" << rr << endl;

        v = newT;
        while (v != newS) {
            f[prE[v]] += rr;
            //cout << p[prE[v]]  << " " << p[prE[v] ^ 1]<< endl;
            f[prE[v] ^ 1] -= rr;
            v = prV[v];
        }
    }

    ll cost = 0;
    for (int i = 0; i < ecnt; i += 2) {
        cost += f[i] * p[i];
        //cout << f[i] << " " << p[i] << endl;
    }

    return cost;
}

struct edge {
    int u, v, c, f;
};

ll bal[maxn];



void add2(int u, int v, int p, int l, int r) {
    add(newS, v, l, 0);
    add(u, newT, l, 0);
    add(u, v, r - l, p);
}

int dsu[maxn];
int find(int v) {
    if (dsu[v] == v) {
        return v;
    }
    return dsu[v] = find(dsu[v]);
}

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
   // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<edge> e;

    iota(dsu, dsu + maxn, 0);

    for (int i = 0; i < m; i++) {
        int u, v, c, f;
        cin >> u >> v >> c >> f;
        dsu[find(u)] = find(v);
        e.pb({u, v, c, f});
        bal[u] -= f;
        bal[v] += f;
    }

    s = maxn - 1, t = maxn - 2;

    for (int i = 2; i < n; i++) {


        if (bal[i] < 0) {
            add2(i, t, 0, -bal[i], -bal[i]);
        } else if (bal[i] > 0) {
            add2(s, i, 0, bal[i], bal[i]);
        } else if (bal[i] == 0) {
            //add2(s, i, 0, 0, 1e9);
            //add2(i, t, 0, 0, 1e9);
        }
    }



    add2(s, 1, 0, 0, 1e9);
    add2(1, t, 0, 0, 1e9);
    add2(s, n, 0, 0, 1e9);
    add2(n, t, 0, 0, 1e9);

    add(t, s, 1e9, 0);

    ll ans = 0;

    for (auto ee : e) {
        if (ee.f <= ee.c) {
            add2(ee.v, ee.u, 1, 0, ee.f);
            add2(ee.u, ee.v, 1, 0, ee.c - ee.f);
            add2(ee.u, ee.v, 2, 0, 1e9);
        } else {
            ans += ee.f - ee.c;
            add2(ee.v, ee.u, 0, 0, ee.f - ee.c);
            add2(ee.v, ee.u, 1, 0, ee.c);
            add2(ee.u, ee.v, 2, 0, 1e9);
        }
    }

    ans += flow();

    cout << ans << endl;

    return 0;
}