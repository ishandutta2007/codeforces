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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

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
        int a[n];
        memset(a, 0, sizeof(a));
        vector < vector < pair <int, int> > > e(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(make_pair(v, i + 1));
            ++a[v];
        }

        int x = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                x = i;
                break;
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int y = -1;
            for (auto& j : e[x]) {
                if (--a[j.first] == 0) {
                    if (y == -1) {
                        y = j.first;
                        ans = max(ans, j.second);
                    } else {
                        y = -2;
                    }
                }
            }
            if (y < 0) {
                ans = -1;
                break;
            }
            x = y;
        }
        cout << ans << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}