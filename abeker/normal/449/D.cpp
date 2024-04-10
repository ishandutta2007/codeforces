#include <cstdio>
using namespace std;

const int MAXB = 20;
const int MAXN = 1000005;
const int MOD = 1000000007;

int N;
int cnt[MAXN];
int dp[1 << MAXB][MAXB + 1];
int pow[MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        dp[x][0]++;
    }
}

int solve() {
    pow[0] = 1;
    for (int i = 1; i <= N; i++)
        pow[i] = add(pow[i - 1], pow[i - 1]);
        
    for (int i = (1 << MAXB) - 1; i >= 0; i--)
        for (int j = 0; j < MAXB; j++) {
            dp[i][j + 1] += dp[i][j];
            if (i >> j & 1)
                dp[i ^ 1 << j][j + 1] += dp[i][j];
        }
    
    int sol = 0;
    for (int i = 0; i < 1 << MAXB; i++) {
        int val = pow[dp[i][MAXB]];
        sol = add(sol, __builtin_popcount(i) & 1 ? -val : val);
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}