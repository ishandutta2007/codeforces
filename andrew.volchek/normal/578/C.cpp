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

    vector<ld> a;
    int n;
    scanf("%d", &n);
    //n = 2e5;

    for (int i = 0; i < n; i++) {
        int x;
        //x = rand() % 10000;
        scanf("%d", &x);
        a.pb(x);
    }

    auto get = [&](ld x) {
        ld res = -1e18;
        ld m = 0.0;

        ld s = 0.0;
        for (int i = 0; i < n; i++) {
            s += a[i];
            res = max(res, s - (i + 1) * x + m);
            m = max(m, (i + 1) * x - s);
        }

        s = 0.0;
        m = 0.0;
        for (int i = 0; i < n; i++) {
            s += a[i];
            res = max(res, (i + 1) * x - s + m);
            m = max(m, - (i + 1) * x + s);
        }

        return res;
    };

    ld lo = -1e5, hi = 1e5;
    for (int i = 0; i < 100; i++) {
        ld m1 = lo + (hi - lo) / 3.0;
        ld m2 = hi - (hi - lo) / 3.0;

        ld x1 = get(m1), x2 = get(m2);

        if (x1 > x2) {
            lo = m1;
        } else {
            hi = m2;
        }
    }

    cout.precision(10);
    cout << fixed << get((lo + hi) / 2.0) << endl;
    cerr << fixed << ((lo + hi) / 2.0) << endl;


    return 0;
}