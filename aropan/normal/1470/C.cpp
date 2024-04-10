#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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

vector<ll> A;
vector<int> l;
vector<int> r;
int P;

int n, k;

void next(vector<ll>& a, int p = 0) {
    vector<ll> b(n, 0);
    for (int i = 0; i < n; ++i) {
        int x = i == p? 0 : a[i] / 2;
        b[l[i]] += x;
        b[r[i]] += a[i] - x;
    }
    a.swap(b);
}

int query(int x) {
    cout << "? " << x + 1 << endl;
    cout.flush();
    int ret;
#ifdef LOCAL
    ret = A[x];
    next(A, P);
#else
    cin >> ret;
#endif
    return ret;
}

void answer(int x) {
    cout << "! " << x + 1 << endl;
    cout.flush();
#ifdef LOCAL
    assert(x == P);
#endif
}


int main(int /* argc */, const char** /* argv */)
{
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int k;
    cin >> n >> k;
    // for (;;) {
    //     n = uniform_int_distribution<>(4, 100000)(rng);
        vector<ll> a(n, k);
        P = uniform_int_distribution<>(0, n - 1)(rng);
        A = a;

        vector<int> f(n, true);

        l = vector<int>(n);
        r = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            l[i] = (i + n - 1) % n;
            r[i] = (i + n + 1) % n;
        }

        int m = n;
        int cnt = 0;

        vector<int> last;
        bool stop = false;
        for (int iter = 0; iter < 1000 && m > 1; ++iter) {
            ++cnt;
            int x;
            if (n <= 500) {
                x = iter % n;
            } else {
                if (last.size() == 0) {
                    int idx = uniform_int_distribution<>(0, n - 1)(rng);
                    last.push_back(idx);
                    stop = false;
                }
                x = stop? last.back() : (last.back() + iter) % n;
                if (!stop) {
                    last.push_back(x);
                }
            }
            int v = query(x);
            if (v != k) {
                stop = true;
                if (last.size()) {
                    last.pop_back();
                }
            }

            for (int i = 0; i < n; ++i) {
                int y = (x - i + n) % n;
                if (f[y] && a[i] != v) {
                    f[y] = false;
                    --m;
                }
            }
            next(a);
        }

        dbg(n, P, m, cnt);
        for (int i = 0; i < n; ++i) {
            if (f[i]) {
                answer(i);
            }
        }
    // }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}