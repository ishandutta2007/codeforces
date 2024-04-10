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

    enum TResult {
        NONE = 0,
        OK = 1,
        FAIL = 2,
    };

    map<pair<int, int>, TResult> f;

    function<TResult(int, int)> rec;
    rec = [&](int n, int m) {
        if (n * n < m) {
            return FAIL;
        }
        if (m == 0) {
            return OK;
        }
        auto& result = f[{n, m}];
        if (result == NONE) {
            result = rec(n - 1, m);
            for (int i = 1; i <= n && result != OK; ++i) {
                result = rec(i - 1, m - 2 * i + 1);
            }
        }
        return result;
    };

    int m;
    while (cin >> m && m) {
        int n = 1;
        while (rec(n, m) != OK && n * n - 2 * n + 1 < m) {
            ++n;
        }
        if (rec(n, m) != OK) {
            cout << -1 << nl;
        } else {
            cout << n << nl;
            auto a = ivec2d(int, n, n, 0);
            for (int j = 0; m; ++j) {
                while (rec(n - 1, m) == OK) {
                    --n;
                }
                for (int i = 1; i <= n; ++i) {
                    if (rec(i - 1, m - 2 * i + 1) == OK) {
                        n = i - 1;
                        m = m - 2 * i + 1;

                        for (int k = 0; k < i; ++k) {
                            a[j][k + j] = 1;
                            a[k + j][j] = 1;
                        }
                        break;
                    }
                }
            }
            reverse(all(a));
            for (auto& b : a) {
                for (auto &x : b) {
                    cout << (x? 'o' : '.');
                }
                cout << nl;
            }
        }
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}