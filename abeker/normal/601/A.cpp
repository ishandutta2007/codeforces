#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 405;

int N, M;
bool mat[MAXN][MAXN];
int dist[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        mat[u][v] = mat[v][u] = true;
    }
}

int solve() {
    memset(dist, -1, sizeof dist);
    queue <int> Q;
    Q.push(1);
    dist[1] = 0;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 1; i <= N; i++)
            if (i != x && mat[x][i] ^ mat[1][N] && dist[i] == -1) {
                dist[i] = dist[x] + 1;
                Q.push(i);
            }
    }
    
    return dist[N];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}