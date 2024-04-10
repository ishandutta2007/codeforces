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
#define ld double
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

struct M {
    ld a[3][3];
    M() {
        for (int i = 0; i < 3; i++) {
            fill(a[i], a[i] + 3, 0);
        }
    }
    M operator * (const M &rhs) const {
        M res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    res.a[i][j] += a[i][k] * rhs.a[k][j];
                }
            }
        }
        return res;
    }
};

const int maxn = 3e5 + 5;

M tr[maxn * 4];

void build(int v, int l, int r) {
    if (l == r) {
        tr[v].a[0][0] = 1;
        tr[v].a[1][1] = 1;
        tr[v].a[2][2] = 1;
        tr[v].a[0][2] = 1;

        return;
    }

    int c = (l + r) >> 1;
    build(2 * v, l, c);
    build(2 * v + 1, c + 1, r);

    tr[v] = tr[2 * v] * tr[2 * v + 1];
}

ld s[400], c[400];

void rot(int v, int l, int r, int i, int ang) {
    if (l == r) {
        M x;
        x.a[0][0] = c[ang];
        x.a[1][1] = c[ang];
        x.a[0][1] = s[ang];
        x.a[1][0] = -s[ang];
        x.a[2][2] = 1;
        tr[v] = x * tr[v];
        return;
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        rot(2 * v, l, c, i, ang);
    } else {
        rot(2 * v + 1, c + 1, r, i, ang);
    }

    tr[v] = tr[2 * v] * tr[2 * v + 1];
}

void shift(int v, int l, int r, int i, int d) {
    if (l == r) {
        M x;
        x.a[0][0] = 1;
        x.a[1][1] = 1;
        x.a[2][2] = 1;
        x.a[0][2] = d;
        tr[v] = tr[v] * x;
        return;
    }

    int c = (l + r) >> 1;

    if (i <= c) {
        shift(2 * v, l, c, i, d);
    } else {
        shift(2 * v + 1, c + 1, r, i, d);
    }

    tr[v] = tr[2 * v] * tr[2 * v + 1];

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

    int n, m;
    scanf("%d %d", &n, &m);

    build(1, 1, n);

    for (int i = 0; i < 400; i++) {
        s[i] = sin(i / 180.0 * pi);
        c[i] = cos(i / 180.0 * pi);
    }

    for (int i = 0; i < m; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        if (type == 1) {
            shift(1, 1, n, x, y);
        } else {
            rot(1, 1, n, x, y);
        }
        ld xx = tr[1].a[0][2];
        ld yy = tr[1].a[1][2];

        printf("%.6lf %.6lf\n", xx, yy);
    }


    return 0;
}