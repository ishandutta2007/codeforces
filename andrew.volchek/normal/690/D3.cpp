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

const int maxn = 105;
const ll mod = 1000003;

struct M {
    ll a[maxn][maxn];
    M() {
        for (int i = 0; i < maxn; i++) {
            fill(a[i], a[i] + maxn, 0);
        }
    }
    M operator * (const M &rhs) const {
        M res;
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                for (int k = 0; k < maxn; k++) {
                    res.a[i][j] += a[i][k] * rhs.a[k][j];
                }
                res.a[i][j] %= mod;
            }
        }
        return res;
    }
};


M bpow(M x, ll n) {
    M res;
    for (int i = 0; i < maxn; i++) {
        res.a[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            res = res * x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif

    int c, w, h;
    cin >> c >> w >> h;

    M x;

    for (int i = 0; i <= w; i++) {
        x.a[0][i] = 1;
        x.a[i][i - 1] = h;
    }

    x = bpow(x, c);

    ll ans = 0;
    for (int i = 0; i <= w; i++) {
        ans += x.a[i][0];
    }
    ans %= mod;
    cout << ans << endl;

    return 0;
}