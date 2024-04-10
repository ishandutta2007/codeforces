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

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int n;
vector < vector <int> > e;
vector < int > s;
vector < int > f;

void dfs_f(int x, int d)
{
    s[x] = f[x] = 0;
    if (e[x].size() == 0) {
        s[x] = 1;
        f[x] = 1;
        return;
    }

    for (auto& y : e[x]) {
        dfs_f(y, d ^ 1);
        s[x] += s[y];
    }

    if (d == 0) {
        for (auto& y : e[x]) {
            f[x] = max(f[x], s[x] - (s[y] - f[y]));
        }
    } else {
        for (auto& y : e[x]) {
            f[x] += s[y] - (s[y] - f[y]) - 1;
        }
        f[x] += 1;
    }
}

void dfs_s(int x, int d)
{
    s[x] = f[x] = 0;
    if (e[x].size() == 0) {
        s[x] = 1;
        f[x] = 1;
        return;
    }

    for (auto& y : e[x]) {
        dfs_s(y, d ^ 1);
        s[x] += s[y];
    }

    if (d == 0) {
        for (auto& y : e[x]) {
            f[x] += f[y];
        }
    } else {
        f[x] = s[x];
        for (auto& y : e[x]) {
            f[x] = min(f[x], f[y]);
        }
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    while (scanf("%d", &n) == 1) {
        e.resize(n + 1);
        f.resize(n + 1);
        s.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            e[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            e[x].push_back(y);
        }
        dfs_f(1, 0);
        cout << f[1] << " ";

        dfs_s(1, 0);
        cout << f[1] << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}