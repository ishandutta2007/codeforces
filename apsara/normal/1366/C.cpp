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

const int V = 35;
int a[V][V], f[V * V];
int fd(int x) {
    if (f[x] != x) f[x] = fd(f[x]);
    return f[x];
}

void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px != py) f[py] = px;
}
int _, n, m, cnt[V * V][2];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &a[i][j]);
        for (int i = 0; i < n * m; ++i) f[i] = i, cnt[i][0] = 0, cnt[i][1] = 0;
        for (int x1 = 0; x1 < n; ++x1)
            for (int y1 = 0; y1 < m; ++y1)
                for (int x2 = x1; x2 < n; ++x2)
                    for (int y2 = y1; y2 < m; ++y2)
                        if (x1 + y1 + x2 + y2 == n + m - 2)
                            U(x1 * m + y1, x2 * m + y2);
        for (int i = 0; i < n * m; ++i) cnt[fd(i)][a[i / m][i % m]]++;
        int ans = 0;
        for (int i = 0; i < n * m; ++i) {
            ans += min(cnt[i][0], cnt[i][1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
2 2
1 1
0 1
2 3
1 1 0
1 0 0
3 7
1 0 1 1 1 1 1
0 0 0 0 0 0 0
1 1 1 1 1 0 1
3 5
1 0 1 0 0
1 1 1 1 0
0 0 1 0 0
*/