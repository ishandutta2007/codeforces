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

const ld eps = 1e-9;

struct pt {
    ld x, y;
    pt(ld _x = 0.0, ld _y = 0.0) {
        x = _x, y = _y;
    }

    pt operator - (const pt &o) {
        return pt(x - o.x, y - o.y);
    }

    ld len() {
        return sqrt(sqr(x) + sqr(y));
    }

    ld len2() {
        return (sqr(x) + sqr(y));
    }

    ld operator ^ (const pt &o) {
        return x * o.y - y * o.x;
    };

    ld operator % (const pt &o) {
        return x * o.x + y * o.y;
    }

    static pt read() {
        ld x, y;
        cin >> x >> y;
        return pt(x, y);
    }
};

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

    pt p = pt::read();
    ld pv;
    cin >> pv;
    ld R = p.len();

    pv = 2.0 * pi * p.len() / pv;
    ld pAng = atan2(p.y, p.x);


    pt c = pt::read();
    ld v, r;
    cin >> v >> r;

    auto myAcos = [](ld x) {
        return acos(min(1.0l, max(-1.0l, x)));
    };

    auto myAsin = [](ld x) {
        return asin(min(1.0l, max(-1.0l, x)));
    };

    auto dist = [&](pt u, pt v) {
        ld a = u.y - v.y;
        ld b = v.x - u.x;
        ld c = -a * u.x - b * u.y;

        ld l = sqrt(sqr(a) + sqr(b));
        a /= l, b /= l, c /= l;

        pt g = pt(-c * a, -c * b);

        if (abs(c) < r - eps && ((g - u) % (v - u)) > eps && ((g - v) % (u - v)) > eps) {
            ld res = sqrt(u.len2() - sqr(r)) + sqrt(v.len2() - sqr(r));
            ld ang = atan2(u ^ v, u % v);

            ang = abs(ang);

            assert(r < u.len() && r < v.len());

            ang -= myAcos(r / u.len()) + myAcos(r / v.len());

            //cerr << u.x << " " << u.y << " " << ((g - u) % (v - u)) << endl;
            assert(ang > -eps);


            res += ang * r;

            return res;

        } else {
            return (u - v).len();
        }
    };

    auto pos = [&](ld t) {
        ld a = pAng + t / pv * 2.0 * pi;
        return pt(cos(a) * R, sin(a) * R);
    };

    ld lo = 0.0, hi = 1e12;
    for (int i = 0; i < 200; i++) {
        ld mid = (lo + hi) / 2.0;

        if (dist(pos(mid), c) / v > mid) {
            lo = mid;
        } else {
            hi = mid;
        }
    }


    cout.precision(10);
    cout << fixed << lo << endl;


    return 0;
}