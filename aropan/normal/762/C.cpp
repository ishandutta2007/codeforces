#include <bits/stdc++.h>

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


int main(int /* argc */, const char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    string a, b;
    while (cin >> a >> b) {
        int n = sz(a);
        int m = sz(b);
        vector<int> f(m, 0);
        for (int i = 0, j = 0; i < m; ++i, ++j) {
            while (j < n && a[j] != b[i]) {
                ++j;
            }
            f[i] = j;
        }
        vector<int> g(m, 0);
        int ans = m;
        int st = 0;
        for (int i = m - 1, j = n - 1; i >= 0; --i, --j) {
            while (j >= 0 && a[j] != b[i]) {
                --j;
            }
            g[i] = j;
            if (g[i] >= 0) {
                ans = i;
            }
        }

        for (int i = 0, j = 0; i < m; ++i) {
            if (f[i] >= n) {
                break;
            }
            while (j <= i || (j < m && f[i] >= g[j])) {
                ++j;
            }
            dbg(i, j);
            if (chmin(ans, j - i - 1)) {
                st = i + 1;
            }
        }
        b.erase(b.begin() + st, b.begin() + st + ans);
        if (sz(b) == 0) {
            cout << "-" << nl;
        } else {
            cout << b << nl;
        }
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}