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

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(int /* argc */, char** /* argv */)
{
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n, q;
    n = q = 0;
    assert(scanf("%d %d", &n, &q) == 2);
    int a[n];
    for (int i = 0; i < n; ++i) {
        assert(scanf("%d", &a[i]) == 1);
    }

    int f[n];
    int c[n];
    ll g[n];
    while (q--) {
        ll b;
        cin >> b;
        ll s = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && s + a[j] <= b) {
                s += a[j];
                ++j;
            }
            f[i] = j;
            s -= a[i];
        }

        s = 0;
        for (int i = n - 1; i >= 0; --i) {
            s += a[i];
            if (f[i] == n) {
                c[i] = 0;
                g[i] = s;
            } else {
                c[i] = c[f[i]] + 1;
                g[i] = g[f[i]];
            }
        }
        int ans = n;
        s = 0;
        for (int i = 0; i < n; ++i) {
            if (s + g[i] <= b) {
                ans = min(ans, c[i] + (s + g[i] > 0));
            }
            s += a[i];
        }
        cout << ans << "\n";
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}