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
#include <numeric>
#include <bitset>

using namespace std;

#define snd second
#define fst first

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

const int MAXN = 1e+6 + 7;
bitset<MAXN> g;
int p[MAXN];
int f[MAXN];
map <int, int> m;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
#endif
    int n, k;
    scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            p[i] = p[i] - 1;
            f[i] = false;
        }
        int d = 0;

        m.clear();
        for (int i = 0; i < n; ++i) {
            if (!f[i]) {
                int l = 0;
                int x = i;
                while (!f[x]) {
                    l += 1;
                    f[x] = true;
                    x = p[x];
                }
                m[l] += 1;
                d += l / 2;
            }
        }
        g.reset();
        g.set(0);
        for (auto& it : m) {
            int x = it.fst;
            int c = it.snd;
            int l = 0;
            for (int i = 30; i >= 0; --i) {
                if (l) {
                    g = g | (g << (l * x));
                }
                l *= 2;
                int b = ((1 << i) & c) >> i;
                if (b) {
                    l += 1;
                    g = g | (g << x);
                }
            }
        }
        cout << k + (g.test(k) == 0) << " ";

        d = min(k, d);
        int ans = min(d * 2 + k - d, n);
        cout << ans << endl;

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}