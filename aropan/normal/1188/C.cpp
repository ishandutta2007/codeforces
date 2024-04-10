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


const int MAXN = 1002;
const int MOD = 998244353;

int f[MAXN][MAXN][2];

void addmod(int& x, int d) {
    x += d;
    if (x >= MOD) {
        x -= MOD;
    } else if (x < 0) {
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
    int n, k;
    // for (int it = 0; it < 100; ++it) {
    while (cin >> n >> k) {
        // n = 1000;
        // k = rand() % (n / 2) + 2;
        // dbg(n);
        // dbg(k);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            // a[i] = rand() % 100000;
        }
        sort(all(a));
        // dbg(a);
        vector<int> lft(n);
        vector<int> rgt(n);
        int ans = 0;
        for (int d = 0; d < 100000 / (k - 1) + 2; ++d) {
            bool ok = false;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && (i == j || a[i] + d > a[j])) {
                    ++j;
                }
                lft[i] = j;
                ok |= (j < n && a[j] - a[i] == d);
            }
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && (i == j || a[i] + d >= a[j])) {
                    ++j;
                }
                rgt[i] = j;
            }
            if (!ok) {
                continue;
            }

            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= k; ++j) {
                    for (int t = 0; t < 2; ++t) {
                        f[i][j][t] = 0;
                    }
                }
            }

            f[0][0][0] = 1;
            int res = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < k; ++j) {
                    for (int t = 0; t < 2; ++t) {
                        if (i) {
                            addmod(f[i][j][t], f[i - 1][j][t]);
                        }
                        int v = f[i][j][t];
                        if (!v) {
                            continue;
                        }
                        if (lft[i] < rgt[i]) {
                            addmod(f[lft[i]][j + 1][1], v);
                            addmod(f[rgt[i]][j + 1][1], -v);
                        }
                        addmod(f[rgt[i]][j + 1][t], v);
                    }
                }
                addmod(res, f[i][k - 1][1]);
            }

#ifdef LOCAL
            // memset(f, 0, sizeof(f));
            // int check = 0;
            // for (int i = 0; i < n; ++i) {
            //     f[i][0][0] = 1;
            //     for (int j = 0; j < k; ++j) {
            //         for (int t = 0; t < 2; ++t) {
            //             if (!f[i][j][t]) {
            //                 continue;
            //             }

            //             for (int x = lft[i]; x < n; ++x) {
            //                 addmod(f[x][j + 1][t || (a[x] - a[i]) == d], f[i][j][t]);
            //             }
            //         }
            //     }
            //     addmod(check, f[i][k - 1][1]);
            // }
            // assert(check == res);
#endif
            addmod(ans, res * (ll)d % MOD);
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}