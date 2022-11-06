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
const int V = 300100;

int rt[V], cnt[V][2], inv[V];
int f(int x) {
    if (rt[x] != x) rt[x] = f(rt[x]);
    return rt[x];
}

void U(int x, int y) {
    int px = f(x);
    int py = f(y);
    rt[py] = px;
    cnt[px][0] += cnt[py][0];
    cnt[px][1] += cnt[py][1];
    inv[px] = max(inv[py], inv[px]);
}

int A(int x) {
    int px = f(x);
    if (inv[px] != -1) return cnt[px][inv[px] ^ 1];
    else return min(cnt[px][0], cnt[px][1]);
}

vector<PII> g[V];
vector<int> gg[V];
int vis[V];
void dfs(int u, int v) {
    vis[u] = v;
    for (int i = 0; i < g[u].size(); ++i) {
        PII p = g[u][i];
        if (vis[p.fi] == -1) {
            //printf("DFS %d %d %d %d\n", u, v, p.fi, p.se);
            dfs(p.fi, v ^ p.se);
        }
    }
}

char s[V];
int n, m, x, y;

int main() {
    while (~scanf("%d%d", &m, &n)) {
        scanf("%s", s);
        for (int i = 1; i <= n; ++i) {
            rt[i] = i;
            cnt[i][0] = cnt[i][1] = 0;
            inv[i] = -1;
            g[i].clear();
        }
        for (int i = 1; i <= m; ++i) gg[i].clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            for (int j = 0; j < x; ++j) {
                scanf("%d", &y);
                gg[y].PB(i);
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (gg[i].size() == 0) continue;
            if (gg[i].size() == 2) {
                x = gg[i][0];
                y = gg[i][1];
                int co = '1' - s[i - 1];
                //printf("ADD %d %d %d\n", x, y, co);
                g[x].PB(MP(y, co));
                g[y].PB(MP(x, co));
            }
        }
        memset(vis, -1, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == -1) dfs(i, 0);
        }
        //for (int i = 1; i <= n; ++i) printf("%d ", vis[i]); puts("");
        for (int i = 1; i <= n; ++i) cnt[i][vis[i]]++;
        int cur = 0;
        for (int i = 1; i <= m; ++i) {
            if (gg[i].size() == 2) {
                x = gg[i][0];
                y = gg[i][1];
                if (f(x) != f(y)) {
                    cur -= A(x);
                    cur -= A(y);
                    U(x, y);
                    cur += A(x);
                }
            } else if (gg[i].size() == 1) {
                int co = '1' - s[i - 1];
                x = gg[i][0];
                cur -= A(x);
                inv[f(x)] = vis[x] ^ co;
                cur += A(x);
            }
            printf("%d\n", cur);
        }
    }
    return 0;
}

/*
7 3
0011100
3
1 4 6
3
3 4 7
2
2 3

8 6
00110011
3
1 3 8
5
1 2 5 6 7
2
6 8
2
3 5
2
4 7
1
2

5 3
00011
3
1 2 3
1
4
3
3 4 5

19 5
1001001001100000110
2
2 3
2
5 6
2
8 9
5
12 13 14 15 16
1
19

*/