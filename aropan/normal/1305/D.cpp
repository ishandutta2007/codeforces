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
vector<int> f;
vector<int> d;

int dfs(int x, int p, int deep) {
    d[x] = deep;
    int ret = x;
    for (auto& y : e[x]) {
        if (y == p || f[y]) {
            continue;
        }
        int v = dfs(y, x, deep + 1);
        if (d[v] > d[ret]) {
            ret = v;
        }
    }
    return ret;
}

int get(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    cout.flush();

    int ret;
    cin >> ret;

    return ret - 1;
}

void answer(int x) {
    cout << "! " << x + 1 << endl;
    cout.flush();
    exit(0);
}

int main(int /* argc */, char** /* argv */)
{
    srand(time(NULL));
    int n;
    cin >> n;
    e.resize(n);
    f.resize(n);
    d.resize(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int fs = 0;
    for (;;) {
        int sc = dfs(fs, -1, 0);
        fs = dfs(sc, -1, 0);
        if (fs == sc) {
            answer(fs);
        }

        int result = get(fs, sc);
        if (result == fs || result == sc) {
            answer(result == fs? fs : sc);
        }
        if (result == -1) {
            return 0;
        }
        queue<int> q;
        q.push(fs);
        q.push(sc);
        f[fs] = f[sc] = true;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto& y : e[x]) {
                if (!f[y] && y != result) {
                    f[y] = true;
                    q.push(y);
                }
            }
        }
        fs = result;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}