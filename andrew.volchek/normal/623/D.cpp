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

const int maxn = 105;

ld p[maxn];
ld pw[maxn];

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

    set<pair<ld, int>> s;
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    ld c = 1;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] /= 100.0;
        p[i] = 1.0 - p[i];
        pw[i] = p[i];
        c *= 1.0 - pw[i];
        s.insert(mp(-(1.0 - pw[i] * p[i]) / (1.0 - pw[i]), i));
        //cout << (1.0 - pw[i] * p[i]) / (1.0 - pw[i])
    }

    ld ans = n;

    //cout << c << endl;

    for (int i = 0; i < 1000000; i++) {
        auto d = *s.begin();
        s.erase(s.begin());

        //cout << fixed << c << endl;
        ans += 1.0 - c;
        c *= -d.fst;
        pw[d.snd] *= p[d.snd];
        s.insert(mp(-(1.0 - pw[d.snd] * p[d.snd]) / (1.0 - pw[d.snd]), d.snd));

    }

    cout.precision(20);
    cout << fixed << ans << endl;

    return 0;
}