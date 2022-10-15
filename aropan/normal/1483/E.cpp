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

ll M;
ll counter;
ll current;

bool get(ll x) {
    assert(1 <= x <= 1e+14 + 1e-9);
    bool ret;
    ++counter;

    cout << "? " << x << endl;
    cout.flush();

#ifdef LOCAL
    ret = x <= M;
#else
    string s;
    cin >> s;
    if (s == "Fired!") {
        exit(0);
    }
    ret = s == "Lucky!";
#endif

    if (ret) {
        current += x;
    } else {
        current -= x;
    }

#ifdef LOCAL
    assert(current >= 0);
#endif

    return ret;
}

int main(int /* argc */, const char** /* argv */)
{
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int t;
    cin >> t;

    ll limit = 1e+14;
    while (t--) {
#ifdef LOCAL
        cin >> M;
#endif
    // for (;;) {
    // M = (1LL << 46) + 500;
    // for (int iter = 0; iter < 1000; ++iter) {
    //     ++M;

        current = 1;
        counter = 0;

        ll left = 0;
        ll right = 1;
        ll x = 1;
        while (x <= limit && get(x)) {
            left = x;
            x *= 2;
            right = x;
        }
        right = min(right, limit + 1);

        while (left + 1 < right) {
            ld la = 0;
            ld ra = 1;
            for (int i = 0; i < 20; ++i) {
                ld alpha = (la + ra) / 2;
                auto cnt = counter;
                auto val = current;

                ll l = left;
                ll r = right;
                while (l + 1 < r) {
                    ll m = l + 1 + (r - l) * alpha;
                    m = max(m, l + 1);
                    m = min(m, r - 1);
                    while (val < m) {
                        val += l;
                        cnt += 1;
                    }
                    cnt += 1;
                    r = m;
                    val -= m;
                }
                if (cnt > 103) {
                    ra = alpha;
                } else {
                    la = alpha;
                }
            }
            ld alpha = (la + ra) / 2;
            ll middle = left + 1 + (right - left) * alpha;
            middle = max(middle, left + 1);
            middle = min(middle, right - 1);

            while (current < middle) {
                get(left);
            }

            if (get(middle)) {
                left = middle;
            } else {
                right = middle;
            }
        }
        dbg(M, counter);
        assert(counter <= 105);

        ll answer = left;
#ifdef LOCA
        assert(M == answer);
#endif
        cout << "! " << answer << endl;
        cout.flush();
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}