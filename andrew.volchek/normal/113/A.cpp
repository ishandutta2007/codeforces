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


bool ends(const string &s, const string &t) {
    return s.substr(max(0, (int)(s.size() - t.size())), t.size()) == t;
}

int type(const string &s) {
    if (ends(s, "lios") || ends(s, "liala")) {
        return 0;
    } else if (ends(s, "etr") || ends(s, "etra")) {
        return 1;
    } else if (ends(s, "initis") || ends(s, "inites")) {
        return 2;
    } else {
        return -1;
    }
}

int foo(const string &s) {
    if (ends(s, "lios") || ends(s, "etr") || ends(s, "initis")) {
        return 1;
    } else {
        return 0;
    }
}



int main() {

    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("hovels.in", "r", stdin);
    //freopen("hovels.out", "w", stdout);
#endif

    string s;
    deque<string> a;
    while (cin >> s) {
        a.pb(s);
        if (type(s) == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (a.size() == 1) {
        cout << "YES" << endl;
        return 0;
    }


    bool all = true;

    for (int i = 1; i < a.size(); i++) {
        all &= foo(a[0]) == foo(a[i]);
    }

    if (!all) {
        cout << "NO" << endl;
        return 0;
    }


    while (a.size() > 1 && type(a.front()) == 0) {
        a.pop_front();
    }

    while (a.size() > 1 && type(a.back()) == 2) {
        a.pop_back();
    }

    if (a.size() == 1 && type(a[0]) == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}