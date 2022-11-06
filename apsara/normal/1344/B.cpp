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
const int V = 1010;

int L[V], R[V], D[V], U[V];
char s[V][V];
int vis[V][V];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int n, m;
void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int k = 0; k < 4; ++k) {
        int tx = x + dx[k];
        int ty = y + dy[k];
        if (tx < 0 ||tx >= n) continue;
        if (ty < 0 ||ty >= m) continue;
        if (s[tx][ty] == '.') continue;
        if (vis[tx][ty] != 0) continue;
        dfs(tx, ty);
    }
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        memset(D, -1, sizeof(D));
        memset(U, -1, sizeof(U));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '.') continue;
                if (L[i] == -1 || L[i] > j) L[i] = j;
                if (R[i] == -1 || R[i] < j) R[i] = j;
                if (U[j] == -1 || U[j] > i) U[j] = i;
                if (D[j] == -1 || D[j] < i) D[j] = i;
            }
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] != '.') continue;
                if (L[i] < j && R[i] > j) ok = false;
                if (U[j] < i && D[j] > i) ok = false;
            }
        }
        int rn = 0, cn = 0;
        for (int i = 0; i < n; ++i) if (L[i] == -1) ++rn;
        for (int i = 0; i < m; ++i) if (U[i] == -1) ++cn;
        if ((rn != 0 || cn != 0) && rn * cn == 0) ok = false;
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '.') continue;
                if (vis[i][j]) continue;
                cnt++;
                dfs(i, j);
            }
        }
        if (!ok) cnt = -1;
        printf("%d\n", cnt);
    }
    return 0;
}

/*
3 3
.#.
###
##.

4 2
##
.#
.#
##

4 5
....#
####.
.###.
.#...

2 1
.
#

3 5
.....
.....
.....
*/