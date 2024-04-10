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
vector<pair<int, int>> ans;

void dfs(int x, int t, int p) {
    ans.push_back({x, t});
    vector<int> a;
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        a.push_back(y);
    }
    int k = a.size();
    int k1 = max(k + 1 - t, 0);
    for (int i = 0; i <= k; ++i) {
        if (i == k1) {
            t -= k + 1;
            ans.push_back({x, t});
        }
        if (i < k) {
            dfs(a[i], t + 1, x);
            t += 1;
            ans.push_back({x, t});
        }
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

    int n;
    while (cin >> n) {
        e.resize(n);
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

#ifdef LOCAL
        int result = -1;
        ans.clear();
        for (int iter = 0; iter < n; ++iter) {
            for (int i = 0; i < n; ++i) {
                random_shuffle(all(e[i]));
            }
            ans.clear();
            dfs(0, 0, -1);
            auto res = ans;

            set<pair<int, int>> sres(all(res));
            assert(sres.size() == res.size());

            int mres = 0;
            for (auto& p : res) {
                chmax(mres, p.second);
            }
            if (result == -1) {
                result = mres;
            }
            assert(result == mres);
        }
#endif

        ans.clear();
        dfs(0, 0, -1);
        cout << ans.size() << "\n";
        for (auto& p : ans) {
            cout << p.first + 1 << " " << p.second << "\n";
        }


#ifdef LOCAL
        set<pair<int, int>> sans(all(ans));
        assert(sans.size() == ans.size());

        int mans = 0;
        for (auto& p : ans) {
            chmax(mans, p.second);
        }
        assert(mans == result);
#endif
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}