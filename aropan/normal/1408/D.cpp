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


struct TCoord {
    int x, y;
};

bool operator<(const TCoord& p, const TCoord& q) {
    return p.x < q.x || (p.x == q.x && p.y < q.y);
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int n, m;
    while (cin >> n >> m) {
        vector<TCoord> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].x >> a[i].y;
        }
        sort(all(a));
        vector<TCoord> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i].x >> b[i].y;
        }
        sort(all(b));

        vector<int> f(m + 1, -1);
        for (int i = m - 1; i >= 0; --i) {
            f[i] = max(f[i + 1], b[i].y);
        }

        vector<int> idx(n, 0);
        vector<int> g(n);
        multiset<int> s;
        priority_queue<pair<int ,int>> h;
        for (int i = 0; i < n; ++i) {
            int v = 0;
            for (int& j = idx[i]; j < m; ++j) {
                if (a[i].x <= b[j].x) {
                    v = max(0, f[j] - a[i].y + 1);
                    int d = b[j].x - a[i].x + 1;
                    h.push({-d, i});
                    break;
                }
            }
            g[i] = v;
            s.insert(v);
        }

        int ans = *s.rbegin();

        while (h.size()) {
            auto [d, i] = h.top();
            h.pop();
            d = -d;

            int& j = idx[i];
            ++j;
            s.erase(s.find(g[i]));
            if (j < m) {
                int v = max(0, f[j] - a[i].y + 1);
                int d = b[j].x - a[i].x + 1;
                h.push({-d, i});
                g[i] = v;
            } else {
                g[i] = 0;
            }
            s.insert(g[i]);

            chmin(ans, d + *s.rbegin());
        }

        cout << ans << nl;
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}