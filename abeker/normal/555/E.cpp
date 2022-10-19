#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;
const int LOG = 19;

int N, M, Q;
vector < pii > E[MAXN];
int u[MAXN], v[MAXN];
int s[MAXN], d[MAXN];
int disc[MAXN], low[MAXN];
int comp[MAXN];
bool bridge[MAXN];
int timer = 1;
vector <int> tree[MAXN];
bool bio[MAXN];
int anc[MAXN][LOG];
int depth[MAXN];
int sum[MAXN];
vector < pii > cond;

void add_edge(int idx) {
    E[u[idx]].push_back(pii(v[idx], idx));
    E[v[idx]].push_back(pii(u[idx], idx));
}

void load() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", u + i, v + i);
        add_edge(i);        
    }
    for (int i = 0; i < Q; i++)
        scanf("%d%d", s + i, d + i);
}

void dfs(int x, int prev, int c) {
    comp[x] = c;
    disc[x] = timer++;
    low[x] = disc[x];
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i].first;
        int edge = E[x][i].second;
        if (edge == prev) continue;
        if (disc[nxt]) 
            low[x] = min(low[x], disc[nxt]);
        else {
            dfs(nxt, edge, c);
            low[x] = min(low[x], low[nxt]);
            if (low[nxt] == disc[nxt]) 
                bridge[edge] = true;
        }
    }
}

void build(int x, int p) {
    bio[x] = true;
    anc[x][0] = p;
    depth[x] = depth[p] + 1;
    for (int i = 0; i < tree[x].size(); i++)
        if (tree[x][i] != p) build(tree[x][i], x);
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    int diff = depth[y] - depth[x];
    for (int i = LOG - 1; i >= 0; i--)
        if (diff >> i & 1) y = anc[y][i];
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) 
        if (anc[x][i] != anc[y][i] && anc[x][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    return anc[x][0];
}

int calc(int x, int p) {
    bio[x] = true;
    for (int i = 0; i < tree[x].size(); i++)
        if (tree[x][i] != p) sum[x] += calc(tree[x][i], x);
    return sum[x];
}

void finish(int x, int p) {
    bio[x] = true;
    sum[x] += sum[p];
    for (int i = 0; i < tree[x].size(); i++)
        if (tree[x][i] != p) finish(tree[x][i], x);
}

bool solve() {
    int curr = 0;
    for (int i = 1; i <= N; i++) 
        if (!disc[i]) dfs(i, -1, ++curr);
        
    for (int i = 0; i < Q; i++)
        if (comp[s[i]] != comp[d[i]]) return 0;
        
    for (int i = 1; i <= N; i++)
        E[i].clear();
    for (int i = 0; i < M; i++)
        if (!bridge[i]) add_edge(i);
    
    curr = 0;
    memset(disc, 0, sizeof disc);
    for (int i = 1; i <= N; i++)
        if (!disc[i]) dfs(i, -1, ++curr);
       
    for (int i = 0; i < M; i++) {
        u[i] = comp[u[i]]; 
        v[i] = comp[v[i]];
    }
    for (int i = 0; i < Q; i++) {
        s[i] = comp[s[i]];
        d[i] = comp[d[i]];
    }
    
    for (int i = 0; i < M; i++)
        if (bridge[i]) {
            tree[u[i]].push_back(v[i]);
            tree[v[i]].push_back(u[i]);
        }
    
    for (int i = 1; i <= curr; i++)
        if (!bio[i]) build(i, 0);
    
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= curr; i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
    
    for (int i = 0; i < Q; i++) {
        if (s[i] == d[i]) continue;
        int l = lca(s[i], d[i]);
        sum[s[i]]++;
        sum[l]--;
        cond.push_back(pii(l, d[i]));
    }
    
    memset(bio, false, sizeof bio);
    for (int i = 1; i <= curr; i++)
        if (!bio[i]) calc(i, 0);
    
    memset(bio, false, sizeof bio);
    for (int i = 1; i <= curr; i++)
        if (!bio[i]) finish(i, 0);
                
    for (int i = 0; i < cond.size(); i++)
        if (sum[cond[i].second] > sum[cond[i].first]) return 0;
    return 1;
}

int main() {
    load();
    puts(solve() ? "Yes" : "No");
    return 0;
}