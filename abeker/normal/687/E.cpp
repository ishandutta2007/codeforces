#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;

int N, M;
vector <int> E[MAXN];
int dist[MAXN][MAXN];
queue <int> Q;
int disc[MAXN], low[MAXN];
bool on[MAXN];
stack <int> S;
vector < vector <int> > comp;
int which[MAXN];
int timer = 1;

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
    }
}

void bfs(int node) {
    Q.push(node);
    dist[node][node] = 0;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < E[x].size(); i++) {
            int nxt = E[x][i];
            if (dist[node][nxt] != -1) continue;
            Q.push(nxt);
            dist[node][nxt] = dist[node][x] + 1;
        }
    }
}

void tarjan(int x) {
    low[x] = disc[x] = timer++;
    S.push(x);
    on[x] = true;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (!disc[nxt]) {
            tarjan(nxt);
            low[x] = min(low[x], low[nxt]);
        }
        else if (on[nxt])
            low[x] = min(low[x], disc[nxt]);
    }
    if (low[x] < disc[x]) return;
    vector <int> tmp;
    for (int node = 0; !S.empty() && node != x; S.pop()) {
        node = S.top();
        tmp.push_back(node);
        on[node] = false;
        which[node] = comp.size();
    } 
    comp.push_back(tmp);
}

int calc(int idx) {
    int cycle = INF;
    for (int i = 0; i < comp[idx].size(); i++) {
        int x = comp[idx][i];
        for (int j = 0; j < E[x].size(); j++) {
            int nxt = E[x][j];
            if (which[nxt] != idx) return 0;
            cycle = min(cycle, dist[nxt][x] + 1);
        }            
    }
    if (cycle == INF) return 0;
    return 998 * cycle + 1;
}

int solve() {
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= N; i++)
        bfs(i);
        
    for (int i = 1; i <= N; i++)
        if (!disc[i]) tarjan(i);    
        
    int sol = N;
    for (int i = 0; i < comp.size(); i++) 
        sol += calc(i);
        
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}