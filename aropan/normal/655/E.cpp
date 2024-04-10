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

const int MOD = 1e+9 + 7;

void add_mod(int &x, const int& d) {
    x += d;
    if (x >= MOD) {
        x -= MOD;
    } else
    if (x < 0) {
        x += MOD;
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
    string s;
    int n, k;
    while (cin >> n >> k >> s) {
        int m = s.size();
        int a[m + n];
        for (int i = 0; i < m; ++i) {
            a[i] = s[i] - 'a';
        }

        int p[k];
        memset(p, 0, sizeof(p));
        for (int i = 0; i < m; ++i) {
            p[a[i]] = i + 1;
        }

        int v[k];
        for (int i = 0; i < k; ++i) {
            v[i] = i;
        }
        sort(v, v + k, [&](const int& a, const int& b) { return p[a] < p[b]; });
        for (int i = m; i < n + m; ++i) {
            a[i] = v[(i - m) % k];
        }

        ll f[k];
        memset(f, 0, sizeof(f));
        int ans = 1;
        for (int i = 0; i < n + m; ++i) {
            int x = f[a[i]];
            f[a[i]] = ans;
            add_mod(ans, ans);
            add_mod(ans, -x);
        }
        cout << ans << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}