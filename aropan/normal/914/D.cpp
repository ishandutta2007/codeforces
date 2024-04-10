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

const int MOD = (int)1e+9 + 7;

const int MAXN = 5e+5 + 42;
const int MAXT = 4 * MAXN;

int g[MAXT];
int a[MAXN];

int build_tree(int x, int l, int r) {
    if (l + 1 == r) {
        g[x] = a[l];
        return g[x];
    }
    int c = (l + r) / 2;
    g[x] = gcd(build_tree(2 * x + 0, l, c), build_tree(2 * x + 1, c, r));
    return g[x];
}

void modify(int x, int l, int r, int index, int value) {
    if (l + 1 == r) {
        g[x] = value;
        return;
    }
    int c = (l + r) / 2;
    if (index < c) {
        modify(2 * x + 0, l, c, index, value);
    } else {
        modify(2 * x + 1, c, r, index, value);
    }
    g[x] = gcd(g[2 * x + 0], g[2 * x + 1]);
}

void get(int x, int l, int r, int left, int right, int value, int& ret) {
    if (ret > 1) {
        return;
    }

    if (left <= l && r <= right) {
        if (g[x] % value == 0) {
            return;
        }
        if (l + 1 == r || ret > 0) {
            ret += 1;
            return;
        }
        int c = (l + r) / 2;
        get(2 * x + 0, l, c, left, right, value, ret);
        get(2 * x + 1, c, r, left, right, value, ret);
        return;
    }

    int c = (l + r) / 2;

    if (left < c) {
        get(2 * x + 0, l, c, left, right, value, ret);
    }

    if (c < right) {
        get(2 * x + 1, c, r, left, right, value, ret);
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        build_tree(1, 0, n);
        int m;
        scanf("%d", &m);
        while (m--) {
            int c, l, r, x, i, y;
            scanf("%d", &c);
            if (c == 1) {
                scanf("%d %d %d", &l, &r, &x);
                --l;
                int ret = 0;
                get(1, 0, n, l, r, x, ret);
                puts(ret > 1? "NO" : "YES");
            } else {
                scanf("%d %d", &i, &y);
                --i;
                modify(1, 0, n, i, y);
            }
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}