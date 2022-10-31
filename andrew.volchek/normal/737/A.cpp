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



int main() {
    //srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    ll n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i].fst, &a[i].snd);
    }
    vector<ll> b(k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &b[i]);
    }
    b.pb(0);
    b.pb(s);
    sort(b.begin(), b.end());
    vector<ll> c;
    for (int i = 0; i + 1 < b.size(); i++) {
        c.pb(b[i + 1] - b[i]);
    }


    const ll inf = 1e18 * 1.5;

    auto can = [&](ll g) {
        ll tt = 0;
        for (ll x : c) {
            if (x > g) {
                return inf;
            }
            ll f1 = x;
            ll f2 = min(x, g - f1);
            tt += (f1 - f2) * 2 + f2;
        }
        return tt;
    };



    ll lo = 0, hi = inf;
    while (hi - lo > 1) {
        ll mid = (lo + hi) >> 1;

        if (can(mid) <= t) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    ll ans = inf;
    for (auto p : a) {
        if (p.snd >= hi) {
            chmin(ans, p.fst);
        }
    }

    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}