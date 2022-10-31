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
#define ld double
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

const ll inf = 1e17;

void djkstra(int s, const vector<vector<pair<ll, int>>> &g, vector<ll> &dist) {
    int n = g.size();
    fill(dist.begin(), dist.end(), inf);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> q;
    q.push(mp(0, s));
    while (!q.empty()) {
        int v = q.top().snd;
        ll cd = q.top().fst;
        q.pop();
        if (dist[v] != cd) {
            continue;
        }
        for (auto to : g[v]) {
            ll nd = cd + to.snd;
            if (dist[to.fst] > nd) {
                dist[to.fst] = nd;
                q.push(mp(nd, to.fst));
            }
        }
    }
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

    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    x--, y--;

    vector<vector<pair<ll, int>>> g(n), ng(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }

    for (int i = 0; i < n; i++) {
        int t, c;
        scanf("%d %d", &t, &c);

        vector<ll> dist(n);
        djkstra(i, g, dist);

        for (int j = 0; j < n; j++) {
            if (dist[j] <= t) {
                ng[i].pb(mp(j, c));
            }
        }
    }

    vector<ll> dist(n);
    djkstra(x, ng, dist);

    if (dist[y] == inf) {
        cout << -1 << endl;
    } else {
        cout << dist[y] << endl;
    }

    return 0;
}