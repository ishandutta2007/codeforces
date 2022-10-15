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

int n, k, m;

void add(int &x, int d)
{
    x += d;
    if (x >= m) {
        x -= m;
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif
    cin >> n >> k >> m;
    if (m == 1) {
        cout << "0" << endl;
        return 0;
    }
    int pow10[n + 1];
    pow10[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pow10[i] = pow10[i - 1] * 10 % k;
    }

    int f[n + 1][k][2];
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1 % m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int t = 0; t < 2; ++t) {
                if (f[i][j][t] && (j > 0 || t == 0)) {
                    for (int x = i + 1 < n? 0 : 1; x < 10; ++x) {
                        add(f[i + 1][(j + x * pow10[i]) % k][t || x? 1 : 0], f[i][j][t]);
                    }
                }
            }
        }
    }
    int ans = f[n][0][1];
    ll pow = 1;
    for (int i = n - 1; i >= 1; --i) {
        add(ans, pow * f[i][0][1] * 9 % m);
        (pow *= 10) %= m;
    }
    cout << ans << endl;
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}