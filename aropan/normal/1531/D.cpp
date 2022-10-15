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
typedef pair<int, int> pii;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));


map<string, int> c2i;
vector<string> i2c;
vector<string> a;

struct TNode {
    pii result[2];

    void init(int c) {
        if (c == -1) {
            result[0] = {1, 0};
            result[1] = {1, 0};
        } else if (c == -2) {
            result[0] = {0, 0};
            result[1] = {0, 0};
        } else {
            result[0] = {0, c};
            result[1] = {1, 0};
        }
    }

    void merge(const TNode& a, const TNode& b) {
        for (int i = 0; i < 2; ++i) {
            auto [s1, c1] = a.result[i];
            auto [s2, c2] = b.result[s1];
            if (c2 == 0) {
                c2 = c1;
            }
            result[i] = {s2, c2 == 0? c1 : c2};
        }
    }
};

vector<TNode> nodes;

void build(int x, int l, int r) {
    if (l + 1 == r) {
        nodes[x].init(c2i[a[l]]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * x + 1, l, m);
    build(2 * x + 2, m, r);

    nodes[x].merge(nodes[2 * x + 1], nodes[2 * x + 2]);
}

void update(int x, int l, int r, int i, string& s) {
    if (l + 1 == r) {
        nodes[x].init(c2i[s]);
    } else {
        int m = (l + r) / 2;
        if (i < m) {
            update(2 * x + 1, l, m, i, s);
        } else {
            update(2 * x + 2, m, r, i, s);
        }
        nodes[x].merge(nodes[2 * x + 1], nodes[2 * x + 2]);
    }
}

int main(int /* argc */, const char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int n;
    cin >> n;
    a.resize(n);
    c2i["lock"] = -1;
    c2i["unlock"] = -2;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = s;
        if (!c2i.count(s)) {
            c2i[s] = i2c.size() + 1;
            i2c.push_back(s);
        }
    }
    nodes.resize(4 * n);
    build(0, 0, n);

    int color = nodes[0].result[0].second;
    cout << (color? i2c[color - 1] : "blue") << endl;
    int m;
    cin >> m;
    while (m--) {
        int x;
        string s;
        cin >> x >> s;
        if (!c2i.count(s)) {
            c2i[s] = i2c.size() + 1;
            i2c.push_back(s);
        }
        update(0, 0, n, x - 1, s);

        int color = nodes[0].result[0].second;
        cout << (color? i2c[color - 1] : "blue") << endl;
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}