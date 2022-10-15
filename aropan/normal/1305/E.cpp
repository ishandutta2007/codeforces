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
    // for (;;) {
        // n = rand() % 100 + 1;
        // m = rand() % (n * n);

        const int delta = 1e+4 + 42;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = 1e9 - delta * n + delta * i;
        }
        int v = m;
        for (int i = 0; i < n; ++i) {
            int x = i / 2;
            if (v >= x) {
                v -= x;
                a[i] = i + 1;
            } else {
                a[i] = a[i - 1] + a[i - v - v];
                v = 0;
                break;
            }
        }
        // dbg(v);
        if (v) {
            cout << -1 << "\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << " ";
            }
            cout << a[i];
        }
        cout << "\n";

#ifdef LOCAL
        if (n < 100) {
            int res = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        if (a[i] + a[j] == a[k]) {
                            ++res;
                        }
                    }
                }
            }
            assert(res == m);
        }
#endif
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}