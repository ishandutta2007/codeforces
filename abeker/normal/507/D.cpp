#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MAXK = 105;

int N, K, M;
int tenK[MAXN], tenM[MAXN];
int dp[MAXN][MAXK];

inline int add(int x, int y, int mod) {
    x += y;
    if (x < 0) x += mod;
    else if (x >= mod) x -= mod;
    return x;
}

inline int mul(int x, int y, int mod) {
    return (ll)x * y % mod;
}

void load() {
    scanf("%d%d%d", &N, &K, &M);
}

int solve() {
    tenK[0] = 1;
    tenM[0] = 1;
    for (int i = 1; i <= N; i++) { 
        tenK[i] = mul(tenK[i - 1], 10, K);
        tenM[i] = mul(tenM[i - 1], 10, M);
    }
    
    int sol = 0;
    for (int i = 1; i <= N; i++) { 
        for (int j = 0; j < K; j++)
            for (int d = !j; d < 10; d++) {
                int rem = add(j, -mul(d, tenK[i - 1], K), K), val = 1;
                if (rem) val = dp[i - 1][rem]; 
                dp[i][j] = add(dp[i][j], val, M);
            }
        int c = 1;
        if (i < N) c = mul(tenM[N - i - 1], 9, M);
        sol = add(sol, mul(c, dp[i][0], M), M);
    }
       
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}