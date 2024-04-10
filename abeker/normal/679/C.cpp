#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 505;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int N, K;
char mat[MAXN][MAXN];
int comp[MAXN][MAXN];
int sum[MAXN][MAXN];
int sz[MAXN * MAXN];
int occ[MAXN * MAXN];
int tot;

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%s", mat[i] + 1);
}

bool ok(int x, int y) {
    return mat[x][y] == '.' && !comp[x][y];
}

void dfs(int x, int y, int c) {
    comp[x][y] = c;
    sz[c]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny)) 
            dfs(nx, ny, c);
    }
}

void add(int c) {
    if (!occ[c]) tot += sz[c];
    occ[c]++;
}

void rem(int c) {
    occ[c]--;
    if (!occ[c]) tot -= sz[c];
}

int get(int x, int y) {
    return sum[x + K - 1][y + K - 1] + sum[x - 1][y - 1] - sum[x + K - 1][y - 1] - sum[x - 1][y + K - 1];
}

int solve() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + !ok(i, j);
    
    int curr = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (ok(i, j)) 
                dfs(i, j, ++curr);
    
    int sol = 0;
    for (int i = 1; i <= N - K + 1; i++) {
        tot = 0;
        memset(occ, 0, sizeof occ);
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < K + 2; k++)
                add(comp[i + j][k]);
            add(comp[i - 1][j + 1]);
            add(comp[i + K][j + 1]);
        }
        for (int j = 1; j <= N - K + 1; j++) {
            sol = max(sol, tot + get(i, j));
            for (int k = 0; k < K; k++) {
                rem(comp[i + k][j - 1]);
                add(comp[i + k][j + K + 1]);
            }
            rem(comp[i - 1][j]);
            rem(comp[i + K][j]);
            add(comp[i - 1][j + K]);
            add(comp[i + K][j + K]);
        }
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}