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
#include <numeric>
#include <future>

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

const ld pi = acos(-1.0);

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


//--------------------------------------------------------------------------

const int maxn = 1e5 + 5;
int dsu[maxn];
int find(int v) {
    if (dsu[v] == v) {
        return v;
    }
    return dsu[v] = find(dsu[v]);
}
void unite(int u, int v) {
    u = find(u), v = find(v);
    dsu[u] = v;
}

int main() {
    srand(time(0));

retry:
#ifdef LOCAL
    //gen();
    //return 0;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif
    iota(dsu, dsu + maxn, 0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    set<int> fi;
    auto die = []() {
        cout << -1 << endl;
        exit(0);
    };
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == a[i]) {
            fi.insert(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!fi.count(a[i])) {
            die();
        }
    }

    int m = fi.size();
    vector<int> h(m + 1);
    auto it = fi.begin();
    for (int i = 0; i < m; i++, it++) {
        h[i + 1] = *it;
    }

    for (int i = 1; i <= n; i++) {
        unite(i, a[i]);
    }

    vector<int> g(n + 1);
    map<int, vector<int>> p;
    for (int i = 1; i <= n; i++) {
        p[find(i)].pb(i);
    }

    set<int> was;
    for (int i = 1; i <= m; i++) {
        int x = h[i];
        if (was.count(find(x))) {
            die();
        }
        was.insert(find(x));
        for (int y : p[find(x)]) {
            g[y] = i;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (g[h[i]] != i) {
            die();
        }
    }

    for (int i = 1; i <= m; i++) {
        if (!(1 <= g[i] && g[i] <= m)) {
            die();
        }
        if (h[g[i]] != a[i]) {
            die();
        }
    }

    cout << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << g[i] << " " ;
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        cout << h[i] << " ";
    }
    cout << endl;

    return 0;
}