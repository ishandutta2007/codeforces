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
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>
#include <functional>

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

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
    return x * x;
}

struct pt {
    ll x, y;
    pt(ll _x = 0., ll _y = 0) {
        x = _x, y = _y;
    }

    pt operator - (const pt &o) const {
        return pt(x - o.x, y - o.y);
    }

    pt operator + (const pt &o) const {
        return pt(x + o.x, y + o.y);
    }

    bool operator < (const pt &o) const {
        return mp(x, y) < mp(o.x, o.y);
    }
};


vector<pt> sum(vector<vector<pt>> in) {
    vector<pair<ld, pt>> e;

    ll trueMinX = 0, trueMinY = 0;


    for (auto a : in) {
        if (a.empty()) {
            continue;
        }

        a.pb(a[0]);

        ll minX = 1e18, minY = 1e18;

        for (int i = 0; i + 1 < a.size(); i++) {
            pt x = a[i + 1] - a[i];
            e.pb(mp(atan2(x.y, x.x), x));

            minX = min(minX, a[i].x);
            minY = min(minY, a[i].y);
        }

        trueMinX += minX;
        trueMinY += minY;
    }

    sort(e.begin(), e.end());
    pt c;

    ll minX = 1e18, minY = 1e18;

    vector<pt> res;
    for (auto p : e) {
        res.pb(c);
        minX = min(minX, c.x);
        minY = min(minY, c.y);
        c = c + p.snd;
    }

    pt add(trueMinX - minX, trueMinY - minY);

    for (auto &p : res) {
        p = p + add;
    }

    return res;
}

ll area(pt a, pt b, pt c) {
    b = b - a;
    c = c - a;

    return b.x * c.y - b.y * c.x;
}

bool inside(pt p, pt u, pt v) {
    return abs(area(pt(0, 0), u, v)) == abs(area(p, pt(0, 0), u)) + abs(area(p, u, v)) + abs(area(p, v, pt(0, 0)));
}

int main() {
    //freopen("a.in", "r", stdin);
    vector<pt> a;
    for (int i = 0; i < 3; i++) {
        int n;
        scanf("%d", &n);

        vector<pt> b;
        while (n--) {
            int x, y;
            scanf("%d %d", &x, &y);
            b.pb(pt(x, y));
        }

        a = sum({a, b});
    }


    pt ce;

    for (auto p : a) {
        ce = ce + p;
    }

    ce.x /= a.size();
    ce.y /= a.size();

    vector<pair<ld, pt>> b;
    for (auto p : a) {
        auto f = p - ce;
        b.pb(mp(atan2(f.y, f.x) - 2.0 * pi, f));
        b.pb(mp(atan2(f.y, f.x), f));
        b.pb(mp(atan2(f.y, f.x) + 2.0 * pi, f));
    }

    sort(b.begin(), b.end());

    int m;
    scanf("%d", &m);

    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        x *= 3;
        y *= 3;
        pt p(x, y);
        p = p - ce;

        ld ang = atan2(p.y, p.x);

        int it = lower_bound(b.begin(), b.end(), mp(ang, pt(-1e18, 0))) - b.begin();

        if (inside(p, b[it - 1].snd, b[it].snd) || inside(p, b[it].snd, b[it + 1].snd)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

}