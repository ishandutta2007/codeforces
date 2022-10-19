#include <cstdio>
using namespace std;

const int MAXN = 4005;
const int MOD = 1000000007;

int N;
int part[MAXN][MAXN];
int choose[MAXN][MAXN];
int tot[MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d", &N);
}

int solve() {
    for (int i = 0; i <= N; i++)
        choose[i][0] = 1;
    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= i; j++)
            choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]); 
    
    tot[0] = 1;
    part[0][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++) {
            part[i][j] = add(part[i - 1][j - 1], mul(part[i - 1][j], j));
            tot[i] = add(tot[i], part[i][j]);
        }
        
    int sol = 0;
    for (int i = 1; i <= N; i++)
        sol = add(sol, mul(choose[N][i], tot[N - i]));
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}