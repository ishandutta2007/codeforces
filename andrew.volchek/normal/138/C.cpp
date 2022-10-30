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


const int maxn = 4e5 + 5;

ld tr[maxn * 4];


void modify(int v, int l, int r, int i, int j, ld val) {
    if (i <= l && r <= j) {
        tr[v] *= val;
        return;
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        modify(2 * v, l, c, i, j, val);
    }

    if (c < j) {
        modify(2 * v + 1, c + 1, r, i, j, val);
    }
}

ld get(int v, int l, int r, int i) {
    if (l == r) {
        return tr[v];
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        return tr[v] * get(2 * v, l, c, i);
    } else {
        return tr[v] * get(2 * v + 1, c + 1, r, i);
    }
}


int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    // gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    fill(tr, tr + maxn * 4, 1.0);

    struct tree {
        int a, h, l, r;
    };

    struct mushroom {
        int b, z;
    };


    vector<int> cc;

    int n, m;
    scanf("%d %d", &n, &m);

    vector<tree> f;
    vector<mushroom> g;

    for (int i = 0; i < n; i++) {
        int a, h, l, r;
        scanf("%d %d %d %d", &a, &h, &l, &r);
        f.pb({a, h, l, r});
        cc.pb(a);
        cc.pb(a + h);
        cc.pb(a - h);
    }

    for (int i = 0; i < m; i++) {
        int b, z;
        scanf("%d %d", &b, &z);
        cc.pb(b);
        g.pb({b, z});
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    for (int i = 0; i < n; i++) {
        int x = lower_bound(cc.begin(), cc.end(), f[i].a - f[i].h) - cc.begin();
        int y = lower_bound(cc.begin(), cc.end(), f[i].a) - cc.begin();
        int z = lower_bound(cc.begin(), cc.end(), f[i].a + f[i].h) - cc.begin();

        modify(1, 0, maxn - 1, x, y - 1, 1.0 - f[i].l / 100.0);
        modify(1, 0, maxn - 1, y + 1, z, 1.0 - f[i].r / 100.0);
    }

    ld ans = 0.0;

    for (int i = 0; i < m; i++) {
        int b = lower_bound(cc.begin(), cc.end(), g[i].b) - cc.begin();
        ans += g[i].z * get(1, 0, maxn - 1, b);
    }

    cout.precision(12);
    cout << fixed << ans << endl;

    return 0;
}