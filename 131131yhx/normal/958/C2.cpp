#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

int n, m, p, X[20010], F[2][111][55], s = 0, tot = 0;

#undef int
int main() {
#define int long long
    scanf("%lld%lld%lld", &n, &m, &p);
    for(int i = 1; i <= n; i++) scanf("%lld", &X[i]), s += X[i] / p, tot += X[i], X[i] %= p;
    int a = 0, b = 1;
    memset(F, 63, sizeof F);
    F[a][X[1]][1] = 0;
    for(int i = 2; i <= n; i++, swap(a, b)) {
        for(int j = 0; j < p; j++)
            for(int k = 1; k <= m; k++)
                F[b][j][k] = F[a][(j + p - X[i]) % p][k] + (j < X[i]);
        for(int k = 1; k <= m; k++)
            for(int j = 0; j < p; j++)
                F[b][X[i]][k] = min(F[b][X[i]][k], F[a][j][k - 1]);
    }
    int ans = 1e18;
    for(int i = 0; i < p; i++) ans = min(ans, F[a][i][m]);
    printf("%lld\n", tot - (s + ans) * p);
    return 0;
}