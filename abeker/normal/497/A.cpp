#include <cstdio>
using namespace std;

const int MAXN = 1005;

int N, M;
char mat[MAXN][MAXN];
bool flag[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) 
        scanf("%s", mat[i]);
}

int solve() {
    int sol = 0;
    for (int j = 0; j < M; j++) {
        bool remove = false; 
        for (int i = 1; i < N; i++) 
            if (mat[i][j] < mat[i - 1][j] && !flag[i]) {
                remove = true;
                break;
            }
        if (remove) { sol++; continue; }
        for (int i = 1; i < N; i++)
            if (mat[i][j] > mat[i - 1][j]) flag[i] = true;
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}