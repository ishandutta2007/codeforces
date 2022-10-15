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


const int MOD = 1e+9 + 7;

vector<int> f;
int m;



ll powmod(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll r = powmod(a, b >> 1);
    r = r * r % MOD;
    return (b & 1)? a * r % MOD : r;
}

ll divmod(ll a, ll b) {
    return a * powmod(b, MOD - 2) % MOD;
}

ll C(int n, int k) {
    return divmod(divmod(f[n], f[k]), f[n - k]);
}

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
        ll h, w;
        h = w = 1;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (s == "UR" || s == "DL") {
                w += 1;
            } else if (s == "UL" || s == "DR") {
                h += 1;
            }  else {
                h += 1;
                w += 1;
            }
        }
        cout << h * w << nl;
    }


#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}