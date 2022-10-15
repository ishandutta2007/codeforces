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

const int MAXT = 3e+5 * 4;
const ll INF = 1e+18 + 42;
const ll NONE = -INF;

struct TNode {
    ll color;
    ll maxv;

    TNode() {
        maxv = -INF;
        color = NONE;
    }
};

TNode nodes[MAXT];


void push(int x, ll val) {
    chmax(nodes[x].maxv, val);
    chmax(nodes[x].color, val);
}

void push(int x) {
    if (nodes[x].color == NONE) {
        return;
    }

    push(2 * x + 1, nodes[x].color);
    push(2 * x + 2, nodes[x].color);
    nodes[x].color = NONE;
}


ll getmax(int x, int l, int r, int lq, int rq) {
    if (lq <= l && r <= rq) {
        return nodes[x].maxv;
    }

    push(x);

    int c = (l + r) / 2;
    ll ret = -INF;
    if (lq < c) {
        chmax(ret, getmax(2 * x + 1, l, c, lq, rq));
    }
    if (c < rq) {
        chmax(ret, getmax(2 * x + 2, c, r, lq, rq));
    }

    return ret;
}

void updmax(int x, int l, int r, int lq, int rq, ll val) {
    if (lq <= l && r <= rq) {
        push(x, val);
        return;
    }

    push(x);

    int c = (l + r) / 2;
    if (lq < c) {
        updmax(2 * x + 1, l, c, lq, rq, val);
    }
    if (c < rq) {
        updmax(2 * x + 2, c, r, lq, rq, val);
    }

    nodes[x].maxv = max(nodes[2 * x + 1].maxv, nodes[2 * x + 2].maxv);
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
    while (cin >> n && n) {
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // for (int i = 0; i < n; ++i) {
        //     h[i] = i + 1;
        //     swap(h[i], h[rand() % (i + 1)]);
        // }
        // for (int i = 0; i < n; ++i) {
        //     b[i] = rand() % 200 - 50;
        // }

        // cout << endl;
        // cout << n << endl;
        // for (int i = 0; i < n; ++i) {
        //     i && cout << " ";
        //     cout << h[i];
        // }
        // cout << endl;
        // for (int i = 0; i < n; ++i) {
        //     i && cout << " ";
        //     cout << b[i];
        // }
        // cout << endl;

        // vector<ll> g(n + 1, -INF);
        // g[0] = 0;
        // for (int i = 0; i < n; ++i) {
        //     int opt = 1e+9 + 42;
        //     int val = -1;
        //     for (int j = i; j < n; ++j) {
        //         if (chmin(opt, h[j])) {
        //             val = b[j];
        //         }
        //         chmax(g[j + 1], g[i] + val);
        //     }
        // }
        // cout << g[n] << endl;


        vector<int> left(n);
        vector<int> right(n);
        {
            stack<pair<int, int>> st;
            st.push({0, -1});
            for (int i = 0; i < n; ++i) {
                while (st.top().first > h[i]) {
                    st.pop();
                }
                left[i] = st.top().second;
                st.push({h[i], i});
            }
        }

        {
            stack<pair<int, int>> st;
            st.push({0, n});
            for (int i = n - 1; i >= 0; --i) {
                while (st.top().first > h[i]) {
                    st.pop();
                }
                right[i] = st.top().second;
                st.push({h[i], i});
            }
        }

        int m = n + 1;
        for (int i = 0; i <= 4 * m; ++i) {
            nodes[i].color = NONE;
            nodes[i].maxv = -INF;
        }

        for (int i = 0; i < n; ++i) {
            ll maxv = getmax(0, 0, m, left[i] + 1, i + 1);
            // cout << left[i] + 1 << ".." << i << " = " << maxv << endl;
            if (left[i] == -1) {
                chmax(maxv, 0LL);
            }
            maxv += b[i];
            // cout << i << " " << maxv << ": " << i + 1 << ".." << right[i] << endl;
            updmax(0, 0, m, i + 1, right[i] + 1, maxv);
        }
        ll answer = getmax(0, 0, m, n, n + 1);
        // assert(answer == g[n]);
        cout << answer << nl;
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}