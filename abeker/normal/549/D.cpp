#include <cstdio>
using namespace std;

const int MAXN = 105;

int N, M;
int mat[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            char c; scanf(" %c", &c);
            mat[i][j] = c == 'W' ? 1 : -1;
        }
}

int solve() {
    int sol = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            sol += mat[i][j] + mat[i + 1][j + 1] != mat[i][j + 1] + mat[i + 1][j];
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}