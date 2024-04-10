#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 2005;
const int MOD = 1000000007;

int N, K;
char s[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN][MAXN];

void load() {
    scanf("%d%d%s", &N, &K, s);
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) 
        x -= MOD;
}

int up(char c) {
    return 'z' - c;
}

int down(char c) {
    return c - 'a';
}

int solve() {
    sum[N][0] = down(s[N - 1]);
    dp[N][0] = 1;
    for (int i = N - 1; i >= 0; i--) {
        double len = sqrt(max((N - i) * (N - i) - 4 * K, 0));
        int hi = (int)ceil((N + i - 1 - len) / 2);
        int lo = (int)floor((N + i - 1 + len) / 2);
        if (hi > lo) hi = lo;
        for (int j = 0; j <= K; j++) {
            dp[i][j] = sum[i + 1][j];
            for (int k = i; k < hi; k++) {
                int val = j - (k - i + 1) * (N - k);
                if (val >= 0) add(dp[i][j], mul(up(s[k]), dp[k + 1][val]));
            }
            for (int k = lo; k < N; k++) {
                int val = j - (k - i + 1) * (N - k);
                if (val >= 0) add(dp[i][j], mul(up(s[k]), dp[k + 1][val]));
            }
            add(dp[i][j], !j);
            sum[i][j] = sum[i + 1][j];
            if (i) add(sum[i][j], mul(down(s[i - 1]), dp[i][j]));
        }
    }
    
    return dp[0][K];
}


int main() {
    load();
    printf("%d\n", solve());
    return 0;
}