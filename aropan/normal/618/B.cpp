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
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n) {
        int a[n][n];
        int f[n];
        for (int i = 0; i < n; ++i) {
            f[i] = 0;
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                f[i] = max(f[i], a[i][j]);
            }
        }
        int ans[n];

        for (int i = 0; i < n; ++i) {
            if (f[i] == n - 1) {
                f[i] = n;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = f[i];
        }
        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
    }


    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}