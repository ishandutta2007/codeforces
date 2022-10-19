#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char name[] = "DIMA";

int n, m;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN];
char buff;

inline bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool dfs(int x, int y) {
    if (dp[x][y]) 
        return dp[x][y] == 1;
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny) && mat[nx][ny] == (mat[x][y] + 1) % 4 && dfs(nx, ny)) 
            return true;
    }
    dp[x][y] = 2;
    return false;
}
 
int rec(int x, int y) {
    if (!dp[x][y]) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ok(nx, ny) && mat[nx][ny] == (mat[x][y] + 1) % 4) 
                dp[x][y] = max(dp[x][y], rec(nx, ny));
        }
        dp[x][y]++;
    }
    return dp[x][y];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {     
            scanf(" %c", &buff);
            mat[i][j] = strchr(name, buff) - name;
        }
    //for (int i = 0; i < n; i++, puts("")) 
       //for (int j = 0; j < m; j++) 
            //printf("%d ", mat[i][j]);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (dfs(i, j)) {
                puts("Poor Inna!");
                return 0;
            }
    memset(dp, 0, sizeof dp);
    int sol = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            if (!mat[i][j]) sol = max(sol, rec(i, j) / 4);
    if (!sol) puts("Poor Dima!");
    else printf("%d\n", sol); 
    //printf("%d\n", rec(0, 0));
    return 0;
}