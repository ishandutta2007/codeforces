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

vector<vector<pair<int, int>>> e;
vector<int> o;
vector<int> f;
vector<int> ans;

void dfs(int x) {
    while (o[x] < (int)e[x].size()) {
        auto& p = e[x][o[x]++];
        if (f[abs(p.second)]) {
            continue;
        }
        f[abs(p.second)] = true;
        dfs(p.first);
        ans.push_back(p.second);
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int m;
    // for (;;) {
    while (cin >> m) {
        // m = 500000;
        vector<int> a(m);
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
            cin >> b[i];
            // a[i] = rand() % (1 << 20);
            // b[i] = rand() % (1 << 20);
        }

        e = vector<vector<pair<int, int>>>(1 << 20);
        o = vector<int>(1 << 20, 0);
        f = vector<int>(m + 1, 0);
        int k;
        for (k = 20; k >= 0; --k) {
            int n = 1 << k;
            int msk = n - 1;
            for (int i = 0; i < n; ++i) {
                e[i].clear();
                o[i] = 0;
            }
            for (int i = 0; i < m; ++i) {
                f[i] = false;
                int u = a[i] & msk;
                int v = b[i] & msk;
                int idx = i + 1;
                e[u].push_back({v, idx});
                e[v].push_back({u, -idx});
            }
            for (int i = 0; i <= m; ++i) {
                f[i] = false;
            }
            ans.clear();
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                ok &= (e[i].size() & 1) == 0;
            }
            if (ok) {
                for (int i = 0; i < n; ++i) {
                    if (e[i].size()) {
                        dfs(i);
                        break;
                    }
                }
                ok = (int)ans.size() == m;
            }
            if (ok) {
                break;
            }
        }

        cout << k << "\n";
        int lst = -1;
        for (int i = 0; i < (int)ans.size(); ++i) {
            if (i) {
                cout << " ";
            }
            int idx = ans[i];
            int u = 2 * abs(idx) - 1;
            int v = 2 * abs(idx);
            int uv = a[abs(idx) - 1];
            int vv = b[abs(idx) - 1];
            if (idx > 0) {
                swap(u, v);
                swap(uv, vv);
            }
            cout << u << " " << v;
            if (i) {
                assert((lst ^ uv) % (1 << k) == 0);
            }
            lst = vv;
        }
        cout << "\n";
        // dbg(ans);
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}