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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MAXN = 1e+6 + 42;
int v[MAXN];

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n, a, b;
    cin >> n >> a >> b;

    int k = -1;
    for (int i = 0; i <= n / a; ++i) {
        if ((n - a * i) % b == 0) {
            k = i;
            break;
        }
    }
    if (k == -1) {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }

    for (int i = 0; i < n; ) {
        int d;
        if (k > 0) {
            d = a;
            --k;
        } else {
            d = b;
        }
        int j = i + d;
        int x = v[i];
        while (i + 1 < j) {
            v[i] = v[i + 1];
            ++i;
        }
        v[i] = x;
        i = j;
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << " ";
        }
        cout << v[i] + 1;
    }
    cout << endl;



    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}