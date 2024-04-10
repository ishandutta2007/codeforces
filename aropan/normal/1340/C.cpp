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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n, m;
    while (cin >> n >> m) {
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        sort(all(a));
        int g, r;
        cin >> g >> r;
        vector<vector<int>> f(m, vector<int>(g + 1, 0));

        queue<int> st;
        queue<pair<int, int>> q;

        const ll INF = (ll)1e18;
        ll ans = INF;
        int iter = 0;

        auto add = [&](int x, int t) {
            if (t < 0 || f[x][t]) {
                return;
            }
            f[x][t] = true;
            if (t == 0) {
                st.push(x);
            } else {
                q.push({x, t});
            }

            if (x == m - 1) {
                chmin(ans, iter * (ll)(r + g) + g - t);
            }
        };
        add(0, 0);

        for (iter = 0; st.size() && ans == INF; ++iter) {
            while (st.size()) {
                q.push({st.front(), g});
                st.pop();
            }
            while (q.size()) {
                int x = q.front().first;
                int t = q.front().second;
                q.pop();

                if (0 < x) {
                    add(x - 1, t - (a[x] - a[x - 1]));
                }
                if (x + 1 < m) {
                    add(x + 1, t - (a[x + 1] - a[x]));
                }
            }
        }
        cout << (ans == INF? -1 : ans) << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}