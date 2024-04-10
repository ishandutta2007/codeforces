#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 1005;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int N, M;
char mat[MAXN][MAXN];
bool bio[MAXN][MAXN];
int comp[MAXN][MAXN];
int sz[MAXN * MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", mat[i]);
}

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M && mat[x][y] == '.';
}

void dfs(int x, int y, int c) {
    bio[x][y] = true;
    comp[x][y] = c;
    sz[c]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny) && !bio[nx][ny]) 
            dfs(nx, ny, c);
    }
}

void solve() {
    int curr = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (bio[i][j] || !ok(i, j)) continue;
            dfs(i, j, curr);
            curr++;
        }
    
    for (int i = 0; i < N; i++) {
        char ans[MAXN];
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == '.') {
                ans[j] = '.';
                continue;
            }
            set <int> S;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (ok(nx, ny)) 
                    S.insert(comp[nx][ny]);
            }   
            int sol = 1;
            for (set <int> :: iterator it = S.begin(); it != S.end(); it++)
                sol += sz[*it];
            ans[j] = sol % 10 + '0';
        }
        ans[M] = '\0';
        puts(ans);
    }
}

int main() {
    load();
    solve();
    return 0;
}