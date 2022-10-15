#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> void chmin(T &x, const T y) { if (x > y) { x = y; } }
template <typename T> void chmax(T &x, const T y) { if (x < y) { x = y; } }

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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const int MAXA = 5005;
    ld f[MAXA];
    memset(f, 0, sizeof(f));
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            f[a[j] - a[i]] += 1. / (n * (n - 1)) * 2;
        }
    }

    ld s[MAXA];
    memset(s, 0, sizeof(s));
    for (int i = MAXA - 2; i > 0; --i) {
        s[i] = s[i + 1] + f[i];
    }

    const ld EPS = 1e-12;
    ld ans = 0;
    for (int i = 1; i < MAXA; ++i) {
        if (f[i] > EPS) {
            for (int j = 1, t; j < MAXA && (t = j + i + 1) < MAXA; ++j) {
                if (f[j] > EPS && s[t] > EPS) {
                    ans += s[t] * f[i] * f[j];
                }
            }
        }
    }
    cout.precision(10);
    cout << fixed << ans << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}