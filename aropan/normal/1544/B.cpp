#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <variant>
#include <sstream>
#include <memory>
#include <functional>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
#define sz(v) ((int)(v).size())

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#ifdef LOCAL
#include "pretty_print.h"
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define nl "\n"

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));


int main(int /* argc */, const char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        auto ans = ivec2d(int, n, m, 0);
        int opt = -1;

        int k = n + m + n + m - 4;

        for (int st = 0; st < m; ++st) {
            int row = 0;
            int col = st;
            int drow = 0;
            int dcol = 1;
            auto a = ivec2d(int, n, m, 0);
            int res = 0;


            for (int z = 0; z < k; ++z) {
                bool ok = true;
                for (int dx = -1; dx <= 1 && ok; ++dx) {
                    for (int dy = -1; dy <= 1 && ok; ++dy) {
                        int x = row + dx;
                        int y = col + dy;
                        if (0 <= x && x < n && 0 <= y && y < m && a[x][y]) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    res += 1;
                    a[row][col] = 1;
                }

                {
                    int x = row + drow;
                    int y = col + dcol;
                    if (x < 0 || y < 0 || n <= x || m <= y) {
                        swap(drow, dcol);
                        dcol = -dcol;
                    }
                }

                row += drow;
                col += dcol;
            }
            if (res > opt) {
                opt = res;
                ans = a;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j];
            }
            cout << nl;
        }
        cout << nl;
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}