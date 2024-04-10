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
#include <tuple>
#include <complex>
#include <numeric>
#include <future>

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

const ld pi = acos(-1.0);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
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


//--------------------------------------------------------------------------

struct pt;

bool leCross(const pt& a, const pt &b);

ll dist(const pt& a);

bool grCross(const pt& a, const pt& b);

ll cross(const pt& a, const pt& b);

struct pt {
    ll x, y;
    bool operator < (const pt& rhs) const {
        return leCross(*this, rhs) || (cross(*this, rhs) == 0 && dist(*this) < dist(rhs));
    }
};


ll cross(const pt& a, const pt& b) {
    return a.x * b.y - a.y * b.x;
}

bool leCross(const pt& a, const pt &b) {
    return cross(a, b) < 0;
}


bool grCross(const pt& a, const pt& b) {
    return cross(a, b) > 0;
}

ll dist(const pt& a) {
    return sqr(a.x) + sqr(a.y);
}


const int maxn = 3e5 + 5;

struct FT {
    ll a[maxn];

    void clear() {
        fill(a, a + maxn, 0);
    }

    void add(int i, int x) {
        while (i < maxn) {
            a[i] += x;
            i |= i + 1;
        }
    }

    ll get(int r) {
        ll res = 0;
        while (r >= 0) {
            res += a[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};


ll solve(vector<pt> a, ll w) {
    vector<pt> up, down;
    for (auto p : a) {
        auto np = p;
        np.y -= -w;
        if (p.y > 0) {
            up.pb(np);
        } else {
            down.pb(np);
        }
    }

    sort(up.begin(), up.end());
    sort(down.begin(), down.end());

    ll ans = 0;

    int r = -1;

    FT tree;
    tree.clear();
    for (int i = 0; i < down.size(); i++) {
        tree.add(down[i].x, +1);
    }

    for (int i = 0; i < down.size(); i++) {
        tree.add(down[i].x, -1);

        ans += tree.get(down[i].x - 1); // -1!!!

        while (r + 1 < up.size() && leCross(down[i], up[r + 1])) {
            r++;
        }

        ans += r + 1;
    }

    tree.clear();
    for (int i = 0; i < up.size(); i++) {
        tree.add(-up[i].x, +1);
    }


    for (int i = 0; i < up.size(); i++) {
        int j = i;
        while (j < up.size() && cross(up[i], up[j]) == 0) {
            tree.add(-up[j].x, -1);
            j++;
        }

        for (int h = i; h < j; h++) {
            ans += (up.size() - j) - tree.get(-up[h].x - 1);
        }

//        while (l < down.size() && (cross(down[l], up[i]) == 0 || leCross(up[i], down[l]))) {
//            l++;
//        }
//
//        ans += down.size() - l;

        i = j - 1;
    }

    return ans;
}


ll brute(vector<pt> a, ll w) {
    ll ans = 0;

    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i].x == a[j].x) {
                continue;
            }

            ld k = (a[i].y - a[j].y) * 1. / (a[i].x - a[j].x);
            ld b = a[i].y - k * a[i].x;
            ans += -w - 1e-9 < b && b < w + 1e-9;
        }
    }

    return ans;
}

void gen() {
    int n = 1e5;
    int w = 0;
    ofstream out("a.in");
    out << n << " " << w << endl;

    set<pair<int,int>> was;
    for (int i = 0; i < n; i++) {
        int x, y;
        do {
            x = 1 + rand() % 2000;
            y = w + 1 + rand() % 2000;
            if (rand() & 1) {
                x = -x;
            } else {
                y = -y;
            }
        } while (was.count(mp(x, y)));
        was.insert(mp(x, y));
        out << x << " " << y << endl;
    }
}

int main() {

    srand(time(NULL));

#ifdef LOCAL
    gen();
    freopen("a.in", "r", stdin);
    //freopen("a.in", "w", stdout);
#else
    //freopen("brackets.in", "r", stdin);
    //freopen("brackets.out", "w", stdout);
#endif


    int n, w;
    cin >> n >> w;

    vector<pt> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }


    ll ans = n * 1LL * (n - 1) / 2;
    for (int i = 0; i < 2; i++) {
        ans -= solve(a, w);
        for (auto& p : a) {
            p.x = -p.x;
            p.y = -p.y;
        }
    }

    cout << ans << endl;
    //cout << brute(a, w) << endl;


    return 0;
}