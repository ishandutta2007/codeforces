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

    function<int(int)> gr;

    int n, k;
    cin >> n >> k;

    map<int, int> was;

    if (k & 1) {
        gr = [&](int x) {
            if (x == 1) {
                return 1;
            }

            if (x & 1) {
                return int(x == 3);
            }

            if (was.count(x)) {
                return (int)was[x];
            }

            set<int> mex({gr(x - 1), gr(x / 2)});
            was[x] = 0;
            while (mex.count(was[x])) {
                was[x]++;
            }

            return (int)was[x];
        };
    } else {
        gr = [&](int x) {
            if (x == 1) {
                return 1;
            } else if (x == 2) {
                return 2;
            }

            if (x & 1) {
                return 0;
            } else {
                return 1;
            }
        };
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans ^= gr(x);
    }

    if (ans) {
        cout << "Kevin" << endl;
    } else {
        cout << "Nicky" << endl;
    }

    return 0;
}