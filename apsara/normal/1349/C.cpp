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
char s[V][V];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int Q[V * V], d[V * V];
int n, m, K, x, y;
LL z;

int main() {
    while (~scanf("%d%d%d", &n, &m, &K)) {
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        int top = 0, tail = 0;
        memset(d, -1, sizeof(d));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool same = false;
                for (int k = 0; k < 4; ++k) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (tx < 0 || tx >= n) continue;
                    if (ty < 0 || ty >= m) continue;
                    if(s[i][j] == s[tx][ty]) same = true;
                }
                if (same) {
                    Q[++tail] = i * m + j;
                    d[i * m + j] = 0;
                }
            }
        }
        while (top != tail) {
            int u = Q[++top];
            int nx = u / m;
            int ny = u % m;
            for (int k = 0; k < 4; ++k) {
                int tx = nx + dx[k];
                int ty = ny + dy[k];
                if (tx < 0 || tx >= n) continue;
                if (ty < 0 || ty >= m) continue;
                int v = tx * m + ty;
                if (d[v] == -1) {
                    Q[++tail] = v;
                    d[v] = d[u] + 1;
                }
            }
        }
        //for (int i = 0; i < n; ++i, puts(""))for(int j = 0; j <m; ++j)printf("%d",d[i * m + j]);
        while (K--) {
            scanf("%d%d%I64d", &x, &y, &z);
            --x;--y;
            if (d[x * m + y] == -1 || d[x * m + y] >= z) printf("%c\n", s[x][y]);
            else {
                int rev = (z - d[x * m + y]) % 2;
                printf("%c\n", rev ^ (s[x][y] - '0') + '0');
            }
        }
    }
    return 0;
}

/*
3 3 3
000
111
000
1 1 1
2 2 2
3 3 3
5 2 2
01
10
01
10
01
1 1 4
5 1 4
5 5 3
01011
10110
01101
11010
10101
1 1 4
1 2 3
5 5 3
1 1 3
0
1 1 1
1 1 2
1 1 3
*/