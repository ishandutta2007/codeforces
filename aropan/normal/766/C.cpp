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

const int MOD = 1e+9 + 7;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
#endif
    int n;
    string s;
    while (cin >> n >> s) {
        vector <int> a(n);
        vector <int> d(26);
        for (int i = 0; i < 26; ++i) {
            cin >> d[i];
        }
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - 'a';
        }

        vector <int> f1(n + 1, 0);
        vector <int> f2(n + 1, 0);
        vector <int> f3(n + 1, n + 1);

        f1[0] = 1;
        f2[0] = 0;
        f3[0] = 0;
        for (int i = 0; i < n; ++i) {
            int x = n;
            for (int j = i; j < n; ++j) {
                x = min(x, i + d[a[j]]);
                if (j >= x) {
                    break;
                }
                (f1[j + 1] += f1[i]) %= MOD;
                f2[j + 1] = max(f2[j + 1], max(f2[i], j - i + 1));
                f3[j + 1] = min(f3[j + 1], f3[i] + 1);
            }
        }
        cout << f1[n] << endl;
        cout << f2[n] << endl;
        cout << f3[n] << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}