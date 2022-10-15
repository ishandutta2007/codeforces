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
#include <cstdlib>
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

const int MAXN = 400000 + 42;
const int MAXM = 20;
const ll INF = 1e+18 + 42;

ll s[MAXN][MAXM];
int t[MAXN][MAXM];
ll w[MAXN];


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int q;
    bool first = true;

    while (cin >> q) {
        if (!first) {
            cout << endl;
        }
        first = false;

        int n = 1;
        w[n] = 0;
        memset(t, 0, sizeof(t));
        memset(w, 0, sizeof(w));
        memset(s, 0, sizeof(s));
        ll last = 0;
        while (q--) {
            ll c, p, q;
            cin >> c >> p >> q;
            p ^= last;
            q ^= last;
            // cerr << c << " " << p << " " << q << endl;
            if (c == 1) {
                ll R = p;
                ll W = q;

                ++n;
                w[n] = W;

                int P = R;
                if (w[P] < w[n]) {
                    for (int i = MAXM - 1; i >= 0; --i) {
                        int x = t[P][i];
                        if (x && w[x] < w[n]) {
                            P = x;
                        }
                    }
                    P = t[P][0];
                }
                if (P > 0) {
                    t[n][0] = w[n] <= w[P]? P : 0;
                    s[n][0] = w[n] <= w[P]? W : INF;

                    for (int i = 1; i < MAXM; ++i) {
                        int x = t[n][i - 1];
                        if (x == 0) {
                            break;
                        }
                        t[n][i] = t[x][i - 1];
                        s[n][i] = min(s[n][i - 1] + s[x][i - 1], INF);
                    }
                }
            } else {
                ll R = p;
                ll X = q;

                int ret = 0;
                for (int i = MAXM - 1; i >= 0; --i) {
                    if (t[R][i] && X >= s[R][i]) {
                        ret += 1 << i;
                        X -= s[R][i];
                        R = t[R][i];
                    }
                }
                if (X >= w[R]) {
                    ret += 1;
                }
                cout << ret << "\n";
                last = ret;
            }
        }
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}