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

const int maxn = 5e5 + 5;

ll dpR[maxn], dpL[maxn];

char s[maxn];

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

    ll n, a, b, t;
    cin >> n >> a >> b >> t;
    scanf("%s", s);


    for (int i = 1; i < n; i++) {
        dpR[i] = a + (s[i] == 'w') * b + 1;
        if (i > 1) {
            dpR[i] += dpR[i - 1];
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        dpL[i] = a + (s[i] == 'w') * b + 1;
        if (i < n - 1) {
            dpL[i] += dpL[i + 1];
        }
    }

    if ((s[0] == 'w') * b + 1 > t) {
        cout << 0 << endl;
        return 0;
    }

    t -= (s[0] == 'w') * b + 1;

    ll ans = 1;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int p = 1;
    for (int i = 1; i < n; i++) {
        if (dpR[i] > t) {
            break;
        }

        ll need = dpR[i] + i * a;
        while (p <= n - 1 && t - need < dpL[p]) {
            p++;
        }

        chmax(ans, min(n, 1 + i + n - p));
    }


    p = n - 1;
    for (int i = n - 1; i >= 1; i--) {
        if (dpL[i] > t) {
            break;
        }
        ll need = dpL[i] + (n - i) * a;
        while (p >= 1 && t - need < dpR[p]) {
            p--;
        }

        chmax(ans, min(n, 1 + (n - i) + p));
    }

    cout << ans << endl;

    return 0;
}