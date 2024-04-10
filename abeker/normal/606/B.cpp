#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 505;
const int MAXL = 100005;

const char dir[] = "URDL";
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int N, M;
int x, y;
char s[MAXL];
int sol[MAXL];
int when[MAXN][MAXN];

void load() {
    scanf("%d%d%d%d%s", &N, &M, &x, &y, s); 
}

void solve() {
    int len = strlen(s);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            when[i][j] = len;
            
    when[--x][--y] = 0;
    for (int i = 0; i < len; i++) {
        int curr = strchr(dir, s[i]) - dir;
        int nx = x + dx[curr];
        int ny = y + dy[curr];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            x = nx;
            y = ny;
        }
        when[x][y] = min(when[x][y], i + 1);
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            sol[when[i][j]]++;
    
    for (int i = 0; i <= len; i++)
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}