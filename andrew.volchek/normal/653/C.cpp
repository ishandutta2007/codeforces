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



int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }


    int err = 0;

    vector<int> cand;
    for (int i = 0; i + 1 < n; i++) {
        if (i & 1) {
            err += a[i] <= a[i + 1];
            if (a[i] <= a[i + 1]) {
                cand.pb(i), cand.pb(i + 1);
            }
        } else {
            err += a[i] >= a[i + 1];
            if (a[i] >= a[i + 1]) {
                cand.pb(i), cand.pb(i + 1);
            }
        }
    }

    auto modify = [&](int i, int val) {

        if (i + 1 < n) {
            if (i & 1) {
                err -= a[i] <= a[i + 1];
            } else {
                err -= a[i] >= a[i + 1];
            }
        }

        if (i - 1 >= 0) {
            if ((i - 1) & 1) {
                err -= a[i - 1] <= a[i];
            } else {
                err -= a[i - 1] >= a[i];
            }
        }


        a[i] = val;


        if (i + 1 < n) {
            if (i & 1) {
                err += a[i] <= a[i + 1];
            } else {
                err += a[i] >= a[i + 1];
            }
        }

        if (i - 1 >= 0) {
            if ((i - 1) & 1) {
                err += a[i - 1] <= a[i];
            } else {
                err += a[i - 1] >= a[i];
            }
        }
    };

    sort(cand.begin(), cand.end());
    cand.resize(unique(cand.begin(), cand.end()) - cand.begin());

    set<pair<int,int>> ans;
    cand.resize(min((int)cand.size(), 10));

    for (int x : cand) {
        for (int i = 0; i < n; i++) {
            if (i == x) {
                continue;
            }

            int u = a[x], v = a[i];

            modify(x, v);
            modify(i, u);

            if (err == 0) {
                ans.insert(mp(min(x, i), max(x, i)));
            }

            modify(i, v);
            modify(x, u);
        }
    }

    cout << ans.size() << endl;

    return 0;
}