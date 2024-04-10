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

struct pt {
    ll x, y;
    int id;

    pt(int _x, int _y, int _id) {
        x = _x, y = _y, id = _id;
    }

    bool operator < (const pt &o) const {
        return mp(x, y) < mp(o.x, o.y);
    }

    bool operator == (const pt &o) const {
        return mp(x, y) == mp(o.x, o.y);
    }
};

ll turn(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

bool cw(pt a, pt b, pt c) {
    return turn(a, b, c) <= 0;
}

bool ccw(pt a, pt b, pt c) {
    return turn(a, b, c) >= 0;
}

int hull(vector<pt> a) {
    if (a.size() < 3) {
        int res = 0;
        for (auto x : a) {
            res |= x.id;
        }
    }

    sort(a.begin(), a.end());

    vector<pt> up, down;
    up.pb(a[0]), down.pb(a[0]);

    int n = a.size();

    for (int i = 1; i < n; i++) {
        if (i == n - 1 || cw(a[0], a[i], a[n - 1])) {
            if (up.back() == a[i]) {
                up.back().id |= a[i].id;
            } else {
                while (up.size() > 1 && !cw(up[up.size() - 2], up.back(), a[i])) {
                    up.pop_back();
                }

                up.pb(a[i]);
            }
        }

        if (i == n - 1 || ccw(a[0], a[i], a[n - 1])) {
            if (down.back() == a[i]) {
                down.back().id |= a[i].id;
            } else {
                while (down.size() > 1 && !ccw(down[down.size() - 2], down.back(), a[i])) {
                    down.pop_back();
                }

                down.pb(a[i]);
            }
        }
    }

    pair<ll, pt> u(-1e18, pt(0, 0, 0)), v(-1e18, pt(0, 0, 0));

    int res = 0;
    for (auto x : up) {
        if (x.x && x.y) {
            res |= x.id;
        } else if (x.x) {
            u = max(u, mp(x.x, x));
        } else if (x.y) {
            v = max(v, mp(x.y, x));
        }
    }

    for (auto x : down) {
        if (x.x && x.y) {
            res |= x.id;
        } else if (x.x) {
            u = max(u, mp(x.x, x));
        } else if (x.y) {
            v = max(v, mp(x.y, x));
        }
    }

    res |= u.snd.id;
    res |= v.snd.id;
    
    return res;
}


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    int x, y;
    scanf("%d %d", &x, &y);

    vector<pt> a;
    a.pb(pt(0, 0, 0));

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a.pb(pt(x, y, 1));
        a.pb(pt(x, 0, 1));
        a.pb(pt(0, y, 1));
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a.pb(pt(x, y, 2));
        a.pb(pt(x, 0, 2));
        a.pb(pt(0, y, 2));
    }

    if (hull(a) & 1) {
        printf("Max\n");
    } else {
        printf("Min\n");
    }

    return 0;
}