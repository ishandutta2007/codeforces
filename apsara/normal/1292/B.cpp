#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 60;
LL ab(LL x) {if (x < 0) return -x; return x;}
LL D(LL x, LL y, LL _x, LL _y) {
    return ab(x - _x) + ab(y - _y);
}
LL x[V], y[V];
LL cost[V][V];
LL bx, by, sx, sy, t;
int ax, ay, n;

int main() {
    while (~scanf("%I64d%I64d%d%d%I64d%I64d", &x[0], &y[0], &ax, &ay, &bx, &by)) {
        scanf("%I64d%I64d%I64d", &sx, &sy, &t);
        for (int i = 1;; i++) {
            x[i] = x[i - 1] * ax + bx;
            y[i] = y[i - 1] * ay + by;
            n = i;
            if ((x[i] >= sx || y[i] >= sy) && D(x[i], y[i], sx, sy) > t) break;
        }
        //for (int i = 0; i < n; ++i) printf("P %I64d %I64d\n", x[i], y[i]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cost[i][j] = D(x[i], y[i], x[j], y[j]);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int k = j; k < n; ++k) {
                    LL td = D(sx, sy, x[i], y[i]) + cost[i][j] + cost[j][k];
                    //printf("%d %d %d %I64d\n", i, j, k, td);
                    if (td <= t) ans = max(ans, max(i, k) - j + 1);
                }
            }
            for (int j = i; j < n; ++j) {
                for (int k = j; k >= 0; --k) {
                    LL td = D(sx, sy, x[i], y[i]) + cost[i][j] + cost[j][k];
                    //printf("%d %d %d %I64d\n", i, j, k, td);
                    if (td <= t) ans = max(ans, j - min(k, i) + 1);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
1 1 2 3 1 0
2 4 20

1 1 2 3 1 0
15 27 26

1 1 2 3 1 0
2 2 1

*/