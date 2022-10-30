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
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 315;
ld f[2][maxn], nf[maxn];

ld g(ld *f, int l, int r, ld p, int ub = 0) {
    fill(nf, nf + maxn, 0);
    ld res = 0.0;
    for (int i = 0; i <= 200; i++) {
        int t = min(r - l + 1, max(0, i + r - ub + 1));
        if (i < ub) {
            res += f[i] * (1.0 - p) * t / (r - l + 1);
        }
        nf[i] += p * f[i];
        nf[i + 1] -= p * f[i];
        nf[i + l] += (1.0 - p) * f[i] / (r - l + 1);
        nf[i + r + 1] -= (1.0 - p) * f[i] / (r - l + 1);
    }
    ld d = 0;
    for (int i = 0; i < maxn; i++) {
        f[i] = nf[i];
        if (abs(f[i]) < 1e-50) {
            f[i] = 0.0;
        }
        d += f[i];
        if (i + 1 < maxn) {
            nf[i + 1] += nf[i];
        }
    }
    assert(abs(d - 1.0) < 1e-9);
    ld s = 0.0;
    for (int j = 200; j < maxn; j++) {
        s += f[j];
        f[j] = 0;
    }
    f[200] = s;
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


    int hp1, dt1, l1, r1;
    ld p1;
    cin >> hp1 >> dt1 >> l1 >> r1 >> p1;
    p1 /= 100.0;

    int hp2, dt2, l2, r2;
    ld p2;
    cin >> hp2 >> dt2 >> l2 >> r2 >> p2;
    p2 /= 100.0;

    if (abs(p1 - 1) < 1e-9) {
        cout << 0.0 << endl;
        return 0;
    }

    if (abs(p2 - 1) < 1e-9) {
        cout << 1.0 << endl;
        return 0;
    }

    f[0][0] = 1, f[1][0] = 1;

    ll t1 = 0, t2 = -dt2;

    ld ans = 0;
    ld s = 0.0;
    for (int i = 0; i < abs(f[0][200] - 1) > 1e-9 || abs(f[1][200] - 1) > 1e-9; i++) {
        if (i % dt1 == 0) {
            ld r = g(f[0], l1, r1, p1, hp2);
            s += r;
            ld y = 0.0;
            for (int j = 0; j < hp1; j++) {
                y += f[1][j];
            }
            ans += y * r;
        }

        if (i % dt2 == 0) {
            g(f[1], l2, r2, p2);
        }
    }
    cout.precision(10);
    cout << fixed << ans << endl;


    return 0;
}