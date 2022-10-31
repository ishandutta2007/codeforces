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

struct z {
    ull d;
    ull r;
    ull m;
    ull p;
    int id;

    z() {
        d = r = m = p = id = 0;
    }

    bool operator < (const z &o) const {
        return mp(m, id) < mp(o.m, o.id);
    }
};

const int maxn = 5e5 + 5;

vector<pair<int,int>> t[maxn * 4];
int ptr[maxn * 4];

int used[maxn];

vector<pair<int,int>> arr[maxn];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = arr[l];
        return;
    }

    int c = (l + r) >> 1;

    build(2 * v, l, c);
    build(2 * v + 1, c + 1, r);

    int sz = t[2 * v].size() + t[2 * v + 1].size();
    t[v].resize(sz);
    merge(t[2 * v].begin(), t[2 * v].end(), t[2 * v + 1].begin(), t[2 * v + 1].end(), t[v].begin());
}



pair<int,int> get(int v, int l, int r, int i, int j) {
    while (ptr[v] < t[v].size() && used[t[v][ptr[v]].snd]) {
        ptr[v]++;
    }
    if (i <= l && r <= j) {
       if (ptr[v] < t[v].size()) {
           return t[v][ptr[v]];
       } else {
           return mp(1e9, 0);
       }
    }

    pair<int,int> x(1e9, 0);

    int c = (l + r) >> 1;

    if (i <= c) {
        chmin(x, get(2 * v, l, c, i, j));
    }

    if (c < j) {
        chmin(x, get(2 * v + 1, c + 1, r, i, j));
    }

    return x;
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

    ull x, y, p, r;
    int n;
    cin >> x >> y >> p >> r >> n;
    //x = rand(), y = rand(), p = rand(), r = rand();
   // n = 250000;
    r *= r;

    vector<z> a;
    for (int i = 0; i < n; i++) {
        int cx, cy, cm, cp, cr;
        scanf("%d %d %d %d %d", &cx, &cy, &cm, &cp, &cr);
        //cx = rand(), cy = rand(), cm = rand(), cp = rand(), cr = rand();
        z c;
        c.d = sqr(((ll)x) - cx) * 1ULL + sqr(((ll)y) - cy) * 1ULL;
        c.r = cr * 1ULL * cr;
        c.p = cp;
        c.m = cm;
        c.id = i;

        a.pb(c);
    }

    vector<ull> ccd, ccm;

    ccd.pb(r);
    ccm.pb(p);

    for (auto x : a) {
        ccd.pb(x.d);
        ccd.pb(x.r);
        ccm.pb(x.m);
        ccm.pb(x.p);
    }

    sort(ccd.begin(), ccd.end());
    sort(ccm.begin(), ccm.end());

    ccd.resize(unique(ccd.begin(), ccd.end()) - ccd.begin());
    ccm.resize(unique(ccm.begin(), ccm.end()) - ccm.begin());

    r = lower_bound(ccd.begin(), ccd.end(), r) - ccd.begin();
    p = lower_bound(ccm.begin(), ccm.end(), p) - ccm.begin();

    for (auto &x : a) {
        x.m = lower_bound(ccm.begin(), ccm.end(), x.m) - ccm.begin();
        x.p = lower_bound(ccm.begin(), ccm.end(), x.p) - ccm.begin();

        x.r = lower_bound(ccd.begin(), ccd.end(), x.r) - ccd.begin();
        x.d = lower_bound(ccd.begin(), ccd.end(), x.d) - ccd.begin();

        arr[x.d].pb(mp(x.m, x.id));
    }

    for (int i = 0; i < n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    build(1, 0, maxn - 1);

    queue<z> q;
    z _x;
    _x.p = p;
    _x.r = r;
    q.push(_x);

    int ans = 0;
    while (!q.empty()) {
        ans++;

        auto c = q.front();
        q.pop();

        while (true) {
            auto ri = get(1, 0, maxn - 1, 0, c.r);
            if (ri.fst > c.p) {
                break;
            }

            auto r = a[ri.snd];
            used[ri.snd] = 1;

            q.push(r);
        }
    }

    cout << ans - 1 << endl;


    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}