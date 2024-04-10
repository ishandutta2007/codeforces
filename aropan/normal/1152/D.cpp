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


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    const int MOD = (int)1e+9 + 7;
    int n;
    cin >> n;
    n *= 2;
    vector<vector<pair<int, int>>> g;
    g.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        g[i].resize(n + 1, {-1, -1});
    }

    g[n][0] = {0, 1};
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= n - i && j <= i; ++j) {
            int sum = 0, ost = 0, child = 0;
            if (j > 0 && g[i + 1][j - 1].first != -1) {
                sum += g[i + 1][j - 1].first;
                ost += g[i + 1][j - 1].second;
                ++child;
            }
            if (g[i + 1][j + 1].first != -1) {
                sum += g[i + 1][j + 1].first;
                ost += g[i + 1][j + 1].second;
                ++child;
            }
            if (child == 0) {
                continue;
            }
            if (ost > 0) {
                sum += 1;
                ost = 0;
            } else {
                ost = 1;
            }
            while (sum >= MOD) {
                sum -= MOD;
            }
            g[i][j] = {sum, ost};
        }
    }
    cout << g[0][0].first << endl;

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}