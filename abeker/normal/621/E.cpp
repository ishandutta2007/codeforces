#include <cstdio>
using namespace std;

const int MOD = 1000000007;
const int MAX = 105;
const int LOG = 30;

int N, B, K, X;
int dp[LOG][MAX];
int ways[MAX][2];
int pot[LOG];

void load() {
    scanf("%d%d%d%d", &N, &B, &K, &X);
    while (N--) {
        int digit;
        scanf("%d", &digit);
        dp[0][digit % X]++;
    }
}

inline int mul(int x, int y, int m) {
    return (long long)x * y % m;
}

inline int add(int x, int y, int m) {
    x += y;
    if (x >= m) x -= m;
    else if (x < 0) x += m;
    return x;
}

int solve() {
    pot[0] = 10 % X;
    for (int i = 1; i < LOG; i++) {    
        for (int j = 0; j < X; j++)
            for (int k = 0; k < X; k++)
                dp[i][j] = add(dp[i][j], mul(dp[i - 1][k], dp[i - 1][add(j, -mul(pot[i - 1], k, X), X)], MOD), MOD);  
        pot[i] = mul(pot[i - 1], pot[i - 1], X);
    }
    
    int c = 0, curr = 1;
    ways[0][0] = 1;
    for (int i = 0; i < LOG; i++)
        if (B >> i & 1) {
            c ^= 1;
            for (int j = 0; j < X; j++) {
                ways[j][c] = 0;     
                for (int k = 0; k < X; k++)
                    ways[j][c] = add(ways[j][c], mul(dp[i][k], ways[add(j, -mul(curr, k, X), X)][c ^ 1], MOD), MOD);
            }
            curr = mul(curr, pot[i], X);
        }
    
    return ways[K][c];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}