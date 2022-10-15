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

    int _, n;
    cin >> _ >> n;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    vector<pair<int, int>> p(n);
    vector<tuple<int, int, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
        a[i] = make_tuple(x, y, i);
        b[i] = make_tuple(y, x, i);
    }

    vector<vector<pair<int, int>>> e(n);
    for (auto& s : vector{a, b}) {
        sort(all(s));
        for (int i = 1; i < n; ++i) {
            auto [x1, y1, u] = s[i - 1];
            auto [x2, y2, v] = s[i];
            int d = min(abs(x1 - x2), abs(y1 - y2));
            e[u].push_back({v, d});
            e[v].push_back({u, d});
        }
    }

    priority_queue<pair<ll, int>> h;
    vector<ll> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = min(abs(sx - p[i].first), abs(sy - p[i].second));
        h.push({-d[i], i});
    }

    while (h.size()) {
        int x;
        ll w;
        tie(w, x) = h.top();
        h.pop();
        w = -w;
        if (d[x] != w) {
            continue;
        }
        for (auto& [y, c] : e[x]) {
            if (chmin(d[y], w + c)) {
                h.push({-d[y], y});
            }
        }
    }

    ll ans = abs(sx - fx) + abs(sy - fy);
    for (int i = 0; i < n; ++i) {
        chmin(ans, d[i] + abs(fx - p[i].first) + abs(fy - p[i].second));
    }

    cout << ans << nl;

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}