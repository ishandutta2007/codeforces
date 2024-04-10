#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MAXK = 505;
const int INF = (int)1e8;

int N, M, K;
int c[MAXK];
int type[MAXN];
int dist[MAXK][MAXK];
vector <int> E[MAXN];
bool bio[MAXN];
int comp[MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", c + i);
        c[i] += c[i - 1];
        for (int j = c[i - 1] + 1; j <= c[i]; j++)
            type[j] = i;
    }
    
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++)
            if (i != j) dist[i][j] = INF;
            
    while (M--) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        if (type[u] != type[v]) {
            u = type[u];
            v = type[v];
            dist[u][v] = dist[v][u] = min(dist[u][v], x); 
        }
        if (!x) {
            E[u].push_back(v);
            E[v].push_back(u);
        }
    } 
}

void dfs(int x, int c) {
    bio[x] = true;
    comp[x] = c;
    for (int i = 0; i < E[x].size(); i++)
        if (!bio[E[x][i]]) dfs(E[x][i], c);
}

void solve() {
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        if (!bio[i]) dfs(i, ++cnt);
    
    for (int i = 1; i <= N; i++) 
        if (comp[i] != comp[c[type[i]]]) {
            puts("No");
            return;
        }
    
    for (int k = 1; k <= K; k++)
        for (int i = 1; i <= K; i++)
            for (int j = 1; j <= K; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    puts("Yes");
    for (int i = 1; i <= K; i++, puts(""))
        for (int j = 1; j <= K; j++)
            printf("%d ", dist[i][j] == INF ? -1 : dist[i][j]);
}

int main() {
    load();
    solve();
    return 0;
}