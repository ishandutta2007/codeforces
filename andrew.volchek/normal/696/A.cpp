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

ll depth(ll a) {
    int d = 0;
    while (a) {
        d++;
        a >>= 1;
    }
    return d;
}

ll lca(ll a, ll b) {
    int da = depth(a), db = depth(b);
    if (da < db) {
        swap(a, b);
        swap(da, db);
    }

    for (int i = 0; i < da - db; i++) {
        a >>= 1;
    }

    while (a != b) {
        a >>= 1;
        b >>= 1;
    }

    return a;
}

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif

    int q;
    cin >> q;

    map<ll, ll> a;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll x, y, z;
            cin >> x >> y >> z;
            ll w = lca(x, y);

            while (x != w) {
                a[x] += z;
                x >>= 1;
            }

            while (y != w) {
                a[y] += z;
                y >>= 1;
            }
        } else {
            ll x, y;
            cin >> x >> y;
            ll ans = 0;
            ll w = lca(x, y);
            while (x != w) {
                ans += a[x];
                x >>= 1;
            }

            while (y != w) {
                ans += a[y];
                y >>= 1;
            }
            cout << ans << endl;
        }
    }



    return 0;
}