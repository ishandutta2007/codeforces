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

const int MAXN = 2e+5 + 7;

struct Fenwick {
    int s[MAXN];
    int a[MAXN];
    int n, m;
    Fenwick(int n, int m) : n(n), m(m) {
        memset(s, 0, sizeof(s));
        memset(a, 0, sizeof(a));
    }

    void upd(int i, int x) {
        int d = min(a[i] + x, m) - a[i];
        a[i] = min(a[i] + x, m);
        if (d == 0) {
            return;
        }
        for (; i <= n; i += i & -i) {
            s[i] += d;
        }
    }

    int sum(int i) {
        int res = 0;
        for (; 1 <= i; i -= i & -i) {
            res += s[i];
        }
        return res;
    }
};


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n, k, a, b, q;
    scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
    Fenwick fenwL(n, b);
    Fenwick fenwR(n, a);
    while (q--) {
        int c;
        scanf("%d", &c);
        if (c == 1) {
            int d, a;
            scanf("%d %d", &d, &a);
            fenwL.upd(d, a);
            fenwR.upd(n - d + 1, a);
        } else
        if (c == 2) {
            int p;
            scanf("%d", &p);
            int res = fenwL.sum(p - 1) + fenwR.sum(n - (p + k - 1));
            printf("%d\n", res);
        }
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}