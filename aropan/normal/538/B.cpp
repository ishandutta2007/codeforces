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
    int n;
    cin >> n;
    int f[n + 1];
    int p[n + 1];
    memset(f, 0, sizeof(f));
    memset(p, 0, sizeof(p));
    f[0] = 1;
    for (int i = 0; ; ++i) {
        int x = 0;
        for (int j = i, d = 1; j; j >>= 1, d *= 10) {
            x += d * (j & 1);
        }
        if (x > n) {
            break;
        }

        for (int j = x; j <= n; ++j) {
            if (f[j - x] && (f[j] == 0 || f[j - x] + 1 < f[j])) {
                f[j] = f[j - x] + 1;
                p[j] = x;
            }
        }
    }
    cout << f[n] - 1 << endl;
    for (; n; n -= p[n]) {
        cout << p[n] << " ";
    }
    cout << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}