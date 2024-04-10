#include <cstdio>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int t, K;
int dp[MAXN];

void load() {
    scanf("%d%d", &t, &K);
}

void solve() {
    dp[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        if (i < K) dp[i] = 1;    
        else dp[i] = dp[i - K] + 1;
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (dp[b] - dp[a - 1] + MOD) % MOD);
    }
}

int main() {
    load();
    solve();
    return 0;
}