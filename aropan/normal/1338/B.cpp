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


vector<vector<int>> e;
int n;
int cnt, last;


void dfs(int x, int p, int d) {
    if (e[x].size() == 1) {
        if (last == 0 || last % 2 != d % 2) {
            last = d;
            ++cnt;
        }
    }

    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        dfs(y, x, d + 1);
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
        e = vector<vector<int>>(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --v;
            --u;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int root = 0;
        while (e[root].size() == 1) {
            ++root;
        }
        cnt = 0;
        last = -1;
        dfs(root, -1, 0);

        cout << (cnt == 1? 1 : 3) << " ";

        int ans = n - 1;
        for (int x = 0; x < n; ++x) {
            int c = 0;
            for (auto& y : e[x]) {
                if (e[y].size() == 1) {
                    c += 1;
                }
            }
            ans -= max(c - 1, 0);
        }
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}