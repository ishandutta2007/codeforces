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
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

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
    int l[n], r[n];
    double c[n];
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        c[i] = (r[i] - l[i] + 1);
    }

    ld ans = 0;
    for (int x = 1; x < 1e+4 + 2; ++x) {
        ld f[n + 1][2][3];
        memset(f, 0, sizeof(f));
        f[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (f[i][j][k] > 0) {
                        if (r[i] > x && j == 0) {
                            f[i + 1][j + 1][k] += f[i][j][k] * min(1., (r[i] - x) / c[i]);
                        }
                        if (l[i] <= x && x <= r[i]) {
                            f[i + 1][j][min(2, k + 1)] += f[i][j][k] * 1 / c[i];
                        }
                        if (l[i] < x) {
                            f[i + 1][j][k] += f[i][j][k] * min(1., (x - l[i]) / c[i]);
                        }
                    }
                }
            }
            ld p = f[n][1][1] + f[n][1][2] + f[n][0][2];
            ans += p * x;
        }
    }
    cout.precision(10);
    cout << fixed << ans << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}