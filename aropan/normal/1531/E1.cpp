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


void gen(int l, int r, vector<tuple<int, int, int>>& a) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;

    a.push_back({l, m, r});
    gen(m, r, a);
    gen(l, m, a);
}


void recovery(vector<int>& a, int l, int r, vector<string>& p) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;

    vector<int> b(a.begin() + l, a.begin() + r);

    string s = p.back();
    p.pop_back();

    int i = l;
    int j = m;
    for (int ind = 0; ind < r - l; ++ind) {
        if (i < m && j < r) {
            if (s[ind] == '0') {
                a[i++] = b[ind];
            } else {
                a[j++] = b[ind];
            }
        } else if (i < m) {
            a[i++] = b[ind];
        } else if (j < r) {
            a[j++] = b[ind];
        } else {
            assert(false);
        }
    }

    recovery(a, m, r, p);
    recovery(a, l, m, p);
}

int main(int /* argc */, const char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif


    string s;
    cin >> s;
    int n = 16;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    vector<tuple<int, int, int>> e;
    gen(0, n, e);
    reverse(all(e));
    int k = 0;

    vector<string> p;
    for (auto [l, m, r] : e) {
        int i = l;
        int j = m;
        string c;
        for (int ind = 0; ind < r - l; ++ind) {
            if (i < m && j < r) {
                c += s[k];
                if (s[k] == '0') {
                    ++i;
                } else {
                    ++j;
                }
                ++k;
            }
        }
        p.push_back(c);
    }
    recovery(a, 0, n, p);

    cout << n << nl;
    for (int i = 0; i < n; ++i) {
        i && cout << " ";
        cout << a[i];
    }
    cout << nl;

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}