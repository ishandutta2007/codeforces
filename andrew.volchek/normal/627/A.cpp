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


int brute(int s, int x) {
    int ans = 0;
    for (int i = 1; i < s; i++) {
        if ((i ^ (s - i)) == x) {
            ans++;
        }
    }
    return ans;
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


    ll s, x;
    cin >> s >> x;
    ll m = s;
    ll ans = 1;

    for (int i = 60; i >= 0; i--) {
        if (x & (1LL << i)) {
            s -= 1LL << i;
            ans *= 2;
        }
    }

    if (s < 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 60; i >= 0; i--) {
        if (!bool(x & (1LL << i))) {
            if (s >= (1LL << (i + 1))) {
                s -= (1LL << (i + 1));
            }
        }
    }

    if (s != 0) {
        cout << 0 << endl;
        return 0;
    }

    if (m == x) {
        ans -= 2;
    }

  //  assert(ans == brute(m, x));
    cout << ans << endl;
   // cout << brute(m, x) << endl;

    return 0;
}