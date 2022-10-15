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

ll dfs(int m, int n, int *a, ll &ans)
{
    if (n == 0) {
        return a[m];
    }

    ll x = dfs(2 * m + 0, n - 1, a, ans);
    ll y = dfs(2 * m + 1, n - 1, a, ans);

    ans += max(x, y) - min(x, y);
    return max(x, y) + a[m];
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    int k = (1 << (n + 1));
    int a[k];
    for (int i = 2; i < k; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    dfs(1, n, a, ans);
    cout << ans << endl;
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}