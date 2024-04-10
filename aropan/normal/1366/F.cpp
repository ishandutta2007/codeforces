#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MOD = 1e+9 + 7;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n, m, q;
    while (cin >> n >> m >> q) {
        vector<vector<pair<int, int>>> e(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            // u = i;
            // v = u + 1;
            // w = rand() % (rand() % 10 + 1) + 1;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }

        vector<ll> f(n, -1);
        f[0] = 0;
        ll ans = 0;
        int d = m;
        for (int i = 0; i < d; ++i) {
            vector<ll> g(n, -1);
            ll res = 0;
            for (int x = 0; x < n; ++x) {
                if (f[x] == -1) {
                    continue;
                }
                for (auto& [y, w] : e[x]) {
                    chmax(g[y], f[x] + w);
                }
            }
            f.swap(g);
            for (int x = 0; x < n; ++x) {
                chmax(res, f[x]);
            }
            ans += res;
            ans %= MOD;
        }
        q -= d;

        vector<pair<ll, ll>> a;
        for (int i = 0; i < n; ++i) {
            if (f[i] == -1) {
                continue;
            }
            ll b = 0;
            for (auto& [_, w] : e[i]) {
                chmax(b, (ll)w);
            }
            a.push_back({b, f[i]});
        }

        sort(all(a));
        stack<tuple<ll, ll, ll>> st;
        for (int i = 0; i < (int)a.size(); ++i) {
            auto& [k1, b1] = a[i];
            ll y = 0;
            while (st.size()) {
                auto& [k2, b2, x] = st.top();
                if (k1 == k2) {
                    st.pop();
                    continue;
                }

                ll dk = k1 - k2;
                y = (b2 - b1 + dk - 1) / dk;
                chmax(y, 1LL);

                if (y > x) {
                    break;
                }
                st.pop();
            }
            if (!st.size()) {
                 y = 1;
            }
            if (y > q) {
                continue;
            }
            st.push({k1, b1, y});
        }

        while (st.size()) {
            auto& [k, b, t] = st.top();
            st.pop();
            ll n = q - t + 1;
            if (n <= 0) {
                continue;
            }
            ans = (ans + (t + q) * n / 2 % MOD * k % MOD + b % MOD * n) % MOD;
            q = t - 1;
        }

        cout << ans << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}