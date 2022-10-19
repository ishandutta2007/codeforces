#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int INF = 1000005;

int N, M;
int idx[MAXN];
vector <int> E[MAXN];
int timer = 1;
int up[MAXN], down[MAXN];
int disc[MAXN], fin[MAXN];
int depth[MAXN], dad[MAXN];
int mx[MAXN][2];
int cnt[MAXN];
int node[MAXN];
int root;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i = 0; i < M; i++)
        scanf("%d", idx + i);
}

void dfs(int x, int p) {
    disc[x] = timer++;
    node[disc[x]] = x;
    depth[x] = depth[p] + 1;
    dad[x] = p;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x);
    fin[x] = timer;
}

int sum(int x) {
    return cnt[fin[x] - 1] - cnt[disc[x] - 1];
}

bool ok(int x) {
    int val = sum(x);
    return val && val < M;
}

int calc(int x, int p) {
    mx[x][0] = depth[x];
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p || !ok(nxt)) continue;
        int val = calc(nxt, x);
        if (val >= mx[x][0]) {
            mx[x][1] = mx[x][0];
            mx[x][0] = val;
        }
        else mx[x][1] = max(mx[x][1], val);
    }
    down[x] = mx[x][0] - depth[x];
    return mx[x][0];
}

int get(int x, int val) {
    if (mx[x][0] == val) return mx[x][1];
    return mx[x][0];
}

void go(int x, int p) {
    up[x] = max(get(p, mx[x][0]) - depth[p], up[p]) + 1;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p && ok(E[x][i])) go(E[x][i], x);
}

bool check(int x) {
    for (int i = 0; i < E[x].size(); i++)
        if (ok(E[x][i])) return true;
    return false;
}

void solve() {
    if (M == 1) {
        printf("%d\n0\n", idx[0]);
        return;
    }
    
    dfs(1, 0);
    for (int i = 0; i < M; i++)
        cnt[disc[idx[i]]]++;
    for (int i = 1; i <= N; i++)
        cnt[i] += cnt[i - 1];
    
    for (int i = 1; i <= N && !root; i++)
        if (check(node[i])) root = node[i];
    
    for (int i = 0; i <= N; i++) {
        up[i] = down[i] = -INF;
        mx[i][0] = mx[i][1] = -INF;
    }
    
    calc(root, dad[root]);
    go(root, dad[root]);
        
    int opt = max(*max_element(up + 1, up + N + 1), *max_element(down + 1, down + N + 1));
    int pos = N + 1;
    for (int i = 1; i <= N; i++)
        if (up[i] == opt || down[i] == opt) 
            pos = min(pos, i);
    
    printf("%d\n", pos);
    int tot = 0;
    for (int i = 1; i <= N; i++)
        tot += ok(i);
    printf("%d\n", 2 * tot - opt);
}

int main() {
    load();
    solve();
    return 0;
}