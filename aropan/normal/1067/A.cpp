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


const int MOD = 998244353;

inline void addmod(int &x, int d) {
    x += d;
    if (x >= MOD) {
        x -= MOD;
    }
}

inline int summod(int a, int b) {
    addmod(a, b);
    return a;
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        const int MAXX = 201;
        vector<vector<int>> f(MAXX, vector<int>(2, 0));
        vector<vector<int>> g(MAXX, vector<int>(2, 0));
        vector<vector<int>> w(MAXX, vector<int>(2, 0));
        f[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            g = f;
            for (int j = 1; j < MAXX; ++j) {
                addmod(g[j][0], g[j - 1][0]);
            }
            for (int j = MAXX - 2; j >= 0; --j) {
                addmod(g[j][1], g[j + 1][1]);
            }

            for (int x = 1; x < MAXX; ++x) {
                w[x][0] = w[x][1] = 0;

                if (a[i] == -1 || x == a[i]) {
                    w[x][0] = summod(g[x][0], summod(g[x][1], MOD - f[x][1]));
                    w[x][1] = summod(f[x][0], summod(g[x][1], MOD - f[x][1]));
                }
            }
            f = w;
        }

        int ans = 0;
        for (int i = 1; i < MAXX; ++i) {
            addmod(ans, f[i][1]);
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}