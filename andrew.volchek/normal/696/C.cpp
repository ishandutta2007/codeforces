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

const ll mod = 1000000007;

struct M {
    ll a[2][2];
    M() {
        for (int i = 0; i < 2; i++) {
            fill(a[i], a[i] + 2, 0);
        }
    }
    M operator * (const M &rhs) const {
        M res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int h = 0; h < 2; h++) {
                    res.a[i][j] += a[i][h] * rhs.a[h][j];
                }
                res.a[i][j] %= mod;
            }
        }
        return res;
    }
};

M bpow(M x, ll n) {
    M res;
    for (int i = 0; i < 2; i++) {
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

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = (x * x) % mod;
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

    M x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 2;

    int n;
    cin >> n;
    //n = 1e5;
    bool all = true;

    ll z = 2;

    for (int i = 0; i < n; i++) {
        ll c;
        //scanf("%lld", &c);
        cin >> c;
        //c = 762281063504198117LL;

        x = bpow(x, c);
        all &= (c == 1);

        z = bpow(z, c);
    }


    if (all) {
        cout << "0/1" << endl;
        return 0;
    }

    M y;
    y.a[0][1] = bpow(2, mod - 2);
    y.a[1][0] = 1;
    y.a[1][1] = (mod - bpow(2, mod - 2)) % mod;


    x = x * y;
    cout << x.a[0][1] << "/" << (z * bpow(2, mod - 2) % mod) << endl;


    return 0;
}