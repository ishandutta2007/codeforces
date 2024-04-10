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

void addmod(int& x, const int d) {
    x += d;
    if (x >= MOD) {
        x -= MOD;
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

    string t, s;
    while (cin >> s >> t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> f(n + 2, vector<int>(n + 2, 0 ));
        for (int i = 0; i <= n; ++i) {
            f[i][i] = 1;
        }
        int ans = 0;
        for (int d = 0; d < m; ++d) {
            for (int i = 0; i <= n; ++i) {
                int j = min(i + d, n);

                int x = f[i][j];
                f[i][j] = 0;

                if (j < n && t[j] == s[d]) {
                    addmod(f[i][j + 1], x);
                }
                if (j == n) {
                    addmod(f[i][j], x);
                }

                if (i > 0 && t[i - 1] == s[d]) {
                    addmod(f[i - 1][j], x);
                }
                if (i == n) {
                    addmod(f[i][j], x);
                }
            }
            addmod(ans, f[0][n]);
        }
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}