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

    int n;
    while (cin >> n) {
        vector<int> l(n);
        vector<int> r(n);
        vector<int> f(n, 0);
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }

        int k = n;
        for (int v = n; v >= 1; --v) {
            for (int i = 0; i < n; ++i) {
                if (!f[i] && l[i] == 0 && r[i] == 0) {
                    a[i] = v;
                    f[i] = 1;
                    --k;
                }
            }
            for (int i = 0, c = 0; i < n; ++i) {
                l[i] -= c;
                c += a[i] == v;
            }
            for (int i = n - 1, c = 0; i >= 0; --i) {
                r[i] -= c;
                c += a[i] == v;
            }
        }
        if (k) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                if (i) {
                    cout << " ";
                }
                cout << a[i];
            }
            cout << endl;
        }
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}