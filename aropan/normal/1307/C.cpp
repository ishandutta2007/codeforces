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

    string s;
    while (cin >> s) {
        int n = s.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - 'a';
        }
        ll f[26][26];
        ll c[26];
        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            for (int j = 0; j < 26; ++j) {
                f[j][x] += c[j];
            }
            c[x] += 1;
        }
        ll ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = max(ans, c[i]);
            for (int j = 0; j < 26; ++j) {
                ans = max(ans, f[i][j]);
            }
        }
        cout << ans << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}