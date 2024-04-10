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


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int n;
    while (cin >> n) {
    // for (;;) {
        // n = 200000;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            // a[i] = rand() % 100 + 1;
        }

//         dbg(a);
// #ifdef LOCAL
//         int result = 0;
//         for (int i = 0; i < n; ++i) {
//             map<int, int> mp;
//             int cnt = 0;
//             int opt = 0;
//             for (int j = i; j < n; ++j) {
//                 int x = ++mp[a[j]];
//                 if (x > opt) {
//                     opt = x;
//                     cnt = 0;
//                 }
//                 if (x == opt) {
//                     ++cnt;
//                 }
//                 if (cnt > 1) {
//                     chmax(result, j - i + 1);
//                 }
//             }
//         }
// #endif

        int m = min(n, 100);
        vector<int> upd(5e+5, 0);
        vector<int> val(5e+5, 0);
        int shift = 2.5e+5;
        int cnt = 0;
        int ans = 0;

        vector<int> updv(5e+5, 0);
        vector<int> valv(5e+5, 0);
        int cntv = 0;

        int x = 1;
        for (int i = 0; i < n; ++i) {
            if (val[x] < ++val[a[i]]) {
                x = a[i];
            }
        }

        for (int y = 1; y <= m; ++y) {
            if (x == y) {
                continue;
            }
            ++cnt;
            ++cntv;
            int s = shift;
            upd[s] = cnt;
            val[s] = -1;

            updv[x] = cntv;
            valv[x] = 0;
            updv[y] = cntv;
            valv[y] = 0;

            int opt = 0;
            for (int i = 0; i < n; ++i) {

                if (updv[a[i]] != cntv) {
                    updv[a[i]] = cntv;
                    valv[a[i]] = 0;
                }
                chmax(opt, ++valv[a[i]]);

                if (a[i] == x) {
                    ++s;
                } else if (a[i] == y) {
                    --s;
                }
                if (upd[s] != cnt) {
                    upd[s] = cnt;
                    val[s] = i;
                } else {
                    if ((valv[x] == opt || valv[y] == opt) && chmax(ans, i - val[s])) {
                        // dbg(x, y, opt, ans, s, val[s], i);
                    }
                }
            }
        }
// #ifdef LOCAL
//         dbg(result, ans);
//         if (result != ans) {
//             break;
//         }
// #endif
        cout << ans << nl;
    }




#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}