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

pair<ll,ll> tr[maxn * 4];

pair<ll, ll> a[maxn];

void build(int v, int l, int r) {
    if (l == r) {
        tr[v] = mp(a[l].snd, l);
        return;
    }

    int c = (l + r) >> 1;

    build(2 * v, l, c);
    build(2 * v + 1, c + 1, r);

    tr[v] = min(tr[2 * v], tr[2 * v + 1]);
}


pair<ll,ll> get(int v, int l, int r, int i, int j) {
    if (i > j) {
        return mp(inf, inf);
    }
    if (i <= l && r <= j) {
        return tr[v];
    }

    pair<ll, ll> res(inf, inf);
    int c = (l + r) >> 1;

    if (i <= c) {
        chmin(res, get(2 * v, l, c, i, j));
    }

    if (c < j) {
        chmin(res, get(2 * v + 1, c + 1, r, i, j));
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

#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    ll d, n, m;
    cin >> d >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, p;
        scanf("%d %d", &x, &p);
        a[i] = mp(x, p);
    }

    a[m] = mp(0, 0);
    a[m + 1] = mp(d, 0);
    m += 2;

    sort(a, a + m);

    build(1, 0, m - 1);

    ll vol = n;
    int pos = 0;
    ll ans = 0;
    int r = 0;

    while (pos != m - 1) {



        bool found = false;
        while (vol < n) {
            while (r < m && a[r].fst <= a[pos].fst + vol) {
                r++;
            }


            auto res = get(1, 0, m - 1, pos + 1, r - 1);
            if (res.fst <= a[pos].snd) {
                vol -= a[res.snd].fst - a[pos].fst;
                pos = res.snd;
                found = true;
                break;
            }

            ll add = min(n - vol, a[r].fst - (a[pos].fst + vol));
            vol += add;
            ans += add * a[pos].snd;
        }

        if (found) {
            continue;
        }

        while (r < m && a[r].fst <= a[pos].fst + vol) {
            r++;
        }

        auto res = get(1, 0, m - 1, pos + 1, r - 1);

        if (res.fst == inf) {
            cout << -1 << endl;
            return 0;
        }

        vol -= a[res.snd].fst - a[pos].fst;
        pos = res.snd;
    }

    cout << ans << endl;

    return 0;
}