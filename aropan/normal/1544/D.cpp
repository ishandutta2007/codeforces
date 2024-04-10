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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> in(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            --x;
            a[i] = x;
            in[x] = true;
        }

        vector<int> upd(n, -1);
        int cnt = 0;
        vector<int> p(n, -1);
        vector<int> f(n, 0);
        int ans = 0;
        for (int st = 0; st < n; ++st) {
            if (in[st]) {
                continue;
            }
            ++ans;

            int x = st;
            ++cnt;
            int prv = -1;
            while (!f[x]) {
                f[x] = true;
                int y = a[x];
                prv = x;
                if (p[y] == -1 || upd[y] == cnt) {
                    if (p[y] != -1) {
                        prv = p[y];
                    }
                    p[y] = x;
                }
                upd[y] = cnt;
                x = y;
            }
            int y = p[x];
            p[x] = prv;
            a[y] = st;
            p[st] = y;
        }

        cout << n - ans << nl;
        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << " ";
            }
            cout << a[i] + 1;
        }
        cout << nl;
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}