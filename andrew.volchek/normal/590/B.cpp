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

const ld eps = 1e-9;
ld vmax;

bool f(ld dx, ld dy, ld wx, ld wy, ld a) {
    return sqr(dx * a - wx) + sqr(dy * a - wy) < sqr(vmax) + eps;
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

    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ld t;
    cin >> vmax >> t;

    ld vx, vy, wx, wy;
    cin >> vx >> vy >> wx >> wy;

    ld lo = 1e-18, hi = 1e18;
    for (int i = 0; i < 300; i++) {
        ld mid = (lo + hi) / 2.0;

        if (f(x2 - x1, y2 - y1, vx, vy, mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout.precision(12);
    if (1.0 / lo < t + eps) {
        cout << fixed << 1.0 / lo << endl;
        return 0;
    }

    lo = 0.0, hi = 1e18;
    for (int i = 0; i < 300; i++) {
        ld mid = (lo + hi) / 2.0;

        ld a = abs(t * vx + mid * wx - (x2 - x1)) / vmax;
        ld b = abs(t * vy + mid * wy - (y2 - y1)) / vmax;

        ld c = sqrt(sqr(a) + sqr(b));
        a -= t * (a / c);
        b -= t * (b / c);

        if (sqr(a) + sqr(b) < sqr(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << hi + t << endl;


    return 0;
}