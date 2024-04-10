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

int main() {
    srand(time(NULL));

    //freopen("a.in", "r", stdin);

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("factory.in", "r", stdin);
    //freopen("factory.out", "w", stdout);
#endif

    vector<ld> a;
    for (int i = 0; i < 6; i++) {
        ld x;
        cin >> x;
        a.pb(x);
    }

    const ld eps = 1e-9;

    ld x = 1.0, y = 0.0;
    vector<pair<ld, ld>> p;
    ld cx = 0.0, cy = 0.0;

    for (int i = 0; i < 6; i++) {
        cx += x * a[i], cy += y * a[i];
        p.pb(mp(cx, cy));

        ld nx = x * cos(pi / 3.0) - y * sin(pi / 3.0);
        ld ny = x * sin(pi / 3.0) + y * cos(pi / 3.0);

        x = nx, y = ny;
    }

    assert(abs(cx) < eps && abs(cy) < eps);

    ld area = 0.0;

    for (int i = 0; i < 6; i++) {
        auto u = p[i], v = p[(i + 1) % 6];
        area += (u.fst - v.fst) * (u.snd + v.snd) / 2.0;
    }

    area = abs(area);
    area /= sqrt(3) / 4.0;

    ll ans = round(area) + 0.0000001;

    cout << ans << endl;


    return 0;
}