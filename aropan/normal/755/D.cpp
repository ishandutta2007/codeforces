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
#include <iomanip>
#include <numeric>

using namespace std;

#define snd second
#define fst first

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MAXN = 1e+6 + 7;
int n, k;
int s[MAXN];

void modify(int x, int d) {
    for (int i = x; i <= n; i += i & -i) {
        s[i] += d;
    }
}

int findsum(int x) {
    int res = 0;
    for (int i = x; 0 < i; i -= i & -i) {
        res += s[i];
    }
    return res;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
#endif
    while (cin >> n >> k) {
        memset(s, 0, sizeof(s));
        k = min(k, n - k);
        int x = 1;
        modify(x, 1);
        ll ans = 1;
        for (int i = 0; i < n; ++i) {
            int y = (x + k - 1) % n + 1;
            int v;
            if (x < y) {
                v = 2 * (findsum(y) - findsum(x));
            } else {
                v = 2 * (i + 1 - findsum(x) + findsum(y)) - 1;
            }
            ans += 1 + v;
            if (i + 1 == n) {
                ans -= 1;
            }
            x = y;
            modify(x, 1);
            if (i) {
                printf(" ");
            }
            printf("%lld", ans);
        }
        printf("\n");
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}