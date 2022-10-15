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
        int q = 0;
        cin >> n;
        // n = 101;
        vector<int> a(n);
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }

        // {
        //     vector<int> b(n);
        //     for (int i = 0; i < n; ++i) {
        //         b[i] = i;
        //         swap(b[i], b[rand() % (i + 1)]);
        //     }
        //     int even = 0;
        //     int odd = 1;
        //     for (auto& x : b) {
        //         if (x & 1) {
        //             a[odd] = x;
        //             odd += 2;
        //         } else {
        //             a[even] = x;
        //             even += 2;
        //         }
        //     }
        // }

        for (int i = 0; i < n; ++i) {
            p[a[i]] = i;
        }

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if ((a[i] + i) & 1) {
                ok = false;
            }
        }
        if (!ok) {
            cout << -1 << nl;
            continue;
        }

        vector<int> ret;

        auto swapping = [&](int k) {
            if (k == 1) {
                return;
            }
            q += 1;
            assert(k % 2 == 1);
            reverse(a.begin(), a.begin() + k);
            for (int i = 0; i < k; ++i) {
                p[a[i]] = i;
            }
            if (ret.size() && ret.back() == k) {
                ret.pop_back();
            } else {
                ret.push_back(k);
            }
        };

        // for (int i = 0; i < n; ++i) {
        //     int k = rand() % n / 2 * 2 + 1;
        //     swapping(k);
        // }

        for (int i = 0; i + 1 < n; i += 2) {
            swapping(p[i] + 1);
            swapping(p[i + 1]);
            if (p[i] != 0) {
                swapping(p[i + 1] + 2);
                swapping(3);
            }
            swapping(n - i);
        }
        swapping(n);

        for (int i = 0; i < n; ++i) {
            assert(a[i] == i);
        }
        assert(5 * n / 2 >= q);
        // dbg(q);

        cout << ret.size() << nl;
        for (int i = 0; i < sz(ret); ++i) {
            i && cout << " ";
            cout << ret[i];
        }
        cout << nl;
    }


#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}