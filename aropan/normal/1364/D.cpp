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

int n, m, k;
vector<vector<int>> e;
vector<int> c;
vector<int> d;
vector<int> b;
vector<int> cycle;
set<int> st;

void dfs(int x, int p) {
    if (p != -1) {
        d[x] = d[p] + 1;
    }
    b.push_back(x);
    c[x] = 1;
    bool ok = true;
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        if (c[y]) {
            if (c[y] == 2) {
                continue;
            }
            if (d[x] - d[y] + 1 <= k && cycle.size() == 0) {
                cycle.assign(b.begin() + d[y], b.end());
            }
        } else {
            dfs(y, x);
            ok &= !st.count(y);
        }
    }
    if (ok && d[x] < k) {
        st.insert(x);
    }
    c[x] = 2;
    b.pop_back();
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    while (cin >> n >> m >> k) {
        e = vector<vector<int>>(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cycle.clear();
        st.clear();
        d = vector<int>(n, 0);
        c = vector<int>(n, 0);
        dfs(0, -1);

        if (cycle.size()) {
            cout << 2 << "\n";
            cout << cycle.size() << "\n";
            for (int i = 0; i < (int)cycle.size(); ++i) {
                if (i) {
                    cout << " ";
                }
                cout << cycle[i] + 1;
            }
            cout << "\n";
        } else {
            cout << 1 << "\n";
            vector<int> a(all(st));
            for (int i = 0; i < (k + 1) / 2; ++i) {
                if (i) {
                    cout << " ";
                }
                cout << a[i] + 1;
            }
            cout << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}