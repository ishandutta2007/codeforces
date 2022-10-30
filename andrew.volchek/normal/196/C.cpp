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

//-----------------------------------------------------------------------------

const int maxn = 1505;

vector<int> g[maxn];
int sz[maxn];
vector<int> ch[maxn];

void dfs(int v, int p = -1) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }

        ch[v].pb(to);
        dfs(to, v);
        sz[v] += sz[to];
    }
}

struct pt {
    ll x, y;
    int id;

    pt(ll _x = 0, ll _y = 0, int _id = 0) {
        x = _x, y = _y, id = _id;
    }

    ll operator ^ (const pt &o) const {
        return x * o.y - y * o.x;
    }

    pt operator - (const pt &o) {
        return pt(x - o.x, y - o.y);
    }

    bool operator < (const pt &o) const {
        return mp(x, y) < mp(o.x, o.y);
    }

    bool operator == (const pt &o) const {
        return mp(x, y) == mp(o.x, o.y);
    }
};

int ans[maxn];

void solve(vector<pt> a, int r) {
    pt o = *min_element(a.begin(), a.end());
    ans[o.id] = r;

    remove_if(a.begin(), a.end(), [&](const pt &p) {
        return p == o;
    });

    a.resize(a.size() - 1);

    for (auto &p : a) {
        p.x -= o.x;
        p.y -= o.y;
    }

    sort(a.begin(), a.end(), [&](const pt &u, const pt &v) {
        return (u ^ v) < 0;
    });

    int p = 0;
    for (int x : ch[r]) {
        vector<pt> c;
        for (int i = p; i < p + sz[x]; i++) {
            c.pb(a[i]);
        }
        solve(c, x);
        p += sz[x];
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

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1);

    vector<pt> a;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.pb(pt(x, y, i));
    }

    solve(a, 1);

    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }

        cout << ans[i];
    }


    return 0;
}