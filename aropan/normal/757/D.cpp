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
#include <iomanip>

using namespace std;

#define fst first
#define snd second

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }


const int MAXX = 20;
const int MAXM = 1 << MAXX;
const int MAXN = 76;
const int MOD = 1e+9 + 7;

int f[MAXN][MAXM];
int l[MAXX + 1];
int p[MAXX + 1];
int a[MAXN];
int n;

void add(int &x, const int d) {
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
    assert(freopen("out", "w", stdout));
#endif

    l[1] = 1;
    for (int i = 2; i <= MAXX; ++i) {
        l[i] = l[i >> 1] + 1;
    }

    int s = 0;
    for (int i = 1; i <= MAXX; ++i) {
        s += l[i];
    }
    cerr << s << " " << l[MAXX] << endl;
    for (int i = 1; i <= MAXX; ++i) {
        p[i] = 1 << (i - 1);
    }

    while (cin >> n && n) {
        memset(f, 0, sizeof(f));
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - '0';
            // a[i] = rand() & 1;
        }
        for (int i = 0; i < n; ++i) {
            f[i][0] = 1;
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < MAXM; ++j) {
                if (f[i][j]) {
                    // cout << i << " " << j << " " << f[i][j] << endl;
                    if (j > 0 && (j & (j + 1)) == 0) {
                        add(ans, f[i][j]);
                    }
                    if (i == n) {
                        continue;
                    }
                    int x = 0;
                    for (int k = i; k < n; ++k) {
                        x = x * 2 + a[k];
                        if (x > MAXX) {
                            break;
                        }
                        if (0 < x && x <= MAXX) {
                            add(f[k + 1][j | p[x]], f[i][j]);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}