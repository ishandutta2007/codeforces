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
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 200100;
struct Edge{
    int u, v, w;
}e[V];

bool cmp(Edge x, Edge y) {return x.w < y.w;}

int f[V];
int fd(int x) {
    if (x != f[x]) f[x] = fd(f[x]);
    return f[x];
}

void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    f[px] = py;
}
int _, n, m, K;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        }
        sort(e, e + m, cmp);
        for (int i = 1; i <= n; ++i) f[i] = i;
        LL ans = 0;
        int mx = 0;
        for (int i = 0; i < m; ++i) {
            if (fd(e[i].u) == fd(e[i].v)) continue;
            ans += max(0, e[i].w - K);
            mx = max(mx, e[i].w);
            U(e[i].u, e[i].v);
        }
        if (mx < K) {
            ans = 1e9 + 10;
            for (int i = 0; i < m; ++i) ans = min(ans, (LL) abs(e[i].w - K));
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
4
4 5 7
4 1 3
1 2 5
2 3 8
2 4 1
3 4 4
4 6 5
1 2 1
1 3 1
1 4 2
2 4 1
4 3 1
3 2 1
3 2 10
1 2 8
1 3 10
5 5 15
1 2 17
3 1 15
2 3 10
1 4 14
2 5 8

*/