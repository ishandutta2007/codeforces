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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n && n) {
        int m = 1 << n;
        ld a[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                a[i][j] /= 100;
            }
        }
        ld f[m][n + 1];
        ld g[m][n + 1];
        for (int i = 0; i < m; ++i) {
            f[i][0] = 1;
            g[i][0] = 0;
        }
        int p2 = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = j;
                for (int k = 1; k < i; ++k) {
                    x /= 2;
                }
                x ^= 1;
                int l = x;
                int r = x;
                for (int k = 1; k < i; ++k) {
                    l *= 2;
                    (r *= 2) += 1;
                }

                ld s = 0;
                ld mg = 0;
                for (int k = l; k <= r; ++k) {
                    s += f[k][i - 1] * a[j][k];
                    chmax(mg, g[k][i - 1]);
                }
                f[j][i] = f[j][i - 1] * s;

                g[j][i] = f[j][i] * p2 + g[j][i - 1] + mg;
            }
            p2 *= 2;
        }
        ld answer = 0;
        for (int i = 0; i < m; ++i) {
            chmax(answer, g[i][n]);
        }
        cout.precision(10);
        cout << fixed << answer << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}