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

const int maxn = 55;
const int maxe = 1e4;
vector<pair<int,int>> g[maxn];
int lvl[maxn];
int f[maxe], c[maxe];
int ecnt = 0;
int ptr[maxn];

void clear() {
    for (int i = 0; i < maxn; i++) {
        g[i].clear();
    }
    fill(f, f + ecnt, 0);
    fill(c, c + ecnt, 0);
    ecnt = 0;
}

int s, t;

void add(int u, int v, int cc) {
    c[ecnt] = cc;
    g[u].pb(mp(v, ecnt));
    g[v].pb(mp(u, ecnt + 1));
    ecnt += 2;
}

bool bfs() {
    fill(lvl, lvl + maxn, -1);
    lvl[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : g[v]) {
            if (lvl[to.fst] != -1 || c[to.snd] == f[to.snd]) {
                continue;
            }
            lvl[to.fst] = lvl[v] + 1;
            q.push(to.fst);
        }
    }
    return lvl[t] != -1;
}

const int inf = 1e9;

int dfs(int v, int flow) {
    if (v == t || !flow) {
        return flow;
    }

    for (int &i = ptr[v]; i < g[v].size(); i++) {
        int to = g[v][i].fst;
        int ee = g[v][i].snd;
        if (lvl[to] != lvl[v] + 1 || f[ee] == c[ee]) {
            continue;
        }
        if (int res = dfs(to, min(flow, c[ee] - f[ee]))) {
            f[ee] += res;
            f[ee ^ 1] -= res;
            return res;
        }
    }
    return 0;
}

int flow() {
    int res = 0;
    while (true) {
        if (!bfs()) {
            break;
        }
        fill(ptr, ptr + maxn, 0);
        while (int c = dfs(s, inf)) {
            res += c;
        }
    }
    return res;
}

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif

    struct edge {
        int u, v, c;
    };

    vector<edge> ev;
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        ev.pb({u, v, c});
    }

    ld lo = 0, hi = 1e6 + 5;
    s = 1, t = n;

    for (int iter = 0; iter < 100; iter++) {
        ld mid = (lo + hi) / 2.0;

        clear();
        for (auto e : ev) {
            add(e.u, e.v, min(k, (ll)min(1e18l, e.c / mid)));
        }

        if (flow() >= k) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout.precision(20);
    cout << fixed << lo * k << endl;

    return 0;
}