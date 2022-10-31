#include <cstdio>
#include <set>
#include <ostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <assert.h>
#include <iomanip>
#include <map>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double


const ld pi = acos(-1);


template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
ostream& operator << (ostream &s, const vector<T> &x) {
    s << "[";
    for (typename vector<T>::const_iterator it = x.begin(); it != x.end(); ++it) {
        s << *it << ", ";
    }
    s << "]";
    return s;
}

template<typename T>
ostream& operator << (ostream &s, const set<T> &x) {
    s << "{";
    for (typename set<T>::iterator it = x.begin(); it != x.end(); ++it) {
        s << *it << ", ";
    }
    s << "}";
    return s;
}


template<typename U, typename V>
ostream& operator << (ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

//---------------------------------------------------------------------

const int maxn = 515;
const int maxe = 100 * 500 * 20;
const ll inf = 1e16;

ll f[maxe], c[maxe], p[maxe];
ll ph[maxn];
vector<pair<int,int>> g[maxn];
ll dist[maxn];
int pr[maxn], prE[maxn];
int s, t;

int ecnt;

void add(int u, int v, ll cc, ll pp) {
    g[u].pb(mp(v, ecnt));
    g[v].pb(mp(u, ecnt + 1));
    c[ecnt] = cc;
    p[ecnt] = pp;
    p[ecnt + 1] = -pp;
    ecnt += 2;
}

void bf() {
    fill(dist, dist + maxn, inf);
    dist[s] = 0;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            for (auto to : g[j]) {
                ll nd = dist[j] + p[to.snd];
                if (nd < dist[to.fst]) {
                    dist[to.fst] = nd;
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
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(mp(0, s));
    while (!q.empty()) {
        int v = q.top().snd;
        ll cd = q.top().fst;
        q.pop();
        if (dist[v] != cd) {
            continue;
        }
        for (auto tt : g[v]) {
            int to = tt.fst;;
            int ee = tt.snd;
            if (f[ee] == c[ee]) {
                continue;
            }
            ll nd = cd - ph[to] + ph[v] + p[ee];
            if (nd < dist[to]) {
                dist[to] = nd;
                pr[to] = v;
                prE[to] = ee;
                q.push(mp(nd, to));
            }
        }
    }

    for (int i = 0; i < maxn; i++) {
        ph[i] += (dist[i] == inf ? 0 : dist[i]);
    }
}

ll flow() {
    bf();
    while (true) {
        djkstra();
        if (dist[t] == inf) {
            break;
        }
        ll rr = inf;
        int v = t;
        ll delta = 0;
        while (v != s) {
            chmin(rr, c[prE[v]] - f[prE[v]]);
            delta += p[prE[v]];
            v = pr[v];
        }

        if (delta > 0) {
            break;
        }

        v = t;
        while (v != s) {
            f[prE[v]] += rr;
            f[prE[v] ^ 1] -= rr;
            v = pr[v];
        }
    }

    ll res = 0;
    for (int i = 0; i < ecnt; i += 2) {
        res += p[i] * f[i];
    }

    return -res;
}

int main() {

    retry:
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#else
    //freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

    s = maxn - 1, t = maxn - 2;

    int n;
    cin >> n;

    string cw;
    cin >> cw;

    int m;
    cin >> m;

    vector<pair<string, int>> a;
    for (int i = 0; i < m; i++) {
        int x;
        string s;
        cin >> s >> x;
        a.pb(mp(s, x));
    }

    int x;
    cin >> x;

    for (int i = 0; i < n; i++) {
        add(i, i + 1, x, 0);
    }

    add(s, 0, x, 0);
    add(n, t, x, 0);

    for (auto w : a) {
        for (int i = 0; i < n; i++) {
            if (cw.substr(i, w.fst.size()) == w.fst) {
                add(i, i + w.fst.size(), 1, -w.snd);
            }
        }
    }

    cout << flow() << endl;

    return 0;
}