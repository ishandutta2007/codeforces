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

const int MOD = (int)1e+9 + 7;

const int MAXN = 1042;
int g[MAXN][2][MAXN];
int f[MAXN];
int c[MAXN];

void addmod(int& x, const int d) {
    x += d;
    if (x >= MOD) {
        x -= MOD;
    }
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    // assert(freopen("out", "w", stdout));
    #endif
    string s;
    int k;

    f[1] = 0;
    c[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        c[i] = c[i >> 1] + (i & 1);
        f[i] = f[c[i]] + 1;
    }

    while (cin >> s >> k) {
        if (k == 0) {
            cout << 1 << endl;
            continue;
        }

        int n = s.size();
        int a[n];
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - '0';
        }

        memset(g, 0, sizeof(g));
        g[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int t = 0; t < 2; ++t) {
                for (int j = 0; j <= i; ++j) {
                    for (int x = 0; x <= (t == 0? a[i] : 1); ++x) {
                        addmod(g[i + 1][(t || x < a[i])? 1 : 0][j + x], g[i][t][j]);
                    }
                }
            }
        }

        int answer = 0;
        for (int i = 1; i < MAXN; ++i) {
            if (f[i] == k - 1) {
                addmod(answer, g[n][0][i]);
                addmod(answer, g[n][1][i]);
            }
        }
        if (k == 1) {
            addmod(answer, MOD - 1);
        }
        cout << answer << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}