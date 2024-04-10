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

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int m = 0;
        while (m < n && s[m] == s[n - m - 1]) {
            ++m;
        }
        if (m == n) {
            cout << s << "\n";
            continue;
        }

        int ans = 2 * m;
        int A, B, D;
        A = 0; B = -1;
        D = m;
        for (int iter = 0; iter < 2; ++iter) {
            vector<int> f(n);
            int l = 0, r = -1;
            for (int i = 0; i < n; ++i) {
                int x = i > r? 0 : min(f[r - i + l + iter], r - i + 1);
                while (i + x < n && i - x - iter >= 0 && s[i - x - iter] == s[i + x]) {
                    ++x;
                }
                f[i] = x;
                int a = i - x + 1 - iter;
                int b = i + x - 1;
                if (chmax(r, b)) {
                    l = a;
                }
                if (a <= b) {
                    int d = min(a, n - b - 1);
                    if (d <= m && chmax(ans, d * 2 + b - a + 1)) {
                        A = a;
                        B = b;
                        D = d;
                    }
                    // cout << a << " " << b << endl;
                }
            }
        }
        cout << s.substr(0, D) + s.substr(A, B - A + 1) + s.substr(n - D, D) << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}