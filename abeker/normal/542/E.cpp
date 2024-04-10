#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> E[MAXN];
int color[MAXN];
bool bio[MAXN];
int comp[MAXN];
int dist[MAXN];
int maks[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

bool dfs(int x, int c) {
    if (color[x] != -1) 
        return color[x] == c;
    color[x] = c;
    for (int i = 0; i < E[x].size(); i++)
        if (!dfs(E[x][i], c ^ 1)) return 0;
    return 1;
}

int bfs(int x) {
    queue <int> Q;
    memset(dist, INF, sizeof dist);
    dist[x] = 0;
    Q.push(x);
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for (int i = 0; i < E[curr].size(); i++) {
            int nxt = E[curr][i];
            if (dist[nxt] != INF) continue;
            dist[nxt] = dist[curr] + 1;
            Q.push(nxt);
        }
    }    
    
    for (int i = 1; i <= N; i++)
        if (comp[i] == comp[x]) 
            maks[comp[x]] = max(maks[comp[x]], dist[i]);
}

void flood(int x, int c) {
    bio[x] = true;
    comp[x] = c;
    for (int i = 0; i < E[x].size(); i++)
        if (!bio[E[x][i]]) flood(E[x][i], c);
}

int solve() {
    memset(color, -1, sizeof color);
    for (int i = 1; i <= N; i++)
        if (color[i] == -1 && !dfs(i, 0)) return -1;
    
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        if (!bio[i]) flood(i, cnt++);
    
    for (int i = 1; i <= N; i++)
        bfs(i);
        
    int sol = 0;
    for (int i = 0; i < cnt; i++)   
        sol += maks[i];
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}