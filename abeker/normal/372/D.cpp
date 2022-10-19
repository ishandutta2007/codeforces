#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int LOG = 18;

int N, K;
vector <int> E[MAXN];
int disc[MAXN], fin[MAXN];
int dad[MAXN][LOG];
int depth[MAXN];
int t[MAXN][LOG];
int exp[MAXN];
int f[MAXN];
int timer = 1;
int sz;

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int x, int p) {
    dad[x][0] = p;
    depth[x] = depth[p] + 1;
    disc[x] = timer++;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x);
    fin[x] = timer;
}

void update(int x, int val) {
    for (; x < MAXN; x += x & -x)
        f[x] += val;
}

int get(int x) {
    int ret = 0;
    for (; x > 0; x -= x & -x)
        ret += f[x];
    return ret;
}

int jmp(int x, int d) {
    for (int i = 0; i < LOG; i++)
        if (d >> i & 1) x = dad[x][i];
    return x;
}

int sum(int x) {
    return get(fin[x] - 1) - get(disc[x] - 1);
}

void add(int x, int c) {
    int lo = 0, hi = depth[x];
    if (c == -1) update(disc[x], c);
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (sum(jmp(x, mid)) > 0) hi = mid;
        else lo = mid + 1;
    }
    if (c == 1) update(disc[x], c);
    sz += c * lo;
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    b = jmp(b, depth[b] - depth[a]);
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--)
        if (dad[a][i] != dad[b][i]) {
            a = dad[a][i];
            b = dad[b][i];
        }
    return dad[a][0];
}

int query(int lo, int hi) {
    int e = exp[hi - lo];
    return lca(t[lo][e], t[hi - (1 << e)][e]);
}

int tot(int lo, int hi) {
    return sz - depth[query(lo, hi)] + 1;
}

int solve() {	
    dfs(1, 0);
    
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= N; i++)
            dad[i][j] = dad[dad[i][j - 1]][j - 1];
    
    for (int i = 1; i <= N; i++) {
        if (i > 1) exp[i] = exp[i / 2] + 1;
        t[i][0] = i;
    }
    
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= N; i++)
            t[i][j] = lca(t[i][j - 1], t[i + (1 << j - 1)][j - 1]);
    
    int j = 1, sol = 0;
    for (int i = 1; i <= N; i++) { 
        if (tot(i, j + 1) > K) {
            add(i, -1);
            continue;
        }
        for (j++; j <= N; j++) {
            add(j, 1);
            if (tot(i, j + 1) > K) break;
        }
        sol = max(sol, j - i);
        if (i > 1) add(i, -1);
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}