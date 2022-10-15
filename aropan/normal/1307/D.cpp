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

    int n, m, k;
    while (cin >> n >> m >> k) {
        set<int> s;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            --x;
            s.insert(x);
            a[i] = x;
        }

        vector<vector<int>> e(n);
        bool ok = false;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
            ok |= s.count(u) && s.count(v);
        }

        auto run_queue = [&](int st) -> vector<int> {
            queue<int> q;
            vector<int> d(n, -1);
            d[st] = 0;
            q.push(st);
            while (q.size()) {
                int x = q.front();
                q.pop();
                for (auto y : e[x]) {
                    if (d[y] == -1) {
                        d[y] = d[x] + 1;
                        q.push(y);
                    }
                }
            }
            return d;
        };

        vector<int> d1 = run_queue(0);
        if (ok) {
            cout << d1[n - 1] << "\n";
            continue;
        }
        vector<int> dn = run_queue(n - 1);

        sort(all(a), [&](const int u, const int v) { return d1[u] > d1[v]; });

        int ans = 0;
        int mx = dn[a[0]];
        for (int i = 1; i < k; ++i) {
            ans = max(ans, min(mx, dn[a[i]]) + d1[a[i]] + 1);
            mx = max(mx, dn[a[i]]);
        }
        dbg(ans);
        ans = min(ans, d1[n - 1]);
        cout << ans << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}