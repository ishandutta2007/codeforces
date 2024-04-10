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
#include <random>
#include <chrono>


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
vector<int> c;
vector<int> deep;
vector<int> a;
vector<int> ans;
vector<vector<int>> f;

bool dfs(int x, int d) {
    a.push_back(x);
    c[x] = 1;
    deep[x] = d;
    f[x].clear();

    auto add = [&](int y) {
        f[x].push_back(y);
        sort(all(f[x]), [&](const int u, const int v) { return deep[u] < deep[v]; });
        f[x].resize(min(2, (int)f[x].size()));
        while (f[x].size() && deep[*f[x].rbegin()] >= deep[x]) {
            f[x].pop_back();
        }
    };

    for (int y : e[x]) {
        if (c[y]) {
            if (c[y] == 1) {
                add(y);
                continue;
            } else {
                return false;
            }
        }
        if (!dfs(y, d + 1)) {
            return false;
        }
        for (auto& i : f[y]) {
            add(i);
        }
    }
    c[x] = 2;
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

    int t;
    cin >> t;
    int idx = 0;
    // t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // n = 100000;
        // m = 200000;
        e = vector<vector<int>>(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            // if (i < n - 1) {
            //     u = i;
            //     v = i + 1;
            // } else {
            //     u = rand() % n;
            //     v = rand() % n;
            // }
            e[u].push_back(v);
        }

        bool ok = false;
        ans.clear();
        int cnt = 0;
        deep = vector<int>(n, 0);
        f = vector<vector<int>>(n);
        mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
        auto gen = uniform_int_distribution<>(0, n - 1);
        for (int iter = 0; iter < 100; ++iter) {
            int root = gen(rnd);
            c = vector<int>(n, 0);
            a.clear();
            if (!dfs(root, 0)) {
                continue;
            }
            if ((int)a.size() != n) {
                continue;
            }

            vector<int> res(n, 0);

            a.erase(a.begin());
            res[root] = true;
            cnt = 1;

            for (auto& x : a) {
                if (f[x].size() != 1) {
                    continue;
                }
                if (!res[f[x][0]]) {
                    continue;
                }
                cnt += 1;
                res[x] = true;
            }

            if (ans.size()) {
                if (res != ans) {
                    dbg(f);
                    dbg(res);
                    dbg(ans);
                    dbg(e);
                    exit(0);
                }
            } else {
                ans = res;
            }
            ok = true;
#ifndef LOCAL
            break;
#endif
        }
        ok &= cnt * 5 >= n;
        if (!ok) {
            idx += 1;
            cout << -1 << endl;
        } else {
            bool first = true;
            for (int i = 0; i < n; ++i) {
                if (!ans[i]) {
                    continue;
                }
                idx += 1;
                if (!first) {
                    cout << " ";
                }
                first = false;
                cout << i + 1;
            }
            cout << endl;
        }
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}