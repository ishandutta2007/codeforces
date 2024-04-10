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

    vector<vector<int>> ds = {
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1},
    };
    int n, k;
    while (cin >> n >> k) {
        vector<vector<int>> a(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            vector<int> b(7);
            for (int j = 0; j < 7; ++j) {
                b[j] = s[j] == '1';
            }
            a[i] = b;
        }
        reverse(all(a));
        vector<vector<int>> f(n + 1, vector<int>(k + 1, -1));
        vector<vector<int>> p(n + 1, vector<int>(k + 1, -1));
        f[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            auto b = a[i];
            vector<int> c(10, -1);
            for (int j = 0; j < 10; ++j) {
                int v = 0;
                for (int t = 0; t < 7; ++t) {
                    if (!ds[j][t] && b[t]) {
                        v = -1;
                        break;
                    }
                    v += ds[j][t] && !b[t];
                }
                c[j] = v;
            }
            for (int j = 0; j <= k; ++j) {
                if (f[i][j] == -1) {
                    continue;
                }
                for (int d = 0; d < 10; ++d) {
                    if (c[d] == -1) {
                        continue;
                    }
                    int x = j + c[d];
                    if (x <= k) {
                        if (chmax(f[i + 1][x], d)) {
                            p[i + 1][x] = j;
                        }
                    }
                }
            }
        }
        if (f[n][k] == -1) {
            cout << "-1" << "\n";
            continue;
        }
        vector<int> s;
        {
            int x = k;
            for (int i = n; i >= 1; --i) {
                s.push_back(f[i][x]);
                x = p[i][x];
            }
        }
        for (auto& x : s) {
            cout << x;
        }
        cout << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}