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

const int N = 60;
const int V = N + 10;
LL C[V][V];
LL mi[V][V], mx[V][V], a[V][V];
int n;

void dfs(int x, int y) {
    if (mi[x][y] != -1) return;
    if (x > 0) dfs(x - 1, y);
    if (y > 0) dfs(x, y - 1);
    mi[x][y] = 0;
    if (x + 1 < n && y > 0) dfs(x + 1, y - 1), mi[x][y] = mx[x + 1][y - 1] + 1;
    mx[x][y] = mi[x][y] + C[x + y][x] - 1;
    if (x > 0) a[x][y] = mx[x][y] - mx[x - 1][y];
    else a[x][y] = mi[x][y] - mi[x][y - 1];
    //printf("%d %d %I64d %I64d\n", x, y, mi[x][y], mx[x][y]);
}

LL t = 0;
void cal(int x, int y, LL K) {
    t += a[x][y];
    LL z = K - a[x][y];
    if (x != 0 || y != 0) {
        if (y > 0 && z <= mx[x][y - 1]) {
            cal(x, y - 1, z);
        } else {
            cal(x - 1, y, z);
        }
    }
    printf("%d %d\n", x + 1, y + 1);
    fflush(stdout);
}

int Q;
LL K;
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < N; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; ++j)
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
        //for (int i = 1; i <= 25; ++i) printf("%d %I64d\n", i, C[2 * i][i]);
        memset(mi, -1, sizeof(mi));
        memset(mx, -1, sizeof(mx));
        memset(a, -1, sizeof(a));
        a[0][0] = mi[0][0] = mx[0][0] = 0;
        dfs(n - 1, n - 1);
        for (int i = 0; i < n; ++i, puts(""), fflush(stdout)) {
            for (int j = 0; j < n; ++j) {
                printf("%I64d ", a[i][j]);
            }
        }
        scanf("%d", &Q);
        while (Q--) {
            scanf("%lld", &K);
            t = 0;
            cal(n - 1, n - 1, K);
            //printf("T %I64d\n", t);
        }
    }
    return 0;
}

/*

*/