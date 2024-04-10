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

const int maxn = 2e5 + 5;
const ll inf = 1e16;
struct seg {
    int l, r;
    ll cost;
    bool operator < (const seg &rhs) const {
        return mp(r, -l) < mp(rhs.r, -rhs.l);
    }
};

ll tr[4 * maxn];
ll add[4 * maxn];

void modifyA(int v, int l, int r, int i, int j, ll val) {
    if (i <= l && r <= j) {
        tr[v] += val;
        add[v] += val;
        return;
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        modifyA(2 * v, l, c, i, j, val);
    }

    if (c < j) {
        modifyA(2 * v + 1, c + 1, r, i, j, val);
    }

    tr[v] = max(tr[2 * v], tr[2 * v + 1]) + add[v];
}


void modifyS(int v, int l, int r, int i, ll val, ll s = 0) {
    if (l == r) {
        chmax(tr[v], val - s);
        return;
    }

    int c = (l + r) >> 1;
    if (i <= c) {
        modifyS(2 * v, l, c, i, val, s + add[v]);
    } else {
        modifyS(2 * v + 1, c + 1, r, i, val, s + add[v]);
    }

    tr[v] = max(tr[2 * v], tr[2 * v + 1]) + add[v];
}

ll get(int v, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return tr[v];
    }

    ll res = -inf;
    int c = (l + r) >> 1;

    if (i <= c) {
        chmax(res, get(2 * v, l, c, i, j));
    }

    if (c < j) {
        chmax(res, get(2 * v + 1, c + 1, r, i, j));
    }

    return add[v] + res;
}


ll s[maxn];


ll ft[maxn];

void ft_mod(int pos, ll val) {
    while (pos < maxn) {
        chmax(ft[pos], val);
        pos |= pos + 1;
    }
}

ll ft_get(int r) {
    ll res = -inf;
    while (r >= 0) {
        chmax(res, ft[r]);
        r = (r & (r + 1)) - 1;
    }
    return res;
}

ll ft2[maxn];

ll ft_add(int i, ll pos) {
    while (i < maxn) {
        ft2[i] += pos;
        i |= i + 1;
    }
}

ll ft_getS(int r) {
    ll res = 0;
    while (r >= 0) {
        res += ft2[r];
        r = (r & (r + 1)) - 1;
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
    //freopen("hovels.in", "r", stdin);
    //freopen("hovels.out", "w", stdout);
#endif

    vector<seg> a;
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] + x;
    }

    for (int i = 0; i < m; i++) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        a.pb({l, r, c});
    }



    fill(tr, tr + maxn * 4, -inf);

    sort(a.begin(), a.end());

    ll ans = 0;

    for (auto x : a) {
        ll val = max(ft_get(x.l - 1) + x.cost - s[x.r] + s[x.l - 1] + ft_getS(maxn - 1) - ft_getS(x.l - 1)
                , get(1, 1, n, 1, x.l) - s[x.r] + x.cost);
        chmax(ans, val);
        modifyA(1, 1, n, 1, x.l, x.cost);
        modifyS(1, 1, n, x.l, val + s[x.r]);
        ft_mod(x.r, val);
        ft_add(x.l, x.cost);
    }

    cout << ans << endl;

    return 0;
}