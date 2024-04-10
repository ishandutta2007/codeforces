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

const int maxn = 1e5 + 5;
const int inf = 1e9;
int d[maxn];
vector<int> g[maxn];

int f[maxn];

int get(int v) {
    if (f[v] == v) {
        return v;
    }
    return f[v] = get(f[v]);
}

void unite(int u, int v) {
    u = get(u), v = get(v);
    if (u != v) {
        if (rand() & 1) {
            swap(u, v);
        }
        f[u] = v;
    }
}

void clear() {
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
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

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector<int> a;
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        a.pb(x);
    }

    vector<pair<int,int>> e;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e.pb(mp(u, v));
        g[u].pb(v);
        g[v].pb(u);
    }

    int s, t;
    scanf("%d %d", &s, &t);
    a.pb(t);

    int lo = 0, hi = maxn;
    while (hi - lo > 1) {
        int mid = (lo + hi) >> 1;

        clear();
        fill(d, d + maxn, inf);
        queue<int> q;
        for (int x : a) {
            d[x] = 0;
            q.push(x);
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (d[to] == inf) {
                    d[to] = d[v] + 1;
                    unite(to, v);
                    q.push(to);
                }
            }
        }

        for (auto p : e) {
            int u = p.fst, v = p.snd;
            if (get(u) != get(v)) {
                if (1 + d[u] + d[v] <= mid) {
                    unite(u, v);
                }
            }
        }

        if (get(s) == get(t)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }


    if (hi == maxn) {
        cout << -1 << endl;
    } else {
        cout << hi << endl;
    }


    return 0;
}