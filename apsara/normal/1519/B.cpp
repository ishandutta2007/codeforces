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
const int oo = 1e9;
const int V = 110;
int _, n, m, c;
int mi[V][V], mx[V][V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &m, &c);
        mi[1][1] = mx[1][1] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i + j == 2) continue;
                mi[i][j] = oo, mx[i][j] = -oo;
                if (i != 1) mi[i][j] = min(mi[i][j], mi[i - 1][j] + j), mx[i][j] = max(mx[i][j], mx[i - 1][j] + j);
                if (j != 1) mi[i][j] = min(mi[i][j], mi[i][j - 1] + i), mx[i][j] = max(mx[i][j], mx[i][j - 1] + i);
            }
        }
        //printf("%d %d\n", mi[n][m], mx[n][m]);
        if (mi[n][m] <= c && c <= mx[n][m]) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
6
1 1 0
2 2 2
2 2 3
2 2 4
1 4 3
100 100 10000
*/