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

    int n, k;
    string s;
    while (cin >> n >> k >> s) {
        int a[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = a[i - 1] + ('1' - s[i - 1]);
        }
        int l = 1, r = n;
        while (l < r) {
            int c = (l + r) / 2;
            bool ok = false;
            for (int i = 1; i <= n; ++i) {
                if (s[i - 1] == '0') {
                    int x = max(1, i - c);
                    int y = min(n, i + c);
                    if (a[y] - a[x - 1] >= k + 1) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) {
                r = c;
            } else {
                l = c + 1;
            }
        }
        cout << l << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}