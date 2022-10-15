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
    int n, m;
    assert(scanf("%d %d\n", &n, &m) == 2);
    char s[n + 2];
    assert(scanf("%s", s + 1) == 1);

    int k[n + 1];
    char a[n + 2];
    k[1] = 0;
    for (int i = 2; i <= n; ++i) {
        int x = k[i - 1];
        while (x && s[x + 1] != s[i]) x = k[x];
        x += s[x + 1] == s[i];
        k[i] = x;
    }

    memset(a, '0', sizeof(a));
    a[n + 1] = '\0';
    for (int i = 1; i <= n; ++i) {
        int p = i - k[i];
        int c = i / p;
        int g = c / m;
        int l = g * p;
        if (i - m * l > l) {
            continue;
        }
        a[i] = '1';
    }
    puts(a + 1);
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}