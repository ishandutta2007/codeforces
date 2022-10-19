#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 2005;

int N;
int mat[MAXN][MAXN];
vector <int> E[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            scanf("%d", mat[i] + j);
}

bool dfs(int root, int x, int p, int d) {
    if (d != mat[root][x]) return 0;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p && !dfs(root, E[x][i], x, d + mat[x][E[x][i]]))
            return 0;
    return 1;
}

bool solve() {
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (i == j && mat[i][j]) return 0;
            if (i != j && !mat[i][j]) return 0;
            if (mat[i][j] != mat[j][i]) return 0;
        }
    
    for (int i = 1; i < N; i++) {
        int dad = 0; 
        for (int j = 1; j < N; j++) { 
            if (i == j || mat[0][i] - mat[0][j] != mat[i][j]) continue;
            if (mat[i][j] > mat[i][dad]) continue;
            if (mat[i][j] == mat[i][dad]) return 0;
            dad = j;
        }
        E[dad].push_back(i);
        E[i].push_back(dad);
        //printf("%d %d\n", i, dad);
    }
    
    for (int i = 0; i < N; i++) 
        if (!dfs(i, i, -1, 0))
            return 0;
    return 1;
}

int main() {
    load();
    puts(solve() ? "YES" : "NO");
    return 0;
}