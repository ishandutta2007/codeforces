#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 3005;

int N, M;
vector <int> E[MAXN];
int dist[MAXN][MAXN];
vector <pii> row[MAXN], col[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u != v) E[u].push_back(v);
    }
}

void bfs(int node) {
    queue <int> Q;
    dist[node][node] = 0;
    Q.push(node);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < E[x].size(); i++) {
            int nxt = E[x][i];
            if (dist[node][nxt] != -1) continue;
            dist[node][nxt] = dist[node][x] + 1;
            Q.push(nxt);
        }
    }
}

void solve() {
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= N; i++) 
        bfs(i);
        
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            row[i].push_back(pii(dist[i][j], j));
        sort(row[i].begin(), row[i].end(), greater <pii> ());
        for (int j = 1; j <= N; j++)
            col[i].push_back(pii(dist[j][i], j));
        sort(col[i].begin(), col[i].end(), greater <pii> ());
    }
    
    int a = 0, b = 0, c = 0, d = 0, maks = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            for (int k = 0; k < 4 && k < col[i].size(); k++)
                for (int l = 0; l < 4 && l < row[j].size(); l++) {
                    int x = col[i][k].second;
                    int y = row[j][l].second;
                    if (x == i || x == j || y == i || y == j || x == y) continue;
                    if (dist[x][i] == -1 || dist[i][j] == -1 || dist[j][y] == -1) continue;
                    int tot = dist[x][i] + dist[i][j] + dist[j][y];
                    if (tot > maks) {
                        maks = tot;
                        a = x;
                        b = i;
                        c = j;
                        d = y;
                    }
                }
        }
    
    printf("%d %d %d %d\n", a, b, c, d);
}

int main() {
    load();
    solve();
    return 0;
}