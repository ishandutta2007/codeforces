#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
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

const int MAXN = 1003;

int n, m;
int a[MAXN][MAXN];
int fa[MAXN][MAXN];
int fb[MAXN][MAXN];
int sa[MAXN][MAXN];
int sb[MAXN][MAXN];

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fa[i][j] = max(fa[i - 1][j], fa[i][j - 1]) + a[i][j];
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            fb[i][j] = max(fb[i + 1][j], fb[i][j + 1]) + a[i][j];
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            sa[i][j] = max(sa[i + 1][j], sa[i][j - 1]) + a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j)
            sb[i][j] = max(sb[i - 1][j], sb[i][j + 1]) + a[i][j];
    int ans = 0;
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < m; ++j) {
            ans = max(ans, fa[i][j - 1] + fb[i][j + 1] + sa[i + 1][j] + sb[i - 1][j]);
            ans = max(ans, fa[i - 1][j] + fb[i + 1][j] + sa[i][j - 1] + sb[i][j + 1]);
        }
    cout << ans << endl;
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}