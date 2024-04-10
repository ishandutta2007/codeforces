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
#include "pretty_print.h"
#else
#define dbg(x)
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
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                a[i] = b[i] = '0';
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1' && i > 0 && b[i - 1] == '1') {
                ++ans;
                a[i] = b[i - 1] = '0';
            }
            if (a[i] == '1' && i + 1 < n && b[i + 1] == '1') {
                ++ans;
                a[i] = b[i + 1] = '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                ++ans;
            }
            if (b[i] == '1') {
                ++ans;
            }
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}