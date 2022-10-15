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

    int n, m;
    while (cin >> n >> m) {
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool ok = true;
        int v = 0;
        for (int i = 0; i < n; ++i) {
            int has_lock = false;
            int has_dot = false;
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '#') {
                    if (has_dot) {
                        ok = false;
                    }
                    has_lock = true;
                } else {
                    if (has_lock) {
                        has_dot = true;
                    }
                }
            }
            if (!has_lock) {
                ++v;
            }
        }
        int h = 0;
        for (int j = 0; j < m; ++j) {
            int has_lock = false;
            int has_dot = false;
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == '#') {
                    if (has_dot) {
                        ok = false;
                    }
                    has_lock = true;
                } else {
                    if (has_lock) {
                        has_dot = true;
                    }
                }
            }
            if (!has_lock) {
                ++h;
            }
        }
        if ((!v && h) || (!h && v)) {
            cout << "-1" << endl;
            continue;
        }

        if (!ok) {
            cout << "-1" << endl;
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != '#') {
                    continue;
                }
                ans += 1;
                queue<pair<int, int>> q;
                a[i][j] = '.';
                q.push({i, j});
                while (q.size()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto [dx, dy] : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, 1}, {0, -1}} ){
                        x += dx;
                        y += dy;
                        if (0 <= x && x < n && 0 <= y && y < m && a[x][y] == '#') {
                            a[x][y] = '.';
                            q.push({x, y});
                        }
                        x -= dx;
                        y -= dy;
                    }
                }
            }
        }
        cout << ans << endl;
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}