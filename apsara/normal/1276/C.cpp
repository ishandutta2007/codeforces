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

const int V = 400100;

int a[V], b[V], v[V], d[V];
bool cmpd(int x, int y) {
    return b[x] > b[y];
}
int ans[V];
int id(int x, int y, int c) {
    return x * c + y;
}
int n;
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || a[i] != a[i - 1]) {
                m++;
                v[m] = a[i];
                b[m] = 1;
            } else {
                b[m]++;
            }
        }
        //for (int i = 1; i <= m; ++i) printf("%d ", b[i]);puts("");
        int mx = 0, mr = -1, mc = -1;
        for (int r = 1; r * r <= n; r++) {
            int total = 0;
            for (int i = 1; i <= m; ++i) {
                total += min(b[i], r);
            }
            int c = total / r;
            //printf("T %d %d %d\n", r, total, c);
            if (c < r) continue;
            if (mx < r * c) {
                mx = r * c;
                mr = r;
                mc = c;
            }
        }
        for (int i = 0; i < mx; ++i) ans[i] = -1;
        printf("%d\n", mx);
        printf("%d %d\n", mr, mc);
        int x = 0, y = 0;
        for (int i = 1; i <= m; ++i) d[i] = i;
        sort(d + 1, d + m + 1, cmpd);
        for (int k = 1; k <= m; ++k) {
            int i = d[k];
            int use = min(b[i], mr);
            use = min(use, mx);
            mx -= use;
            for (int j = 0; j < use; ++j) {
                while (ans[id(x, y, mc)] != -1) y = (y + 1) % mc;
                ans[id(x, y, mc)] = v[i];
                x = (x + 1) % mr;
                y = (y + 1) % mc;
            }
        }
        for (int i = 0; i < mr; ++i, puts("")) {
            for (int j = 0; j < mc; ++j) {
                printf("%d ", ans[id(i, j, mc)]);
            }
        }
    }
    return 0;
}

/*
12
3 1 4 1 5 9 2 6 5 3 5 8
5
1 1 1 1 1
8
1 2 3 4 1 2 3 4
4
1 2 2 3
11
3 3 3 3 2 2 1 1 1 1 4
8
1 2 3 4 5 6 1 5
*/