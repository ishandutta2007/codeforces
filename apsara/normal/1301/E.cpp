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
const int V = 510;
const int QN = 300100;
char mp[V][V];
int id(char c) {
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    if (c == 'Y') return 2;
    else return 3;
}
int s[V][V][4];
int ts[V][V];

int cal(int sx, int sy, int ex, int ey, int c) {
    if (sx > ex) return 0;
    if (sy > ey) return 0;
    return s[ex][ey][c] - s[ex][sy][c] - s[sx][ey][c] + s[sx][sy][c];
}

int cal2(int sx, int sy, int ex, int ey) {
    //printf("C2 %d %d %d %d\n", sx, sy, ex, ey);
    if (sx > ex) return 0;
    if (sy > ey) return 0;
    return ts[ex][ey] - ts[ex][sy] - ts[sx][ey] + ts[sx][sy];
}

int ans[QN];
int sx[QN], sy[QN], ex[QN], ey[QN];

/*
01
23
*/
int n, m, Q;
int main() {
    while (~scanf("%d%d%d", &n, &m, &Q)) {
        for (int i = 0; i < n; ++i) scanf("%s", mp[i]);
        for (int i = 0; i < Q; ++i) {
            scanf("%d%d%d%d", &sx[i], &sy[i], &ex[i], &ey[i]);
        }
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < 4; ++k)
                    s[i + 1][j + 1][k] = s[i + 1][j][k];
                s[i + 1][j + 1][id(mp[i][j])]++;
            }
            for (int j = 1; j <= m; ++j)
                for (int k = 0; k < 4; ++k)
                    s[i + 1][j][k] += s[i][j][k];
        }
        int L = min(n, m) / 2;
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= L; ++i) {
            memset(ts, 0, sizeof(ts));
            for (int x = i; x <= n - i; ++x) {
                for (int y = i; y <= m - i; ++y) {
                    ts[x][y] = 1;
                    if (cal(x - i, y - i, x, y, 0) != i * i) ts[x][y] = 0;
                    if (cal(x - i, y, x, y + i, 1) != i * i) ts[x][y] = 0;
                    if (cal(x, y - i, x + i, y, 2) != i * i) ts[x][y] = 0;
                    if (cal(x, y, x + i, y + i, 3) != i * i) ts[x][y] = 0;
                    //if (ts[x][y] != 0) printf("TS %d %d\n", x, y);
                }
            }
            for (int x = 1; x <= n; ++x) {
                for (int y = 1; y <= m; ++y) ts[x][y] += ts[x][y - 1];
                for (int y = 1; y <= m; ++y) ts[x][y] += ts[x - 1][y];
            }
            //printf("L %d\n", i);
            //for (int x = 0; x <= n; ++x, puts(""))for(int y = 0; y <= m; ++y) printf("%d ", ts[x][y]);
            for (int j = 0; j < Q; ++j) {
                if (cal2(sx[j] - 2 + i, sy[j] - 2 + i, ex[j] + 0 - i, ey[j] + 0 - i) != 0) ans[j] = i * i;
            }
        }
        for (int i = 0; i < Q; ++i) printf("%d\n", 4 * ans[i]);
    }
    return 0;
}

/*
5 5 5
RRGGB
RRGGY
YYBBG
YYBBR
RBBRG
1 1 5 5
2 2 5 5
2 2 3 3
1 1 3 5
4 4 5 5
6 10 5
RRRGGGRRGG
RRRGGGRRGG
RRRGGGYYBB
YYYBBBYYBB
YYYBBBRGRG
YYYBBBYBYB
1 1 6 10
1 3 3 10
2 2 6 6
1 7 6 10
2 1 5 10
8 8 8
RRRRGGGG
RRRRGGGG
RRRRGGGG
RRRRGGGG
YYYYBBBB
YYYYBBBB
YYYYBBBB
YYYYBBBB
1 1 8 8
5 2 5 7
3 1 8 6
2 3 5 8
1 2 6 8
2 1 5 5
2 1 7 7
6 5 7 5

*/