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
    int n;
    while (scanf("%d", &n) == 1) {
        vector <int> a(n);
        vector < pair <int, int> > v(n);
        for (int i = 0; i < n; ++i) {
            assert(scanf("%d", &a[i]) == 1);
            v[i] = make_pair(a[i] + i, i);
        }
        sort(v.begin(), v.end());
        bool ok = true;
        vector <int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = v[i].first - i;
            ok &= ans[i] >= 0;
        }
        for (int i = 1; i < n; ++i) {
            ok &= v[i].first != v[i - 1].first;
        }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                if (i) {
                    printf(" ");
                }
                printf("%d", ans[i]);
            }
            printf("\n");
        } else {
            puts(":(");
        }
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}