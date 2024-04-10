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
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int n;
    cin >> n;

#ifdef LOCAL
    vector<int> P(n);
    for (int i = 0; i < n; ++i) {
        P[i] = i + 1;
        swap(P[i], P[rand() % (i + 1)]);
    }
#endif

    auto query = [&](vector<int>& a) {
        cout << "?";
        for (auto x : a) {
            cout << " " << x;
        }
        cout << endl;
        cout.flush();
        int k = 0;
#ifdef LOCAL
        for (auto x : a) {
            assert(1 <= x && x <= n);
        }
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int x = P[i] + a[i];
            m[x] += 1;
        }
        for (int i = 0; i < n; ++i) {
            int x = P[i] + a[i];
            if (m[x] > 1) {
                k = i + 1;
                break;
            }
        }
        assert(0 <= k && k <= n);
#else
        cin >> k;
#endif
        return k - 1;
    };

    const int UNDEF = -1;
    vector<int> result(n, UNDEF);

    int pos = n - 1;
    int left = n;
    for (;;) {
        while (pos >= 0 && result[pos] != UNDEF) {
            --pos;
        }
        if (pos < 0) {
            break;
        }

        vector<int> b;

        for (int d = 1; d < n; ++d) {
            auto a = ivec1d(int, n, 1);
            a[pos] = d + 1;

            int res = query(a);
            if (res == -1 || res == pos) {
                break;
            }

            b.push_back(res);
        }

        int val = left - sz(b);
        result[pos] = val;
        for (int i = 0; i < sz(b); ++i) {
            result[b[i]] = val + i + 1;
        }
        left -= sz(b) + 1;
    }

    cout << "!";
    for (auto& x : result) {
        cout << " " << x;
    }
    cout << endl;
    cout.flush();

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}