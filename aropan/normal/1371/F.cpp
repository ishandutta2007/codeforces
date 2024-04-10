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

#define goleft(x) (2 * (x) + 0)
#define goright(x) (2 * (x) + 1)

struct TNode {
    int res01;
    int res10;
    int suff[2][2];
    int pref[2][2];
    int len;
    int inv;

    TNode() {
        res01 = 0;
        res10 = 0;
        memset(suff, 0, sizeof(suff));
        memset(pref, 0, sizeof(pref));
        inv = 0;
        len = 0;
    }
};

int n, m;
vector<TNode> nodes;
int root = 1;

void merge(const TNode& a, const TNode& b, TNode& c) {
    c.res01 = max(a.res01, b.res01);
    chmax(c.res01, a.suff[0][1] + b.pref[1][1]);
    chmax(c.res01, a.suff[0][0] + b.pref[0][1]);

    c.res10 = max(a.res10, b.res10);
    chmax(c.res10, a.suff[1][0] + b.pref[0][0]);
    chmax(c.res10, a.suff[1][1] + b.pref[1][0]);

    c.len = a.len + b.len;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int v = a.pref[i][j];
            if (a.pref[i][i] == a.len) {
                chmax(v, a.len + b.pref[i][j]);
            }
            if (a.pref[i][j] == a.len) {
                chmax(v, a.len + b.pref[j][j]);
            }
            c.pref[i][j] = v;
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int v = b.suff[i][j];
            if (b.suff[j][j] == b.len) {
                chmax(v, b.len + a.suff[i][j]);
            }
            if (b.suff[i][j] == b.len) {
                chmax(v, b.len + a.suff[i][i]);
            }
            c.suff[i][j] = v;
        }
    }
}

void init(int x, TNode& c) {
    c.res01 = 1;
    c.res10 = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (i != x && j != x) {
                continue;
            }
            c.pref[i][j] = c.suff[i][j] = 1;
        }
    }
    c.len = 1;
}

TNode& build(int x, int l, int r, const string& s) {
    if (l + 1 == r) {
        init(s[l] == '>', nodes[x]);
    } else {
        int c = (l + r) / 2;
        merge(
            build(goleft(x), l, c, s),
            build(goright(x), c, r, s),
            nodes[x]
        );
    }
    return nodes[x];
}

void inverse(TNode& a) {
    swap(a.res01, a.res10);
    swap(a.pref[0][0], a.pref[1][1]);
    swap(a.pref[0][1], a.pref[1][0]);
    swap(a.suff[0][0], a.suff[1][1]);
    swap(a.suff[0][1], a.suff[1][0]);
    a.inv ^= 1;
}

void push(TNode& x, TNode& a, TNode& b) {
    if (!x.inv) {
        return;
    }
    x.inv ^= 1;
    inverse(a);
    inverse(b);
}

void get(int x, int l, int r, int L, int R, TNode& result) {
    if (L <= l && r <= R) {
        inverse(nodes[x]);
        merge(result, nodes[x], nodes[0]);
        result = nodes[0];
        return;
    }
    int left = goleft(x);
    int right = goright(x);
    push(nodes[x], nodes[left], nodes[right]);

    int c = (l + r) / 2;
    if (L < c) {
        get(left, l, c, L, R, result);
    }
    if (c < R) {
        get(right, c, r, L, R, result);
    }
    merge(nodes[left], nodes[right], nodes[x]);
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
#endif

    int n, q;
    while (cin >> n >> q) {
        string s;
        cin >> s;
        // s = "";
        // for (int i = 0; i < n; ++i) {
        //     s += (rand() % 2 == 0? '<' : '>');
        // }
        nodes = vector<TNode>(4 * n);
        m = 0;
        build(root, 0, n, s);

        while (q--) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            // l = uniform_int_distribution<>(0, n)(rng);
            // r = uniform_int_distribution<>(0, n)(rng);
            // if (l > r) {
            //     swap(l, r);
            // }
            TNode result;
            get(root, 0, n, l, r + 1, result);
            cout << result.res10 << nl;
        }
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}