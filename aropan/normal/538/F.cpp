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
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int ans[n];
    memset(ans, 0, sizeof(ans));

    for (int i = 1; i < n; ++i) {
        int k = n - 1;
        while (k) {
            int g = (i - 1) / k;
            int _k = (i - 1) / (g + 1);
            if (a[g] > a[i]) {
                ans[_k + 1] += 1;
                ans[k + 1] -= 1;
            }
            k = _k;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (i > 1) {
            printf(" ");
        }
        ans[i] += ans[i - 1];
        printf("%d", ans[i]);
    }
    printf("\n");
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}