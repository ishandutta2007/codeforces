#include <cstdio>
using namespace std;

typedef long double ld;

const int MAXN = 2005;

int N, M;
ld dp[MAXN][MAXN];
bool row[MAXN], col[MAXN];
int a, b;

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int x, y;
        scanf("%d%d", &x, &y);
        a += !row[x];
        b += !col[y];
        row[x] = col[y] = true;
    }
}

ld solve() {
    a = N - a;
    b = N - b;
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++) {
            if (i) dp[i][j] += (ld)i * (N - j) * dp[i - 1][j];
            if (j) dp[i][j] += (ld)j * (N - i) * dp[i][j - 1];
            if (i && j) dp[i][j] += (ld)i * j * dp[i - 1][j - 1];
            if (i || j) {
                dp[i][j] += (ld)N * N;
                dp[i][j] /= (ld)N * (i + j) - (ld)i * j;
            }
        }
    return dp[a][b];
}

int main() {
    load();
    printf("%.10lf\n", (double)solve());
    return 0;
}