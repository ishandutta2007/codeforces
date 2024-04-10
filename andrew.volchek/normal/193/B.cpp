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

const ld pi = 3.14159265359;

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
ostream &operator<<(ostream &s, const pair <U, V> &x) {
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

//-----------------------------------------------------------------------------

vector<ll> a, b, p, k;
ll ans = 0;
ll r = 0;

void rec(int mv, bool f) {
    if (mv == -1) {
        ll c = 0;
        for (int i = 0; i < a.size(); i++) {
            c += a[i] * k[i];
        }
        chmax(ans, c);
        return;
    }

    vector<ll> old = a;
    for (int i = 0; i < a.size(); i++) {
        a[i] = old[p[i]] + r;
    }

    rec(mv - 1, false);

    if (mv - 2 >= -1) {
        for (int i = 0; i < a.size(); i++) {
            a[i] ^= b[i];
        }

        rec(mv - 2, false);

        for (int i = 0; i < a.size(); i++) {
            a[i] ^= b[i];
        }
    }

    a = old;

    if (f) {
        for (int i = 0; i < a.size(); i++) {
            a[i] ^= b[i];
        }

        rec(mv - 1, false);

        for (int i = 0; i < a.size(); i++) {
            a[i] ^= b[i];
        }
    }
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

    int n, u;
    cin >> n >> u >> r;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        a.pb(c);
    }

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        b.pb(c);
    }

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        k.pb(c);
    }

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        c--;
        p.pb(c);
    }

    ans = -1e18;
    for (int i = u; i >= 0; i -= 2) {
        rec(i - 1, 1);
    }

    cout << ans << endl;


    return 0;
}