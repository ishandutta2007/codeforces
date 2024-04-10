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


typedef pair<int, ll> TEdge;


#define Y first
#define C second

int n;
vector<vector<TEdge>> e;
vector<ll> w;
vector<vector<TEdge>> f;

void dfs_f(int x, int p) {
    f[x].clear();
    f[x].push_back({-1, 0});
    f[x].push_back({-1, 0});
    for (auto& i : e[x]) {
        int y = i.Y;
        ll c = i.C;
        if (y == p) {
            continue;
        }
        dfs_f(y, x);
        f[x].push_back({y, f[y][0].C - c});
        sort(all(f[x]), [](const TEdge& a, const TEdge& b) {
                return a.C > b.C;
        });
        if (f[x].size() > 2) {
            f[x].pop_back();
        }
    }
    for (auto& p : f[x]) {
        p.C += w[x];
    }
}


void dfs_s(int x, int p, ll up, ll& ans) {
    ans = max(ans, f[x][0].C + up);
    for (auto& i : e[x]) {
        int y = i.Y;
        ll c = i.C;
        if (y == p) {
            continue;
        }
        dfs_s(y, x, max(0LL, max(f[x][y == f[x][0].Y].C, w[x] + up) - c), ans);
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
    while (cin >> n) {
        e.resize(n);
        w.resize(n);
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            e[i].clear();
            cin >> w[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            --u;
            --v;
            e[v].push_back({u, c});
            e[u].push_back({v, c});
        }

        int root = 0;
        ll ans = 0;
        dfs_f(root, -1);
        dfs_s(root, -1, 0, ans);
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}