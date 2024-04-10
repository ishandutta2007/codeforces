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

const int V = 1000100;
int w[V];
char s[V], mp[V];
int nxt[V], d[V], Q[V], mx[V], dg[V], inq[V];
vector<int> g[V];

void dfs(int u, int cur, int mod) {
    d[u] = cur;
    mx[d[u]] = max(mx[d[u]], w[u]);
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (d[v] != -1) continue;
        dfs(v, (d[u] + 1) % mod, mod);
    }
}
int n, m, _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; j < m; ++j)
                w[i * m + j] = 1 - (s[j] - '0');
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; j < m; ++j)
                mp[i * m + j] = s[j];
        }
        for (int i = 0; i < n * m; ++i) g[i].clear(), dg[i] = 0, inq[i] = 0, d[i] = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = i * m + j;
                int v = u;
                if (mp[u] == 'L') --v;
                else if (mp[u] == 'R') ++v;
                else if (mp[u] == 'U') v -= m;
                else if (mp[u] == 'D') v += m;
                nxt[u] = v;
                dg[v]++;
                g[v].PB(u);
            }
        }
        int top = 0, tail = 0;
        for (int i = 0; i < n * m; ++i) {
            if (dg[i] == 0) inq[i] = 1, Q[++tail] = i;
        }
        while (top != tail) {
            int u = Q[++top];
            int v = nxt[u];
            --dg[v];
            if (dg[v] == 0) {
                inq[v] = 1;
                Q[++tail] = v;
            }
        }
        int ans = 0, res = 0;
        for (int i = 0; i < n * m; ++i) {
            if (inq[i]) continue;
            if (d[i] != -1) continue;
            int u = i;
            int cnt = 0;
            while (true) {
                ++cnt;
                u = nxt[u];
                if (u == i) break;
            }
            res += cnt;
            for (int j = 0; j < cnt; ++j) mx[j] = 0;
            dfs(u, 0, cnt);
            for (int j = 0; j < cnt; ++j) ans += mx[j];
        }
        printf("%d %d\n", res, ans);
    }
    return 0;
}

/*
3
1 2
01
RL
3 3
001
101
110
RLL
DLD
ULL
3 3
000
000
000
RRD
RLD
ULL
*/