#include <cstdio>
using namespace std;

const int MAXN = 2005;
const int MOD = 1000000007;

int N, H;
int a[MAXN];
int dp[MAXN][2];

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void load() {
    scanf("%d%d", &N, &H);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int f(int pos, int val) {
    int idx = a[pos] + val - H + 1;
    if (idx < 0 || idx > 1) return 0;
    return dp[pos][idx];
}

int solve() {
    dp[N][0] = 1;
    a[N] = H - 1;
    for (int i = N - 1; i >= 0; i--) {
        int j = H - a[i];
        dp[i][0] = f(i + 1, j - 1);
        dp[i][1] = f(i + 1, j);
        add(dp[i][0], f(i + 1, j));
        add(dp[i][0], mul(f(i + 1, j - 1), j - 1)); 
        if (j > 0) add(dp[i][1], mul(f(i + 1, j - 1), j));
    }
    return f(0, 0);
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}