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

vector <vector<int>> e;
int ans;
int n, k;

int dfs(int x, int p) {
    if (e[x].size() == 2 || (p != -1 && e[x].size() == 3)) {
        return -1;
    }

    map<int, int> mp;
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        int r = dfs(y, x);
        ans = max(ans, r);
        if (r == -1) {
            return -1;
        }
        mp[r] += 1;
    }
    if (mp.size() > 1) {
        return -1;
    }
    if (mp.size() == 0) {
        return 0;
    }
    return mp.begin()->first + 1;
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    cin >> n >> k;
    e.resize(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    queue <int> q;
    vector<int> f(n, 0);
    for (int i = 0; i < n; ++i) {
        if (e[i].size() == 1) {
            q.push(i);
            f[i] = 1;
        }
    }

    int x = 0;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (auto& y : e[x]) {
            if (!f[y]) {
                q.push(y);
                f[y] = 1;
            }
        }
    }

    cout << (e[x].size() >= 3 && dfs(x, -1) == k? "Yes" : "No") << endl;

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}