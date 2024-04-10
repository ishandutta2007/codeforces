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
typedef pair<LL, LL> PLL;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 200100;
LL gcd(LL x, LL y) {
    if (!x) return y;
    if (!y) return x;
    return gcd(y, x % y);
}
map<PLL, int> mp;
int n, m;

int get(int a, int b, int c, int d) {
    LL gd = gcd((LL) b * c, (LL) a * d);
    LL x = (LL) a * d / gd;
    LL y = (LL) b * c / gd;
    if (mp.find({x, y}) == mp.end()) {
        m++;
        mp[{x, y}] = m;
    }
    return mp[{x, y}];
}

int rt[2 * V], en[V];

int fd(int x) {
    if (rt[x] != x) rt[x] = fd(rt[x]);
    return rt[x];
}

void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py) return;
    rt[px] = py;
    en[py] += en[px];
}

vector<PII> g[V * 2];
PII res[V];
int vis[V * 2], ans, D[V * 2];

bool dfs(int u, int fa, int pre) {
    vis[u] = 1;
    vector<int> re;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i].fi;
        int w = g[u][i].se;
        if (vis[v]) {
            if (w != pre && D[v] < D[u]) re.PB(w);
        } else {
            D[v] =D[u] + 1;
            bool left = dfs(v, u, w);
            if (left) re.PB(w);
        }
    }
    //for (int i = 0; i < re.size(); ++i) printf("%d ", re[i]);
    //printf("  U: %d %d %d %d\n", u, re.size(), fa, pre);
    if (re.size() % 2 == 0 || pre == -1) {
        for (int i = 0; i + 1< re.size(); i += 2) {
            res[ans++] = {re[i], re[i + 1]};
        }
        return true;
    } else {
        re.PB(pre);
        for (int i = 0; i + 1< re.size(); i += 2) {
            res[ans++] = {re[i], re[i + 1]};
        }
        return false;
    }
}

int u[V], v[V];
int a, b, c, d;
int main() {
    while (~scanf("%d", &n)) {
        mp.clear();
        m = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            u[i] = get(a + b, b, c, d);
            v[i] = get(a, b, c + d, d);
        }
        for (int i = 1; i <= m; ++i) rt[i] = i, en[i] = 0, g[i].clear(), vis[i] = 0, D[i] = 0;
        for (int i = 0; i < n; ++i) {
            U(u[i], v[i]);
            en[fd(u[i])]++;
            g[u[i]].PB({v[i], i + 1});
            g[v[i]].PB({u[i], i + 1});
            //printf("%d %d\n", u[i], v[i]);
        }
        ans = 0;
        /*
        for (int i = 1; i <= m; ++i) {
            if (rt[i] == i) ans += en[i] / 2;
        }*/
        for (int i = 1; i <= m; ++i) {
            if (vis[i]) continue;
            dfs(i, -1, -1);
        }
        printf("%d\n", ans);
        for (int i = 0; i < ans; ++i) printf("%d %d\n", res[i].fi, res[i].se);
    }
    return 0;
}

/*
7
4 1 5 1
1 1 1 1
3 3 3 3
1 1 4 1
6 1 1 1
5 1 4 1
6 1 1 1

4
2 1 1 1
1 1 2 1
2 1 1 2
1 2 1 2

4
182 168 60 96
78 72 45 72
69 21 144 63
148 12 105 6
*/