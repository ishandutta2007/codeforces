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
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int n, k;
    cin >> n >> k;

    vector<int> A(n);


#ifdef LOCAL
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        // A[i] = rand() % 1000000000;
    }
#endif

    auto query = [&](string op, int u, int v) {
        int ret = 0;
#ifdef LOCAL
        if (op == "and") {
            ret = A[u] & A[v];
        } else if (op == "or" ){
            ret = A[u] | A[v];
        } else {
            exit(1);
        }
#else
        cout << op << " " << u + 1 << " " << v + 1 << endl;
        cout.flush();
        cin >> ret;
        if (ret == -1) {
            exit(0);
        }
#endif
        return ret;
    };

    vector<int> a(n);

    int or01 = query("or", 0, 1);
    int or02 = query("or", 0, 2);
    int or12 = query("or", 1, 2);
    int and01 = query("and", 0, 1);
    int and02 = query("and", 0, 2);
    int and12 = query("and", 1, 2);

    for (int i = 0; i < 30; ++i) {
        int b = 1 << i;
        if (!((or01 | or12) & b)) {
            continue;
        }

        int c = 0;
        if ((and01 & b) || (and02 & b)) {
            a[0] |= b;
            ++c;
        }
        if ((and01 & b) || (and12 & b)) {
            a[1] |= b;
            ++c;
        }
        if ((and02 & b) || (and12 & b)) {
            a[2] |= b;
            ++c;
        }

        if (!c) {
            if ((or01 & b) && (or02 & b)) {
                a[0] |= b;
            }
            if ((or01 & b) && (or12 & b)) {
                a[1] |= b;
            }
            if ((or02 & b) && (or12 & b)) {
                a[2] |= b;
            }
        }
    }
    for (int i = 3; i < n; ++i) {
        int andv = query("and", 0, i);
        int orv = query("or", 0, i);
        a[i] = (orv ^ a[0]) | andv;
    }

#ifdef LOCAL
    assert(A == a);
#endif

    sort(all(a));
    cout << "finish " << a[k - 1] << nl;
    cout.flush();

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}