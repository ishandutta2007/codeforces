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

const int maxn =  3e5 + 5;

int dsu[maxn];
int sz[maxn];

set<int> cf[maxn];

int find(int v) {
    if (dsu[v] == v) {
        return v;
    }
    return dsu[v] = find(dsu[v]);
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        dsu[u] = v;
        vector<int> del;
        for (int x : cf[u]) {
            if (!cf[v].count(x)) {
                del.pb(x);
            }
        }
        for (int x : del) {
            cf[u].erase(x);
        }
        cf[v].swap(cf[u]);
        cf[u].clear();

        sz[v] += sz[u];
        return true;
    }
    return false;
}

set<int> f[maxn];

void die() {
    cout << "impossible" << endl;
    exit(0);
}

int used[maxn];

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

    iota(dsu, dsu + maxn, 0);
    fill(sz, sz + maxn, 1);


    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        f[u].insert(v);
        f[v].insert(u);
    }

    for (int i = 1; i <= n; i++) {
        cf[i] = f[i];
    }

    if (n - 1 - f[1].size() < k) {
        die();
    }


    set<int> b = f[1];
    queue<int> q;
    for (int i = 2; i <= n; i++) {
        if (!f[1].count(i)) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        int i = 2;
        while (i <= n && b.size()) {


            if (b.lower_bound(i) == b.end()) {
                break;
            }
            i = *b.lower_bound(i);

            if (!f[v].count(i)) {
                q.push(i);
                unite(v, i);
                b.erase(i);
            }

            i++;
        }
    }


    if (b.size()) {
        die();
    }

    for (int i = 2; i <= n; i++) {
        if (used[find(i)]) {
            continue;
        }

        int v = find(i);
        used[v] = 1;
        for (int j = 2; j <= n; j++) {
            if (find(j) == v) {
                continue;
            }

            if (cf[v].count(j)) {
                continue;
            }

            unite(v, j);
            v = find(v);
            used[v] = 1;
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (find(i) == i) {
            cnt ++;
        }
    }

    if (cnt > k) {
        die();
    }

    cout << "possible" << endl;

    return 0;
}