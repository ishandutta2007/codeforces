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

const int V = 200100;

int s[V], c[V];

int f(int x) {
    if (s[x] != x) s[x] = f(s[x]);
    return s[x];
}

void U(int x, int y) {
    int px = f(x);
    int py = f(y);
    if (px == py) return;
    c[py] += c[px];
    s[px] = py;
}

const int M = 500100;

int cn[120];
int u[M], v[M];
int _, n, m, a, b;
int cc[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u[i], &v[i]);
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) cc[i] = 0;

        for (int i = 1; i <= n; ++i) s[i] = i, c[i] = 1;
        c[a] = c[b] = 0;
        for (int i = 0; i < m; ++i) {
            if (u[i] == a || v[i] == a) continue;
            U(u[i], v[i]);
        }
        for (int i = 1; i <= n; ++i) if(f(i) == f(b)) cc[i] |= 2;
        int pre = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] != i) continue;
            ans += (LL) pre * c[i];
            pre += c[i];
        }
        //printf("A %I64d\n", ans);

        for (int i = 1; i <= n; ++i) s[i] = i, c[i] = 1;
        c[a] = c[b] = 0;
        for (int i = 0; i < m; ++i) {
            if (u[i] == b || v[i] == b) continue;
            U(u[i], v[i]);
        }
        for (int i = 1; i <= n; ++i) if(f(i) == f(a)) cc[i] |= 1;
        pre = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] != i) continue;
            ans += (LL) pre * c[i];
            pre += c[i];
        }
        //printf("A %I64d\n", ans);

        /*
        for (int i = 1; i <= n; ++i) s[i] = i, c[i] = 1;
        c[a] = c[b] = 0;
        for (int i = 0; i < m; ++i) {
            if (u[i] == a || v[i] == a) continue;
            if (u[i] == b || v[i] == b) continue;
            U(u[i], v[i]);
        }
        pre = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] != i) continue;
            ans -= (LL) pre * c[i];
            pre += c[i];
        }
        */

        memset(cn, 0, sizeof(cn));
        for (int i = 1; i <= n; ++i) if(i != a && i != b) cn[cc[i]]++;
        //printf("CN %d %d %d %d\n", cn[0], cn[1], cn[2], cn[3]);
        printf("%I64d\n", (LL) cn[1] * cn[2]);

        for (int i = 1; i <= n; ++i) s[i] = i, c[i] = 1;
        c[a] = c[b] = 0;
        for (int i = 1; i <= n; ++i) if (cc[i] == 2) c[i] =0;
        for (int i = 0; i < m; ++i) {
            if (u[i] == a || v[i] == a) continue;
            if (u[i] == b || v[i] == b) continue;
            U(u[i], v[i]);
        }
        pre = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] != i) continue;
            ans -= (LL) pre * c[i];
            pre += c[i];
        }

        //printf("%I64d\n", ans);
    }
    return 0;
}

/*
8
7 7 3 5
1 2
2 3
3 4
4 5
5 6
6 7
7 5
4 5 2 3
1 2
2 3
3 4
4 1
4 2
4 3 2 1
1 2
2 3
4 1
4 3 1 2
1 2
2 3
3 4
7 6 1 2
1 2
1 3
1 4
2 5
2 6
2 7
7 7 1 2
1 2
1 3
1 4
2 5
2 6
2 7
4 5
7 8 1 2
1 2
1 3
1 4
2 5
2 6
2 7
4 5
3 7
*/