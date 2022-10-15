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
    int n, m;
    scanf("%d %d", &n, &m);
    int d, h;
    scanf("%d %d", &d, &h);
    int ans = d + h - 1;
    for (int i = 1; i < m; ++i) {
        int _h = h;
        int _d = d;
        scanf("%d %d", &d, &h);
        if (abs(d - _d) < abs(h - _h)) {
            puts("IMPOSSIBLE");
            return 0;
        }
        int v = abs(d - _d) - abs(h - _h);
        ans = max(ans, max(h, _h) + v / 2);
    }
    ans = max(ans, n - d + h);
    printf("%d\n", ans);
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}