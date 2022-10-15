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
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
#endif


    int t;
    cin >> t;
    while (t--) {
        int n, p, q;
        cin >> n >> p >> q;
        q -= p;
        vector<int> a(n);
        vector<int> c(n + 1);
        priority_queue<pair<int, int>> h;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            c[a[i]] += 1;
        }

        int e = -1;
        for (int i = 0; i <= n; ++i) {
            if (c[i]) {
                h.push({c[i], i});
            } else {
                e = i;
            }
        }

        vector<int> b(n + 1);
        while (p && h.size()) {
            p--;
            auto [k, x] = h.top();
            h.pop();
            b[x] += 1;
            c[x] -= 1;
            if (c[x]) {
                h.push({c[x], x});
            }
        }

        vector<vector<int>> s(n + 1);
        vector<pair<int, int>> v;
        int x, y;
        x = y = -1;
        while (q > 0 && h.size() > 1) {
            int _;
            tie(_, x) = h.top();
            h.pop();
            tie(_, y) = h.top();
            h.pop();
            c[x] -= 1;
            c[y] -= 1;
            s[x].push_back(y);
            s[y].push_back(x);
            v.push_back({x, y});
            if (c[x]) {
                h.push({c[x], x});
            }
            if (c[y]) {
                h.push({c[y], y});
            }
            q -= 2;
        }
        if (q > 0 && h.size()) {
            auto [_, z] = h.top();
            h.pop();

            bool ok = false;
            for (auto [x, y] : v) {
                if (x != z && y != z) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                s[x].pop_back();
                s[y].pop_back();
                s[x].push_back(y);
                s[y].push_back(z);
                s[z].push_back(x);
                q -= 1;
            }
        }
        if (q < 0 && x != -1) {
            s[x].pop_back();
            ++q;
        }

        if (p || q) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
            for (int i = 0; i < n; ++i) {
                i && cout << " ";
                int x = e;
                if (b[a[i]]) {
                    b[a[i]]--;
                    x = a[i];
                } else if (s[a[i]].size()) {
                    x = s[a[i]].back();
                    s[a[i]].pop_back();
                }
                cout << x + 1;
            }
            cout << nl;
        }
    }


#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}