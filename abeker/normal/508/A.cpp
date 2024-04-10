#include <cstdio>
using namespace std;

const int MAXN = 1005;

int N, M, K;
int mat[MAXN][MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &K);
}

bool ok(int x, int y) {
    return mat[x][y] && mat[x + 1][y] && mat[x][y + 1] && mat[x + 1][y + 1];
}

int solve() {
    for (int i = 1; i <= K; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        mat[x][y] = 1;
        if (ok(x, y) || ok(x - 1, y) || ok(x, y - 1) || ok(x - 1, y - 1))
            return i;
    }
    return 0;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;    
}