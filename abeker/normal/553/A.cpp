#include <cstdio>
using namespace std;

const int MAXN = 1005;  
const int MOD = 1000000007;

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int choose[MAXN][MAXN];

void init() {
    for (int i = 0; i < MAXN; i++)
        choose[i][0] = 1;
    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j <= i; j++)
            choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
}

void solve() {
    int K;
    scanf("%d", &K);
    int sum = 0, sol = 1;
    while (K--) {
        int c;
        scanf("%d", &c);
        sum += c;
        sol = mul(sol, choose[sum - 1][c - 1]);
    }
    printf("%d\n", sol);
}

int main() {
    init();
    solve();
    return 0;
}