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
        int r, c;
        cin >> r >> c;
        --r;
        --c;
        int x, y;
        cin >> x >> y;
        vector<vector<int>> f(n, vector<int>(m));
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < m; ++j) {
                f[i][j] = 0;
            }
        }
        deque<tuple<int, int, int, int>> q;
        auto add = [&f, &q, &n, &m, &a](int r, int c, int x, int y, bool s) {
            if (r < 0 || n <= r || c < 0 || m <= c) {
                return;
            }
            if (x < 0 || y < 0 || f[r][c] || a[r][c] == '*') {
                return;
            }
            f[r][c] = true;
            if (s) {
                q.push_back(make_tuple(r, c, x, y));
            } else {
                q.push_front(make_tuple(r, c, x, y));
            }
        };
        add(r, c, x, y, false);

        int ans = 0;
        while (q.size()) {
            ans += 1;
            tie(r, c, x, y) = q.front();
            q.pop_front();

            add(r - 1, c, x, y, false);
            add(r + 1, c, x, y, false);
            add(r, c - 1, x - 1, y, true);
            add(r, c + 1, x, y - 1, true);
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}