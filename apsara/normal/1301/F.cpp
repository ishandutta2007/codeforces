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
const int N = 41;
int d[N][V * V];
int n, m;
int idx[V][V];
vector<int> pos[N];
vector<int> nxt[V * V];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int Q[2][V * V], top[2], tail[2], c[V * V];

void bfs(int id) {
    int cur = 0, pre = 0, v;
    d[id][n * m + id] = 0;
    top[0] = tail[0] = 0;
    Q[cur][tail[cur]++] = n * m + id;
    for (int dis = 0; ; ++dis) {
        if (tail[cur] == 0) break;
        pre = cur;
        cur = 1 - pre;
        top[cur] = tail[cur] = 0;
        while (top[pre] != tail[pre]) {
            int u = Q[pre][top[pre]++];
            if (d[id][u] != dis) continue;
            //printf("D %d %d %d\n", id, u, d[id][u]);
            if (u >= n * m) {
                int col = u - n * m;
                for (int i = 0; i < pos[col].size(); ++i) {
                    v = pos[col][i];
                    if (d[id][v] == -1 || d[id][v] > d[id][u]) {
                        d[id][v] = d[id][u];
                        Q[pre][tail[pre]++] = v;
                    }
                }
            } else {
                for (int i = 0; i < nxt[u].size(); ++i) {
                    v = nxt[u][i];
                    if (d[id][v] == -1 || d[id][v] > d[id][u] + 1) {
                        d[id][v] = d[id][u] + 1;
                        Q[cur][tail[cur]++] = v;
                    }
                }
                v = c[u] + n * m;
                if (d[id][v] == -1 || d[id][v] > d[id][u] + 1) {
                    d[id][v] = d[id][u] + 1;
                    Q[cur][tail[cur]++] = v;
                }
            }
        }
    }
}

int K, QY, sx, sy, ex, ey, a[V][V];
int main() {
    while (~scanf("%d%d%d", &n, &m, &K)) {
        for (int i = 0; i < K; ++i) pos[i].clear();
        memset(d, -1, sizeof(d));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                idx[i][j] = i * m + j;
                scanf("%d", &a[i][j]);
                --a[i][j];
                c[idx[i][j]] = a[i][j];
                pos[a[i][j]].PB(idx[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = idx[i][j];
                nxt[u].clear();
                for (int k = 0; k < 4; ++k) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (tx < 0 || tx >= n) continue;
                    if (ty < 0 || ty >= m) continue;
                    nxt[u].PB(idx[tx][ty]);
                }
            }
        }
        for (int i = 0; i < K; ++i) bfs(i);
        scanf("%d", &QY);
        while (QY--) {
            scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
            --sx;--sy;--ex;--ey;
            int ans = abs(sx - ex) + abs(sy - ey);
            for (int i = 0; i < K; ++i) {
                ans = min(ans, d[i][idx[sx][sy]] + d[i][idx[ex][ey]] + 1);
                //printf("DD %d %d %d\n", i, d[i][idx[sx][sy]], d[i][idx[ex][ey]]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

/*
3 4 5
1 2 1 3
4 4 5 5
1 2 1 3
2
1 1 3 4
2 2 2 2

4 4 8
1 2 2 8
1 3 4 7
5 1 7 6
2 3 8 8
4
1 1 2 2
1 1 3 4
1 1 2 4
1 1 4 4

*/