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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> void chmin(T &x, const T y) { if (x > y) { x = y; } }
template <typename T> void chmax(T &x, const T y) { if (x < y) { x = y; } }

vector < vector <int> > e;
vector <int> s;

int put(int *f, int x)
{
    if (f[x] == 0) {
        f[x] = 1;
        return x;
    }

    int r = put(f, x + f[x]);
    f[x] = r - x;
    return r;
}

int dfs(int x, int p, int *f)
{
    int res = 0;
    s[x] = 1;
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        res = max(res, dfs(y, x, f + 1) + 1);
        s[x] += s[y];
    }
    if (s[x] == 1) {
        res = put(f, 0);
    }
    return res;
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    e.resize(n);
    s.resize(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int *f;
    f = new int[n + n];
    memset(f, 0, sizeof(int) * n);

    int ans = 0;
    for (auto& x : e[0]) {
        ans = max(ans, dfs(x, 0, f) + 1);
        memset(f, 0, sizeof(int) * (s[x] + s[x] + 1));
    }
    cout << ans << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}