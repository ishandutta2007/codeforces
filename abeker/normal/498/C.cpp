#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 105;

int N, M;
int a[MAXN];
int u[MAXN], v[MAXN];
int edge[MAXN][MAXN];
vector <int> E[MAXN];
vector <int> V;
bool bio[MAXN];
int sol;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
    for (int i = 0; i < M; i++) 
        scanf("%d%d", u + i, v + i);
}

void factor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        while (!(x % i)) x /= i;
        V.push_back(i);
    }
    if (x > 1) V.push_back(x);
}

int dfs(int x, int cap) {
    if (cap <= 0) return 0;
    bio[x] = true;
    if (x == N + 1) {
        sol += cap;
        return cap;
    }
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (bio[nxt]) continue;
        int tmp = dfs(nxt, min(cap, edge[x][nxt]));
        if (tmp > 0) {
            edge[x][nxt] -= tmp;
            edge[nxt][x] += tmp;
            return tmp;
        }
    }
    return 0;
}

void flow(int prime) {
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int x = a[i]; !(x % prime); x /= prime)
            cnt++;
        if (i & 1) edge[i][N + 1] = cnt;
        else edge[0][i] = cnt;
    }
    
    for (int i = 0; i < M; i++) {
        edge[u[i]][v[i]] = 100;
        edge[v[i]][u[i]] = 0;
    }
    
    while (1) {
        memset(bio, false, sizeof bio);
        if (!dfs(0, 100)) break;
    }
}

int solve() {
    for (int i = 0; i < M; i++) { 
        if (u[i] & 1) swap(u[i], v[i]);
        E[u[i]].push_back(v[i]);
        E[v[i]].push_back(u[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        E[0].push_back(i);
        E[i].push_back(N + 1);
    }
    
    for (int i = 1; i <= N; i++) 
        factor(a[i]);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    
    for (int i = 0; i < V.size(); i++)
        flow(V[i]);
        
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}