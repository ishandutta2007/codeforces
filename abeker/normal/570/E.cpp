#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 505;
const int MOD = 1000000007;

int N, M;
char mat[MAXN][MAXN];
int dp[MAXN][MAXN][2];

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%s", mat[i] + 1);
}

bool bad(int x, int y) {
    return x < 1 || y < 1 || x > N || y > M;
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int solve() {
    int c = 0;
    dp[1][N][0] = mat[1][1] == mat[N][M];
    int sol = 0;
    for (int k = 1; k < (N + M) / 2; k++) {
        c ^= 1;
        sol = 0;
        for (int i = 1; i < k + 2; i++)
            for (int j = 1; j < N + M - k; j++) {
                int x1 = i, y1 = k + 2 - i;
                int x2 = j, y2 = N + M - k - j;
                if (bad(x1, y1) || bad(x2, y2)) continue;
                dp[i][j][c] = 0;
                if (mat[x1][y1] != mat[x2][y2]) continue;
                for (int a = 0; a < 2; a++)
                    for (int b = 0; b < 2; b++) 
                        add(dp[i][j][c], dp[i - a][j + b][c ^ 1]);
                if (dist(x1, y1, x2, y2) < 2) add(sol, dp[i][j][c]);
            }
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}