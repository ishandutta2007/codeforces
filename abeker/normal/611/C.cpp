#include <cstdio>
using namespace std;

const int MAXN = 505;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int N, M, Q;
char mat[MAXN][MAXN];
int deg[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%s", mat[i] + 1);
}

bool ok(int x, int y) {
    return x > 0 && y > 0 && x <= N && y <= M && mat[x][y] == '.';
}

int sum(int x1, int y1, int x2, int y2) {
    return deg[x2][y2] - deg[x2][y1 - 1] - deg[x1 - 1][y2] + deg[x1 - 1][y1 - 1];
}

int query(int x1, int y1, int x2, int y2) {
    int sol = sum(x1, y1, x2, y2);
    
    for (int i = x1; i <= x2; i++) {
        if (mat[i][y1] == '.') sol -= ok(i, y1 - 1);
        if (mat[i][y2] == '.') sol -= ok(i, y2 + 1);
    }
    
    for (int i = y1; i <= y2; i++) {
        if (mat[x1][i] == '.') sol -= ok(x1 - 1, i);
        if (mat[x2][i] == '.') sol -= ok(x2 + 1, i);
    }
    
    return sol / 2;
}

void solve() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (mat[i][j] == '#') continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                deg[i][j] += ok(x, y);
            }
        }           
        
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            deg[i][j] += deg[i][j - 1] + deg[i - 1][j] - deg[i - 1][j - 1];
         
    scanf("%d", &Q);
    while (Q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", query(x1, y1, x2, y2));
    }
}

int main() {
    load();
    solve();
    return 0;
}