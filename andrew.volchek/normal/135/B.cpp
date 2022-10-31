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


struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {

    }

    pt operator - (const pt &rhs) const {
        return pt(x - rhs.x, y - rhs.y);
    }

    ll operator % (const pt &rhs) const {
        return x * rhs.x + y * rhs.y;
    }

    ll len() const {
        return sqr(x) + sqr(y);
    }
};

bool checkS(vector<pt> a) {
    vector<int> p;
    ll s = -1;
    for (int i = 0; i < 4; i++) {
        auto u = a[i], v = a[(i + 1) % 4], w = a[(i + 2) % 4];
        if ((u - v) % (w - v)) {
            return false;
        }

        ll d = (u - v).len();
        if (s == -1) {
            s = d;
        } else if (s != d) {
            return false;
        }
    }
    return true;
}


bool checkR(vector<pt> a) {
    vector<ll> p;

    for (int i = 0; i < 4; i++) {
        auto u = a[i], v = a[(i + 1) % 4], w = a[(i + 2) % 4];
        if ((u - v) % (w - v)) {
            return false;
        }

        ll d = (u - v).len();
        p.pb(d);
    }
    return p[0] == p[2] && p[1] == p[3];
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    // gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    vector<pt> a;
    for (int i = 0; i < 8; i++) {
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
    }

    vector<int> p;
    for (int i = 0; i < 8; i++) {
        p.pb(i);
    }

    do {
        vector<pt> b, c;
        for (int i = 0; i < 8; i++) {
            if (i < 4) {
                b.pb(a[p[i]]);
            } else {
                c.pb(a[p[i]]);
            }
        }
        if (checkS(b) && checkR(c)) {
            cout << "YES" << endl;
            for (int i = 0; i < 4; i++) {
                if (i) {
                    cout << " ";
                }
                cout << p[i] + 1;
            }
            cout << endl;
            for (int i = 0; i < 4; i++) {
                if (i) {
                    cout << " ";
                }
                cout << p[i + 4] + 1;
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << "NO" << endl;


    return 0;
}