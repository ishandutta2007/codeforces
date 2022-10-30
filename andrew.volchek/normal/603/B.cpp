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

const ll mod = 1000000007;
const int maxn = 2e5 + 5;
ll f[maxn];

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

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

    f[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
    }

    int p, k;
    cin >> p >> k;

    if (k == 1) {
        cout << bpow(p, p) << endl;
        return 0;
    } else if (k == 0) {
        cout << bpow(p, p - 1) << endl;
        return 0;
    }

    vector<int> used(p, 0);
    map<ll, ll> cnt;

    for (int i = 1; i < p; i++) {
        if (used[i]) {
            continue;
        }

        int v = i;
        int len = 0;
        while (!used[v]) {
            used[v] = 1;
            len++;
            v = v * 1LL * k % p;
        }

        cnt[len]++;
    }

    ll ans = 1;
    for (auto kv : cnt) {
        ans = ans * bpow((kv.fst * kv.snd + 1) % mod, kv.snd) % mod;
    }

    cout << ans << endl;

    return 0;
}