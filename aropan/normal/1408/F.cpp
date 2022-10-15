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


struct TPair {
    int x, y;
};

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    int n;
    while (cin >> n) {
    // for (n = 14; ; ++n) {
        vector<TPair> ans;
        vector<int> f[2];

        int m = 0;
        for (int bit = 30; bit >= 0; --bit) {
            {
                int k = ans.size();
                for (int i = 0; i < k; ++i) {
                    ans.push_back({ans[i].x + m, ans[i].y + m});
                }
                for (int i = 0; i < 2; ++i) {
                    int k = f[i].size();
                    for (int j = 0; j < k; ++j) {
                        f[i].push_back(f[i][j] + m);
                    }
                    for (int j = 0; j < k; ++j) {
                        ans.push_back({f[i][j], f[i][j + k]});
                    }
                }
                m = m * 2;
            }

            if (n & (1 << bit)) {
                int x = f[0].size() < f[1].size()? 0 : 1;
                f[x].push_back(m++);

                int k = f[x].size();
                int l = f[1 - x].size();

                int t = 1;
                while (t < (int)k) {
                    t *= 2;
                }

                while (t > k) {
                    int v = f[1 - x][--l];
                    f[x].push_back(v);
                    f[1 - x].pop_back();
                    ++k;
                }

                for (int p = 1; p < k; p *= 2) {
                    for (int i = 0; i < k; i += p + p) {
                        for (int j = 0; j < p; ++j) {
                            ans.push_back({f[x][i + j], f[x][i + j + p]});
                        }
                    }
                }

#ifdef LOCAL
                assert(l == f[1 - x].size());
                assert(k == f[x].size());
#endif
            }
            // dbg(f[0]);
            // dbg(f[1]);
        }
        assert(ans.size() <= 5 * 1e+5);

        cout << ans.size() << nl;

        for (auto& [a, b] : ans) {
            cout << a + 1 << " " << b + 1 << nl;
        }
        //
        // vector<string> res(n);
        // for (int i = 0; i < n; ++i) {
        //     res[i] = to_string(i);
        // }

        // for (auto& [a, b] : ans) {
        //     string v = "{" + res[a] + "," + res[b] + "}";
        //     res[a] = v;
        //     res[b] = v;
        //     cout << a + 1 << " " << b + 1 << nl;
        // }

        // map<string, int> mp;
        // for (auto& c : res) {
        //     if (!mp.count(c)) {
        //         mp[c] = mp.size();
        //     }
        //     cout << mp[c] << endl;
        // }
        // for (int i = 0; i < 2; ++i) {
        //     cout << f[i] << nl;
        //     for (auto& x : f[i]) {
        //         cout << mp[res[x]] << " ";
        //     }
        //     cout << nl;
        // }

        // set<string> s(all(res));
        // dbg(n, s.size());
        // for (auto& c : res) {
        //     cout << c << endl;
        // }
        // assert(s.size() <= 2);
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}