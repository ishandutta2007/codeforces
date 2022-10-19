#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2005;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int N, M;
char mat[MAXN][MAXN];
int deg[MAXN][MAXN];
queue < pii > Q;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) 
        scanf("%s", mat[i]);
}

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M && mat[x][y] == '.';
}

void solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (!ok(i, j)) continue;
            for (int k = 0; k < 4; k++)
                deg[i][j] += ok(i + dx[k], j + dy[k]);
            if (deg[i][j] == 1) Q.push(pii(i, j));
        }
    
    while (!Q.empty()) {
        pii p = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) 
            if (ok(p.first + dx[k], p.second + dy[k])) {
                if (k & 1) {
                    mat[p.first][p.second + min(dy[k], 0)] = '<';
                    mat[p.first][p.second + max(dy[k], 0)] = '>';
                }
                else {
                    mat[p.first + min(dx[k], 0)][p.second] = '^';
                    mat[p.first + max(dx[k], 0)][p.second] = 'v';
                }
                p.first += dx[k];
                p.second += dy[k];
                for (int i = 0; i < 4; i++) {
                    pii tmp(p.first + dx[i], p.second + dy[i]);
                    if (ok(tmp.first, tmp.second) && --deg[tmp.first][tmp.second] == 1)  
                        Q.push(tmp);
                }                
                break;
            }
    }    
    
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            if (ok(i, j)) {
                puts("Not unique");
                return;
            }
            
    for (int i = 0; i < N; i++, puts("")) 
        for (int j = 0; j < M; j++) 
            printf("%c", mat[i][j]);
}

int main() {
    load();
    solve();
    return 0;
}