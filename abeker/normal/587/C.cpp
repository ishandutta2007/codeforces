#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int LOG = 18;
const int MAXA = 11;

int N, M, Q;
vector <int> E[MAXN];
vector <int> V[MAXN][LOG];
int dad[MAXN][LOG];
int depth[MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    for (int i = 0; i < M; i++) {
        int c;
        scanf("%d", &c);
        V[c][0].push_back(i + 1);
    }
}

void dfs(int x, int p) {
    dad[x][0] = p;
    depth[x] = depth[p] + 1;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x);
}

vector <int> merge(const vector <int> &a, const vector <int> &b) {
    vector <int> res;
    int pos_a = 0, pos_b = 0;
    for (int i = 0; i < MAXA; i++) {
        if (pos_b < b.size() && (pos_a >= a.size() || b[pos_b] <  a[pos_a])) res.push_back(b[pos_b++]);
        if (pos_a < a.size() && (pos_b >= b.size() || a[pos_a] <= b[pos_b])) res.push_back(a[pos_a++]);
    }
    return res;
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int diff = depth[b] - depth[a];
    for (int i = 0; i < LOG; i++)
        if (diff >> i & 1) b = dad[b][i];
    
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--)
        if (dad[a][i] != dad[b][i] && dad[a][i]) {
            a = dad[a][i];
            b = dad[b][i];
        }
    return dad[a][0];
}

vector <int> query(int a, int len) {
    vector <int> res;
    for (int i = 0; i < LOG; i++) 
        if (len >> i & 1) {
            res = merge(res, V[a][i]);
            a = dad[a][i];
        }
    return res;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        sort(V[i][0].begin(), V[i][0].end());
        V[i][0].resize(min((int)V[i][0].size(), MAXA));
    }
    
    dfs(1, 0);
    
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            dad[i][j] = dad[dad[i][j - 1]][j - 1];
            V[i][j] = merge(V[i][j - 1], V[dad[i][j - 1]][j - 1]);
        }
    }
    
    while (Q--) {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        if (depth[u] < depth[v]) swap(u, v);
        int l = lca(u, v);
        vector <int> sol = merge(query(u, depth[u] - depth[l] + 1), query(v, depth[v] - depth[l]));
        int k = min(a, (int)sol.size());
        printf("%d ", k);
        for (int i = 0; i < k; i++)
            printf("%d ", sol[i]);
        puts("");
    }
}

int main() {
    load();
    solve();
    return 0;
}