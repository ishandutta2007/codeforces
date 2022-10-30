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

ll turn(const pair<ll, ll> &a, const pair<ll, ll> &b, const pair<ll, ll> &c) {
    return a.fst * (b.snd - c.snd) + b.fst * (c.snd - a.snd) + c.fst * (a.snd - b.snd);
}

bool cw(const pair<ll, ll> &a, const pair<ll, ll> &b, const pair<ll, ll> &c) {
    return turn(a, b, c) < 0;
}

bool ccw(const pair<ll, ll> &a, const pair<ll, ll> &b, const pair<ll, ll> &c) {
    return turn(a, b, c) > 0;
}

vector<pair<ll, ll>> hull(vector<pair<ll, ll>> a) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    vector<pair<ll, ll>> up, down;
    up.pb(a[0]);
    down.pb(a[0]);


    int n = a.size();

    for (int i = 1; i < n; i++) {
        if (i == n - 1 || cw(a[0], a[i], a[n - 1])) {
            while (up.size() > 1 && !cw(up[up.size() - 2], up.back(), a[i])) {
                up.pop_back();
            }

            up.pb(a[i]);
        }

        if (i == n - 1 || ccw(a[0], a[i], a[n - 1])) {
            while (down.size() > 1 && !ccw(down[down.size() - 2], down.back(), a[i])) {
                down.pop_back();
            }

            down.pb(a[i]);
        }
    }



    vector<pair<ll, ll>> res;
    for (int i = 0; i < up.size(); i++) {
        res.pb(up[i]);
    }

    for (int i = down.size() - 2; i > 0; i--) {
        res.pb(down[i]);
    }

    return res;
}

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

    int n;
    ld p, q;
    cin >> n >> p >> q;

    vector<pair<ll, ll>> a;

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a.pb(mp(x, y));
        a.pb(mp(0, y));
        a.pb(mp(x, 0));
    }

    a.pb(mp(0, 0));


    a = hull(a);


    ld lo = 0.0, hi = 1e7 + 6;

    for (int i = 0; i < 60; i++) {
        ld mid = (lo + hi) / 2.0;

        ld s1 = 0.0, s2 = 0.0;

        for (int j = 0; j < a.size(); j++) {
            auto u = a[j], v = a[(j + 1) % a.size()];
            ld f = (u.fst  - p / mid) * (v.snd  - q / mid) - (u.snd  - q / mid) * (v.fst  - p / mid);
            s1 += f;
            s2 += abs(f);
        }

        s1 = abs(s1);

        if (s1 < s2) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout.precision(20);
    cout << fixed << lo << endl;

    return 0;
}