#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 505;

int N, M;
bool mat[MAXN][MAXN];
int color[MAXN];
bool ac[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        mat[u][v] = mat[v][u] = true;
    }
}

bool dfs(int x, bool c) {    
    if (color[x] != -1) return color[x] == c;
    color[x] = c;
    for (int i = 0; i < N; i++)
        if (i != x && ac[i] && !dfs(i, c == mat[x][i])) 
            return false;
    return true;
}

void solve() {
    memset(color, -1, sizeof color);
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j && !mat[i][j]) 
                ac[i] = ac[j] = true;
            
    for (int i = 0; i < N; i++)
        if (ac[i] && color[i] == -1 && !dfs(i, 0)) {
            puts("No");
            return;
        }
        
    puts("Yes");
    for (int i = 0; i < N; i++) 
        printf("%c", !ac[i] ? 'b' : "ac"[color[i]]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}