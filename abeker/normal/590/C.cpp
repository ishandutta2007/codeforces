#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1005;
const int INF = (int)1e8;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int N, M;
char mat[MAXN][MAXN];
int dist[MAXN][MAXN][3];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", mat[i]);
}

bool ok(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && mat[x][y] != '#';
}

void bfs(int x) {
    queue <pii> Q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (mat[i][j] == x + '1') {
                Q.push(pii(i, j));
                dist[i][j][x] = 0;
            }
            else dist[i][j][x] = INF;
        
    while (!Q.empty()) {
        pii curr = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (ok(nx, ny) && dist[nx][ny][x] == INF) {
                Q.push(pii(nx, ny));
                dist[nx][ny][x] = dist[curr.first][curr.second][x] + 1;
            }
        }
    }
}

int solve() {
    for (int i = 0; i < 3; i++) 
        bfs(i);
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < 3; k++)
                dist[i][j][k]--;
                
    int sum = 0, mx = -INF;
    for (int k = 0; k < 3; k++) 
        for (int l = 0; l < k; l++) {
            int mini = INF;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    if (mat[i][j] == k + '1') 
                        mini = min(mini, dist[i][j][l]);
            sum += mini;
            mx = max(mx, mini);
        }
    
    int sol = sum - mx;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            sol = min(sol, dist[i][j][0] + dist[i][j][1] + dist[i][j][2] + 1);
    
    if (sol > N * M) sol = -1;
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}