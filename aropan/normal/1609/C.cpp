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

    vector<int> f(1e+6 + 42, 0);
    f[0] = f[1] = true;
    for (int i = 2; i * i < sz(f); ++i) {
        if (f[i]) {
            continue;
        }
        for (int j = i * i; j < sz(f); j += i) {
            f[j] = true;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll ans = 0;
        for (int st = 0; st < e; ++st) {
            vector<int> b;
            for (int i = st; i < n; i += e) {
                b.push_back(a[i]);
            }
            int m = sz(b);
            int idx = -1;
            // cout << b << endl;
            for (int i = 0, j = 0; i < m; ++i) {
                if (idx < i) {
                    idx = -1;
                }
                chmax(j, i);
                while (j < m && (b[j] == 1 || (idx == -1 && !f[b[j]]))) {
                    if (!f[b[j]]) {
                        idx = j;
                    }
                    j += 1;
                }

                if (idx == -1) {
                    continue;
                }

                // cout << i << " " << idx << " " << j << " = " << j - max(idx, i + 1) << nl;
                ans += j - max(idx, i + 1);
            }
        }
        cout << ans << nl;
    }


#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}