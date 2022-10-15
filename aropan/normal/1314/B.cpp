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


const int INF = 1e+9 + 42;

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
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
            --a[i];
        }
        sort(all(a));

        vector<pair<int, int>> v(m, make_pair(INF, INF));

        for (int i = 1; i < m; ++i) {
            int d = 0;
            for (int x = a[i - 1], y = a[i]; x != y; ++d) {
                x >>= 1;
                y >>= 1;
            }
            v[i - 1].second = d;
            v[i].first = d;
        }
        for (int i = 0; i < m; ++i) {
            if (v[i].first > v[i].second) {
                swap(v[i].first, v[i].second);
            }
        }

        vector<int> p(m);
        for (int i = 0; i < m; ++i) {
            p[i] = i;
        }
        sort(all(p), [&](const int i, const int j) { return v[i] < v[j]; });

        set<pair<int, int>> ws, ls;
        int ans = 0;
        for (auto& idx : p) {
            int x = a[idx];

            if (!ws.count({0, x >> 1})) {
                ws.insert({0, x >> 1});
                ++ans;
            }

            int wr = 0;
            for (int i = 1, v = x >> 1; i < n; ++i) {
                v >>= 1;
                wr += ws.count({i, v}) == 0;
            }


            int lr = 0;
            for (int i = 1, v = x >> 1; i < n; ++i) {
                v >>= 1;
                lr += 2 * (ls.count({i, v}) == 0);
            }

            if (wr > lr) {
                ans += wr;
                for (int i = 1, v = x >> 1; i < n; ++i) {
                    v >>= 1;
                    ws.insert({i, v});
                }
            } else {
                ans += lr;
                for (int i = 1, v = x >> 1; i < n; ++i) {
                    v >>= 1;
                    ls.insert({i, v});
                }
            }
        }
        if (m) {
            ++ans;
        }
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}