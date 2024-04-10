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

const int maxn = 25;
vector<int> g[maxn];
ld p[maxn];
const ld eps = 1e-9;

vector<ld> gauss(vector<vector<ld>> a, vector<ld> b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && abs(a[j][i]) < eps) {
            j++;
        }

        if (j == n) {
            assert(0);
        }

        for (int h = 0; h < n; h++) {
            swap(a[i][h], a[j][h]);
        }
        swap(b[i], b[j]);

        for (int h = 0; h < n; h++) {
            if (h == i) {
                continue;
            }

            ld c = a[h][i] / a[i][i];
            for (int k = 0; k < n; k++) {
                a[h][k] -= c * a[i][k];
            }

            b[h] -= b[i] * c;
        }
    }

    for (int i = 0; i < n; i++) {
        b[i] /= a[i][i];
    }

    return b;
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
    //freopen("hovels.in", "r", stdin);
    //freopen("hovels.out", "w", stdout);
#endif

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    //n = 22, m = 21, s = 1, t = 22;


    if (s == t) {
        for (int i = 1; i <= n; i++) {
            cout << ((i == s) ? 1 : 0) << endl;
        }
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        //u = i + 1, v = i + 2;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        //p[i] = 0.99;
    }


    auto enc = [&](int i, int j) {
        return (i - 1) * n + (j - 1);
    };

    vector<vector<ld>> a(n * n + 1, vector<ld>(n * n + 1, 0));
    vector<ld> b(n * n + 1);

    for (int i = 0; i < n * n + 1; i++) {
        a[i][i] = 1;
    }

    b[n * n] = 1;

    auto gen = [&](int u, int v, bool s = false) {
        vector<pair<ld, pair<int,int>>> res;

        if (u == v && !s) {
            return res;
        }

        ld w = p[u] * p[v];
        res.pb(mp(w, mp(u, v)));

        w = (1 - p[u]) / g[u].size() * p[v];
        for (int to : g[u]) {
            res.pb(mp(w, mp(to, v)));
        }

        w = (1 - p[v]) / g[v].size() * p[u];
        for (int to : g[v]) {
            res.pb(mp(w, mp(u, to)));
        }

        w = (1 - p[u]) / g[u].size() * (1 - p[v]) / g[v].size();
        for (int to1 : g[u]) {
            for (int to2 : g[v]) {
                res.pb(mp(w, mp(to1, to2)));
            }
        }

        return res;
    };

    for (auto x : gen(s, t, true)) {
        a[enc(x.snd.fst, x.snd.snd)][n * n] -= x.fst;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto x : gen(i, j)) {
                a[enc(x.snd.fst, x.snd.snd)][enc(i, j)] -= x.fst;
            }
        }
    }

    //cout << a << endl;

    auto res = gauss(a, b);

    cout.precision(20);
    for (int i = 0; i < n; i++) {
        cout << fixed << res[enc(i + 1, i + 1)] << endl;
    }

    return 0;
}