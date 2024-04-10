#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int N, M;
int mat[MAXN][MAXN];
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int c[MAXN][MAXN];
int d[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", mat[i] + j);
}

int rec_a(int x, int y) {
    if (a[x][y] != -1) return a[x][y];
    return a[x][y] = mat[x][y] + max(rec_a(x - 1, y), rec_a(x, y - 1));
}

int rec_b(int x, int y) {
    if (b[x][y] != -1) return b[x][y];
    return b[x][y] = mat[x][y] + max(rec_b(x - 1, y), rec_b(x, y + 1));
}

int rec_c(int x, int y) {
    if (c[x][y] != -1) return c[x][y];
    return c[x][y] = mat[x][y] + max(rec_c(x + 1, y), rec_c(x, y + 1));
}

int rec_d(int x, int y) {
    if (d[x][y] != -1) return d[x][y];
    return d[x][y] = mat[x][y] + max(rec_d(x + 1, y), rec_d(x, y - 1));
}

int solve() {
    memset(a, -INF, sizeof a);
    memset(b, -INF, sizeof b);
    memset(c, -INF, sizeof c);
    memset(d, -INF, sizeof d);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            a[i][j] = b[i][j] = c[i][j] = d[i][j] = -1;
    a[1][1] = mat[1][1];
    b[1][M] = mat[1][M];
    c[N][M] = mat[N][M];
    d[N][1] = mat[N][1];
     
    ll sol = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            sol = max(sol, (ll)rec_a(i - 1, j) + (ll)rec_c(i + 1, j) + (ll)rec_b(i, j + 1) + (ll)rec_d(i, j - 1));
            sol = max(sol, (ll)rec_b(i - 1, j) + (ll)rec_d(i + 1, j) + (ll)rec_a(i, j - 1) + (ll)rec_c(i, j + 1));
        }
    return (int)sol;   
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}