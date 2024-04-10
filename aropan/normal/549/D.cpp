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

#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__)
#define INT64 "%I64d"
#define UNS64 "%I64u"
#else
#define INT64 "%lld"
#define UNS64 "%llu"
#endif

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif
    int n, m;
    while (cin >> n >> m) {
        vector <string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector <ll> c(m, 0);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ll r = 0;
            for (int j = m - 1; j >= 0; -- j) {
                ll v = a[i][j] == 'B'? -1 : 1;
                c[j] += r;
                if (c[j] != v) {
                    ll x = v - c[j];
                    c[j] += x;
                    r += x;
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}