#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MAXK = 1000005;
const int MOD = 1000000007;
const int LOG = 19;

int N, K;
int anc[MAXN][LOG];
int a[MAXN], b[MAXN], x[MAXN];
vector <int> E[MAXN];
int depth[MAXN];
int sum[MAXN][2];
int pow[MAXK];

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        scanf("%d%d%d", a + i, b + i, x + i);
        E[a[i]].push_back(b[i]);
        E[b[i]].push_back(a[i]);
    }
}

void dfs(int x, int p) {
    anc[x][0] = p;
    depth[x] = depth[p] + 1;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x);
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++)
        if (diff >> i & 1) a = anc[a][i];
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--)
        if (anc[a][i] && anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    return anc[a][0];
}

void go(int x, int p) {
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p) continue;
        go(E[x][i], x);
        sum[x][0] += sum[nxt][0];
        sum[x][1] += sum[nxt][1];
    }      
}

int solve() {
    dfs(1, 0);
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= N; i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
    scanf("%d", &K);
    pow[0] = 1;
    for (int i = 1; i <= K; i++)
        pow[i] = 2 * pow[i - 1] % MOD;
    int last = 1;
    while (K--) {
        int x;
        scanf("%d", &x);
        int l = lca(last, x);
        sum[last][0]++;
        sum[l][0]--;
        sum[x][1]++;
        sum[l][1]--;
        last = x;
    }
    go(1, 0);
    int sol = 0;
    for (int i = 1; i < N; i++) {
        if (!x[i]) continue;
        int dir = 1;
        if (anc[b[i]][0] == a[i]) {
            swap(a[i], b[i]); 
            dir = 0;
        }
        sol += pow[sum[a[i]][dir]] - 1;
        if (sol >= MOD) sol -= MOD;
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}