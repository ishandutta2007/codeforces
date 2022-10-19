#include <cstdio>
using namespace std;

const int MAXN = 4005;
const int MAXK = 805;
const int INF = 0x3f3f3f3f;

int N, K;
int mat[MAXN][MAXN];
int dp[MAXN][MAXK];
int pivot[MAXN][MAXK];

int NextInt() {
    int ret = 0, d;
    d = getchar();
    while (d < 48 || d > 57) 
       	d = getchar();
    do {
        ret = ret * 10 + d - 48;
        d = getchar();
    } while (d > 47 && d < 58);
    return ret;
}

void load() {
    N = NextInt();
    K = NextInt();
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) 
            mat[i][j] = NextInt() + mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
}

int sum(int x, int y) {
    return mat[y][y] - mat[x - 1][y] - mat[y][x - 1] + mat[x - 1][x - 1];
}

void rec(int lo, int hi, int from, int to, int idx) {
    int mid = (lo + hi) / 2;
    for (int i = from; i < mid && i <= to; i++) {
        int curr = dp[i][idx - 1] + sum(i + 1, mid);
        if (curr < dp[mid][idx]) {
            dp[mid][idx] = curr;
            pivot[mid][idx] = i;
        }
    }
    if (lo >= hi) return;
    rec(lo, mid - 1, from, pivot[mid][idx], idx);
    rec(mid + 1, hi, pivot[mid][idx], to, idx);
}
   
int solve() { 
    for (int i = 0; i <= N; i++) 
        for (int j = 0; j <= K; j++)
            dp[i][j] = INF;
            
    dp[0][0] = 0;
    for (int i = 1; i <= K; i++)
        rec(1, N, 0, N - 1, i);
        
    return dp[N][K] / 2;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}