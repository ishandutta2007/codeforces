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

#define goleft(x) ((x) * 2 + 1)
#define goright(x) ((x) * 2 + 2)


const int MAXN = 1e+5 + 42;
const int MAXT = 4 * MAXN;


struct TNode {
    ll balance;
    ll maxv;
    ll minv;

    TNode() {
        balance = 0;
        minv = 0;
        maxv = 0;
    };

    void merge(TNode a, TNode b) {
        balance = a.balance + b.balance;
        minv = min(a.minv, a.balance + b.minv);
        maxv = max(a.maxv, a.balance + b.maxv);
    }
};

TNode nodes[MAXT];
vector<ll> v;

void build_tree(int x, int l, int r) {
    if (l + 1 == r) {
        nodes[x].balance = v[l];
        nodes[x].maxv = max(0LL, v[l]);
        nodes[x].minv = min(0LL, v[l]);
    } else {
        int c = (l + r) / 2;
        build_tree(goleft(x), l, c);
        build_tree(goright(x), c, r);
        nodes[x].merge(nodes[goleft(x)], nodes[goright(x)]);
    }
}

void find_result(int x, int l, int r, int lq, int rq, TNode& result) {
    if (lq <= l && r <= rq) {
        result.merge(result, nodes[x]);
        return;
    }
    int c = (l + r ) / 2;
    if (lq < c) {
        find_result(goleft(x), l, c, lq, rq, result);
    }
    if (c < rq) {
        find_result(goright(x), c, r, lq, rq, result);
    }
}

int main(int /* argc */, const char** /* argv */)
{
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        v.resize(n);
        for (int i = 0; i < n; ++i) {
            v[i] = b[i] - a[i];
        }

        build_tree(0, 0, n);

        while (m--) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            TNode result;
            find_result(0, 0, n, l, r + 1, result);
            if (result.balance || result.minv < 0) {
                cout << -1 << nl;
            } else {
                cout << result.maxv << nl;
            }
        }
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}