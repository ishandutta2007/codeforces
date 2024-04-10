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
#include "pretty_print.h"
#else
#define dbg(x)
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

#define X first
#define Y second

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int INF = 1e+9 + 42;
const int MAXN = 140000;
pair <int, int> p[MAXN][2];

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
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> p[i][j].X >> p[i][j].Y;
            }
        }

        set <int> s;
        for (int iter = 0; iter < 4; ++iter) {
            for (int d = -1; d <= 1; d += 2) {
                pair <int, int> opt = {-INF, -INF};
                int index = -1;
                for (int i = 0; i < n; ++i) {
                    pair <int, int> x = make_pair(min(p[i][0].X, p[i][1].X), d * min(p[i][0].Y, p[i][1].Y));
                    if (chmax(opt, x)) {
                        index = i;
                    }
                }
                s.insert(index);
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 2; ++j) {
                    swap(p[i][j].X, p[i][j].Y);
                    p[i][j].X = -p[i][j].X;
                }
            }
        }
        dbg(s);

        bool ok = false;
        for (auto& ind : s) {
            int xmin, ymin, xmax, ymax;
            xmin = -INF;
            ymin = -INF;
            xmax = INF;
            ymax = INF;
            for (int i = 0; i < n; ++i) {
                if (ind == i) {
                    continue;
                }
                xmin = max(xmin, p[i][0].X);
                ymin = max(ymin, p[i][0].Y);
                xmax = min(xmax, p[i][1].X);
                ymax = min(ymax, p[i][1].Y);
            }
            // cerr << xmin << " " << xmax << " " << ymin << " " << ymax << endl;
            if (xmin <= xmax && ymin <= ymax) {
                cout << xmin << " " << ymin << endl;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}