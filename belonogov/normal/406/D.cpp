#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 2e5 + 10;
const int inf = 1e9;

struct pnt {
    long long x, y;
    pnt(){}
    pnt(long long x, long long y): x(x), y(y) {}
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    long long operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    void read() {
        //shanf("%lld%lld", &x, &y);
        scanf("%I64d%I64d", &x, &y);
    }
};

pnt p[maxn];
pnt stack[maxn];
int id[maxn];
int cur = 0;
int next[maxn];
vector < int > e[maxn];
bool use[maxn];
int lca[20][maxn];
int tin[maxn];
int tout[maxn];
int tmr = 0;;

void dfs0(int v) {
    tin[v] = tmr++;
    for (int i = 0; i < (int)e[v].size(); i++)
        dfs0(e[v][i]);
    tout[v] = tmr++;
}

void dfs(int v, int p, int t) {
    if (t == 0)
        lca[t][v] = p;
    else
        lca[t][v] = lca[t - 1][lca[t - 1][v]];
    for (int i = 0; i < (int)e[v].size(); i++)
        dfs(e[v][i], v, t);
}

bool par(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLca(int v, int u) {
    if (par(v, u)) return v;
    if (par(u, v)) return u;
    for (int i = 19; i >= 0; i--)
        if (!par(lca[i][v], u))
            v = lca[i][v];
    return lca[0][v];
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, m, v, u;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }
    stack[0] = p[n - 1];
    id[0] = n - 1;
    cur = 1;
    next[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--) {
        for (; cur >= 2 && (stack[cur - 2] - stack[cur - 1]) * (stack[cur - 1] - p[i]) < 0; cur--);
        next[i] = id[cur - 1];
        stack[cur] = p[i];
        id[cur] = i;
        cur++;
    }
    
    cerr << "next: ";
    for (int i = 0; i < n; i++)
        cerr << next[i] + 1 << " ";
    cerr << endl;
    for (int i = 0; i < n - 1; i++) {
        e[next[i]].pb(i);
    }
    dfs0(n - 1);
    for (int t = 0; t < 20; t++) {
        dfs(n - 1, n - 1, t);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v, &u); v--; u--;
        printf("%d ", getLca(v, u) + 1);
    }
    return 0;
}