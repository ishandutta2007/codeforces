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

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 2e5 + 5;
const ll mod = 1000000007;

ll tr[maxn * 4];
ll trM[maxn * 4];

ll mul(ll x, ll y) {
    return x * y % mod;
}

ll add(ll x, ll y) {
    return (x + y) % mod;
}


void modifyM(int v, int l, int r, int i, int j, ll val) {
    if (i <= l && r <= j) {
        tr[v] = mul(tr[v], val);
        trM[v] = mul(trM[v], val);
        return;
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        modifyM(2 * v, l, c, i, j, val);
    }

    if (c < j) {
        modifyM(2 * v + 1, c + 1, r, i, j, val);
    }

    tr[v] = mul(add(tr[2 * v], tr[2 * v + 1]), trM[v]);
}

void modifyS(int v, int l, int r, int i, ll val) {
    if (l == r) {
        tr[v] = mul(val, trM[v]);
        return;
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        modifyS(2 * v, l, c, i, val);
    } else {
        modifyS(2 * v + 1, c + 1, r, i, val);
    }

    tr[v] = mul(add(tr[2 * v], tr[2 * v + 1]), trM[v]);
}

ll getS(int v, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return tr[v];
    }

    ll res = 0;
    int c = (l + r) >> 1;

    if (i <= c) {
        res = add(res, getS(2 * v, l, c, i, j));
    }

    if (c < j) {
        res = add(res, getS(2 * v + 1, c + 1, r, i, j));
    }

    return mul(res, trM[v]);
}

ll getM(int v, int l, int r, int i) {
    if (l == r) {
        return trM[v];
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        return mul(trM[v], getM(2 * v, l, c, i));
    } else {
        return mul(trM[v], getM(2 * v + 1, c + 1, r, i));
    }
}

vector<int> g[maxn];
int tin[maxn], tout[maxn];
int timer = 0;
int pr[maxn];

void dfs(int v) {
    tin[v] = timer++;
    for (int to : g[v]) {
        dfs(to);
        pr[to] = v;
    }
    tout[v] = timer - 1;
}

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}
int deg[maxn];


int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    fill(trM, trM + 4 * maxn, 1);

    struct qe {
        int type, x, y;
    };

    vector<qe> a;

    pr[1] = -1;
    fill(deg, deg + maxn, 1);

    int v1, q;
    scanf("%d %d", &v1, &q);

    modifyS(1, 0, maxn - 1, 0, v1);

    int vcnt = 1;

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            g[x].pb(++vcnt);
            a.pb({type, x, y});
        } else {
            int x;
            scanf("%d", &x);
            a.pb({type, x, 0});
        }
    }

    dfs(1);

    vcnt = 1;

    for (auto q : a) {
        if (q.type == 1) {
            int v = ++vcnt;
            int l = tin[q.x];
            int r = tout[q.x];

            modifyM(1, 0, maxn - 1, l, r, bpow(deg[q.x], mod - 2));
            deg[q.x]++;
            modifyM(1, 0, maxn - 1, l, r, deg[q.x]);

            modifyS(1, 0, maxn - 1, tin[v], q.y);
        } else {
            ll res = getS(1, 0, maxn - 1, tin[q.x], tout[q.x]);
            //cout << getS(1, 0, maxn - 1, 2, 2) << endl;
            if (pr[q.x] != -1) {
                res = mul(res, bpow(getM(1, 0, maxn - 1, tin[pr[q.x]]), mod - 2));
            }

            cout << res << endl;
        }
    }




    return 0;
}