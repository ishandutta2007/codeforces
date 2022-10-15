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


int prv;
vector<ll> a;

int get(ll y) {
    cout << y << endl;
    cout.flush();

#ifdef LOCAL
    set<ll> st;
    for (int i = 0; i < 3; ++i) {
        st.insert(a[i]);
    }
    vector<int> b;
    for (int i = 0; i < 3; ++i) {
        if (!st.count(a[i] + y) && i != prv) {
            b.push_back(i);
        }
    }
    if (b.size() == 0) {
        return -1;
    }
    int ret = b[uniform_int_distribution<>(0, sz(b) - 1)(rng)];
    prv = ret;
    return ret;
#endif

    int x;
    cin >> x;
    if (x == 0) {
        exit(0);
    }
    return x - 1;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef LOCAL
    for (;;) {
#endif
        prv = -1;
        a.resize(3);
        ll m = 0;
        int t;
        for (int i = 0; i < 3; ++i) {
#ifdef LOCAL
            a[i] = uniform_int_distribution<>(1, (int)1e+9)(rng);
#else
            cin >> a[i];
#endif
            chmax(m, a[i]);
        }
        cout << "First" << endl;
        t = get(m);
        a[t] += m;

        vector<ll> b = a;
        sort(all(b));
        dbg(a, b);

        ll x = 2 * b[2] - b[0] - b[1];
        t = get(x);
        a[t] += x;

        b = a;
        sort(all(b));
        dbg(a, b);

        t = get(b[1] - b[0]);
#ifdef LOCAL
        if (t == -1) {
            continue;
        }
        cerr << "WA" << endl;
        exit(1);
    }
#endif

    return 0;
}