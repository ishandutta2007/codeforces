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
vector<vector<int>> r;
vector<int> f;
vector<int> g;

bool dfs(int x) {
    f[x] = 1;
    for (auto y : e[x]) {
        if (f[y] == 1) {
            return false;
        }
        if (f[y] == 2) {
            continue;
        }
        if (!dfs(y)) {
            return false;
        }
    }
    f[x] = 2;
    return true;
}


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
        e = vector<vector<int>>(n);
        r = vector<vector<int>>(n);
        f = vector<int>(n, 0);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            r[v].push_back(u);
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (f[i]) {
                continue;
            }
            ok &= dfs(i);
        }
        if (!ok) {
            cout << "-1" << endl;
            continue;
        }

        string ans(n, 'E');
        f = vector<int>(n, 0);
        g = vector<int>(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!f[i] && !g[i]) {
                ans[i] = 'A';
                ++cnt;
            }

            auto run = [](const int st, vector<int>& f, vector<vector<int>>& e) {
                queue <int> q;
                f[st] = true;
                q.push(st);
                while (q.size()) {
                    int x = q.front();
                    q.pop();
                    for (int y : e[x]) {
                        if (!f[y]) {
                            f[y] = true;
                            q.push(y);
                        }
                    }
                }
            };
            run(i, f, e);
            run(i, g, r);
        }
        cout << cnt << endl;
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}