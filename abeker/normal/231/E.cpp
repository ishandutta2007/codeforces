#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int LOG = 19;
const int MOD = 1000000007;

int N, M, K;
vector <int> E[MAXN];
vector <int> V;
int bio[MAXN];
vector < vector <int> > cycles;
int depth[MAXN], sum[MAXN];
int anc[MAXN][LOG];
int pow[MAXN];
int idx[MAXN];

void add_edge(int a, int b) {
    E[a].push_back(b);
    E[b].push_back(a);
}

void remove_edge(int from, int to) {
    for (int i = 0; i < E[from].size(); i++)
        if (E[from][i] == to) {
            E[from].erase(E[from].begin() + i);
            break;
        }
}

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add_edge(a, b);
    }
}

void doit(int val) {
    vector <int> tmp;
    for (int i = (int)V.size() - 1; i >= 0; i--) {
        tmp.push_back(V[i]);
        if (V[i] == val) break;
    }
    cycles.push_back(tmp);
}

void dfs(int x, int p) {
    bio[x] = 1;
    V.push_back(x);
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p || bio[nxt] == 2) continue;
        if (bio[nxt]) doit(nxt);
        else dfs(nxt, x);
    }
    V.pop_back();
    bio[x] = 2;
}

void build(int x, int p) {
    anc[x][0] = p;
    depth[x] = depth[p] + 1;
    sum[x] = sum[p] + (x > N);
    for (int i = 0; i < E[x].size(); i++) 
        if (E[x][i] != p) build(E[x][i], x);
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = LOG - 1; i >= 0; i--)
        if (diff >> i & 1) a = anc[a][i];
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--)
        if (anc[a][i] && anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    return anc[a][0];
}

void solve() {
    dfs(1, 0);
    for (int i = 1; i <= N; i++)
        idx[i] = i;
        
    for (int i = 0; i < cycles.size(); i++)
        for (int j = 0; j < cycles[i].size(); j++) {
            int curr = cycles[i][j];
            idx[curr] = N + i + 1;
            int sz = cycles[i].size();
            int nxt = cycles[i][(j + 1) % sz];
            int prev = cycles[i][(j - 1 + sz) % sz]; 
            for (; !E[curr].empty(); E[curr].pop_back()) {
                int neigh = E[curr].back();
                remove_edge(neigh, curr);
                if (neigh != nxt && neigh != prev) 
                    add_edge(neigh, idx[curr]);
            }
        }
    
    build(N + cycles.size(), 0);
    N += cycles.size();
    
    for (int i = 1; i < LOG; i++)
        for (int j = 1; j <= N; j++)
            anc[j][i] = anc[anc[j][i - 1]][i - 1];
            
    pow[0] = 1;
    for (int i = 1; i <= N; i++)
        pow[i] = pow[i - 1] * 2 % MOD;
        
    scanf("%d", &K);
    while (K--) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = idx[x], y = idx[y];
        int node = lca(x, y), dad = anc[node][0];
        printf("%d\n", pow[sum[x] + sum[y] - sum[node] - sum[dad]]);
    }
}

int main() {
    load();
    solve();
    return 0;
}