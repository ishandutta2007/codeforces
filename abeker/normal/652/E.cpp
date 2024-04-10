#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 300005;

int N, M, A, B;
int x[MAXN], y[MAXN], z[MAXN];
vector <pii> E[MAXN];
int disc[MAXN], fin[MAXN];
int low[MAXN];
int comp[MAXN];
bool bridge[MAXN], has[MAXN];
bool bio[MAXN];
int timer = 1;
vector <int> path;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%d%d%d", x + i, y + i, z + i);
    scanf("%d%d", &A, &B);
}

void dfs(int x, int prev) {
    disc[x] = timer++;
    low[x] = disc[x];
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i].first;
        int edge = E[x][i].second;
        if (edge == prev) continue;
        if (disc[nxt]) 
            low[x] = min(low[x], disc[nxt]);
        else {
            dfs(nxt, edge);
            low[x] = min(low[x], low[nxt]);
            if (low[nxt] == disc[nxt]) 
                bridge[edge] = true;
        }
    }
}

void add_edge(int idx) {
    E[x[idx]].push_back(pii(y[idx], idx));
    E[y[idx]].push_back(pii(x[idx], idx));
}

bool go(int node) {
    bio[node] = true;
    if (node == B) {
        bool ok = false;
        for (int i = 0; i < path.size(); i++) {
            ok |= z[path[i]];
            ok |= has[comp[x[path[i]]]];
            ok |= has[comp[y[path[i]]]];
        }
        return ok;
    }
    for (int i = 0; i < E[node].size(); i++) {
        int nxt = E[node][i].first;
        if (bio[nxt]) continue;
        path.push_back(E[node][i].second);
        if (go(nxt)) return true;
        path.pop_back();
    }
    return false;
}

void flood(int x, int c) {
    bio[x] = true;
    comp[x] = c;
    for (int i = 0; i < E[x].size(); i++)
        if (!bio[E[x][i].first]) flood(E[x][i].first, c);
}

bool solve() {
    for (int i = 0; i < M; i++) 
        add_edge(i);
    
    for (int i = 1; i <= N; i++)
        if (!disc[i]) dfs(i, -1);
    
    for (int i = 1; i <= N; i++)
        E[i].clear();
    
    for (int i = 0; i < M; i++)
        if (!bridge[i]) add_edge(i);
        
    int curr = 0;
    for (int i = 1; i <= N; i++)
        if (!bio[i]) flood(i, ++curr);
    
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < E[i].size(); j++) 
            has[comp[i]] |= z[E[i][j].second];
    
    if (comp[A] == comp[B]) return has[comp[A]];
    
    for (int i = 0; i < M; i++)
        if (bridge[i]) add_edge(i);
    memset(bio, false, sizeof bio);
    
    return go(A);
}

int main() {
    load();
    puts(solve() ? "YES" : "NO");
    return 0;
}