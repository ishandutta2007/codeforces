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

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int INF = (int)1e+9 + 42;

vector<int> a, b, c;
vector<int> f, g;
vector<vector<int>> e;


ll dfs(int x, int p = -1, int d = INF) {
    chmin(d, a[x]);
    f[x] = b[x] < c[x];
    g[x] = b[x] > c[x];

    ll res = 0;
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        res += dfs(y, x, d);
        f[x] += f[y];
        g[x] += g[y];
    }
    int k = min(f[x], g[x]);
    f[x] -= k;
    g[x] -= k;

    res += 2 * k * (ll)d;
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

    int n;
    while (cin >> n) {
        a = vector<int>(n);
        b = vector<int>(n);
        c = vector<int>(n);
        f = vector<int>(n);
        g = vector<int>(n);
        e = vector<vector<int>>(n);
        int sb = 0;
        int sc = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            sb += b[i];
            sc += c[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if (sb != sc) {
            cout << -1 << endl;
            continue;
        }

        ll ans = dfs(0, -1);
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}