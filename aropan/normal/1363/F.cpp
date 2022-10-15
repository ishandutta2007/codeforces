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
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        auto get_prefs = [&](string s) {
            auto ret = vector<vector<int>>(n + 1, vector<int>(26, 0));
            for (int i = 0; i < n; ++i) {
                ++ret[i][s[i] - 'a'];
                ret[i + 1] = ret[i];
            }
            return ret;
        };

        auto a = get_prefs(s);
        auto b = get_prefs(t);


        {
            string a = s;
            string b = t;
            sort(all(a));
            sort(all(b));
            if (a != b) {
                cout << "-1" << endl;
                continue;
            }
        }


        auto f = vector<vector<int>> (n + 1, vector<int>(n + 1, -1));
        f[0][0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (f[i][j] == -1) {
                    continue;
                }
                if (i < n) {
                    chmax(f[i + 1][j], f[i][j]);
                }
                if (j < n) {
                    chmax(f[i][j + 1], f[i][j]);
                }
                if (i < n && j < n && s[i] == t[j]) {
                    bool ok = true;
                    for (int x = 0; x < 26; ++x) {
                        ok &= a[i][x] <= b[j][x];
                    }
                    if (ok) {
                        chmax(f[i + 1][j + 1], f[i][j] + 1);
                    }
                }
            }
        }

        cout << n - f[n][n] << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}