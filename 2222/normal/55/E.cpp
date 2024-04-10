#define __USE_MINGW_ANSI_STDIO    1

#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(), (a).end()

typedef long long int64;
typedef pair<int, int> point;

int X[100500], Y[100500];

inline int64 det(int a, int b, int c, int d) { return (int64)a * d - (int64)b * c; }

int main(){
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    freopen("x.out", "w", stdout);
    #endif
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d%d", X + i, Y + i);
    for (cin >> m; m --> 0; ) {
        int64 res = (int64)n * (n - 1) * (n - 2) / 6;
        int x, y, j = 1;
        scanf("%d%d", &x, &y);
        for (int i = 0; i < n; ++i) X[i] -= x, Y[i] -= y;
        for (int i = 0; i < n; ++i) {
            for (; i != j && det(X[i], Y[i], X[j], Y[j]) < 0; )
                if (++j == n) j = 0;
            if (i == j) {
                res = 0;
                break;
            }
            int k = j - i;
            if (k < 0) k += n;
            res -= (int64)(k - 1) * (k - 2) / 2;
        }
        for (int i = 0; i < n; ++i) X[i] += x, Y[i] += y;
        printf("%lld\n", res);
    }
    return 0;
}