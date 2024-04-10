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
const int P = 1000000007;
const int V = 100100;
const int N = 5000;

map<LL, int> mp;

LL s[20];
int pos[20], a[20][N + 10], n, cnt[20];
int Q[V], deg[V], vis[V], node[V], g[V];
int dp[1<<20], mask[1<<20], pre[1<<20];
vector<int> clc[V];
int ans[20], to[20];

int main() {
    while (~scanf("%d", &n)) {
        mp.clear();
        pos[0] = 0;
        LL total = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &cnt[i]);
            s[i] = 0;
            for (int j = 0; j < cnt[i]; ++j) {
                scanf("%d", &a[i][j]);
                mp[a[i][j]] = i * N + j;
                s[i] += a[i][j];
                node[pos[i] + j] = i;
            }
            total += s[i];
            pos[i + 1] = pos[i] + cnt[i];
        }
        if (total % n != 0) {
            puts("No");
            continue;
        }
        memset(g, -1, sizeof(g));
        memset(deg, 0, sizeof(deg));
        LL avg = total / n;
        for (int i = 0; i < n; ++i) {
            LL diff = s[i] - avg;
            for (int j = 0; j < cnt[i]; ++j) {
                LL need = a[i][j] - diff;
                if (mp.find(need) != mp.end()) {
                    int id = mp[need];
                    int u = id / N;
                    int v = id % N;
                    g[pos[i] + j] = pos[u] + v;
                    deg[pos[u] + v]++;
                    //printf("G %d %d %d %d\n", i, a[i][j], u, a[u][v]);
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        int top = 0, tail = 0;
        for (int i = 0; i < pos[n]; ++i) {
            if (!deg[i]) {
                Q[++tail] = i;
            }
        }
        while (top != tail) {
            int u = Q[++top];
            vis[u] = 1;
            //printf("topo %d\n", u);
            int v = g[u];
            if (v == -1) continue;
            deg[v]--;
            if (!deg[v]) {
                Q[++tail] = v;
            }
        }
        memset(mask, -1, sizeof(mask));
        for (int i = 0; i < pos[n]; ++i) {
            clc[i].clear();
            if (vis[i]) continue;
            int u = i;
            while (!vis[u]) {
                clc[i].push_back(u);
                vis[u] = 1;
                u = g[u];
            }
            bool ok = true;
            int s = 0;
            for (int j = 0; j < clc[i].size(); ++j) {
                int id = clc[i][j];
                int u = node[id];
                if (s & (1 << u)) ok = false;
                s |= (1 << u);
            }
            //printf("%d %d\n", s, ok);
            if (ok) mask[s] = i;
        }
        memset(dp, 0, sizeof(dp));
        memset(pre, -1, sizeof(pre));
        dp[0] = 1;
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = i; j; j = (j - 1) & i) {
                if (mask[j] != -1 && dp[i ^ j]) {
                    dp[i] = 1;
                    pre[i] = j;
                }
            }
        }
        if (dp[(1 << n) - 1]) {
            int cur = (1 << n) - 1;
            while (cur != 0) {
                int u = mask[pre[cur]];
                for (int i = 0; i < clc[u].size(); ++i) {
                    int id = clc[u][i];
                    int j = node[id];
                    int v = a[j][id - pos[j]];
                    //printf("%d ", v);
                    ans[j] = v;
                    to[node[clc[u][(i + 1) % clc[u].size()]]] = j;
                }
                //puts(">>>>");
                cur ^= pre[cur];
            }
            puts("Yes");
            for (int i = 0; i < n; ++i) printf("%d %d\n", ans[i], to[i] + 1);
        } else {
            puts("No");
        }
    }
    return 0;
}

/*
4
3 1 7 4
2 3 2
2 8 5
1 10

2
2 3 -2
2 -1 5

2
2 -10 10
2 0 -20

*/