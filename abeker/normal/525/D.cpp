#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 2005;

int N, M;
char mat[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", mat[i]);
}

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= N - 1 || y >= M - 1) 
        return;
    int cnt = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cnt += mat[x + i][y + j] == '*';
    if (cnt != 1) return;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            mat[x + i][y + j] = '.';
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            dfs(x + i, y + j);
}

void solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dfs(i, j);
    
    for (int i = 0; i < N; i++, puts(""))
        for (int j = 0; j < M; j++)
            printf("%c", mat[i][j]);
}

int main() {
    load();
    solve();      
    return 0;
}