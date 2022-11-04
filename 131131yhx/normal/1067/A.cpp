#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 100010
#define P 998244353
#define int long long

using namespace std;

int n, A[M], F[2][205][3], G[2][205][3];

void add(int &x, int y) {x = (x + y) % P;}

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    if(A[1] == -1) {
        for(int i = 1; i <= 200; i++) F[0][i][0] = 1;
    } else F[0][A[1]][0] = 1;
    int a = 0, b = 1;
    for(int j = 1; j <= 200; j++)
        for(int k = 0; k < 3; k++)
            G[a][j][k] = (F[a][j][k] + G[a][j - 1][k]) % P;
    for(int i = 2; i <= n; i++, swap(a, b)) {
        memset(F[b], 0, sizeof F[b]);
        memset(G[b], 0, sizeof G[b]);
        for(int j = A[i] != -1 ? A[i] : 1; j <= (A[i] != -1 ? A[i] : 200); j++) {
            F[b][j][2] = (F[a][j][0] + F[a][j][1] + F[a][j][2]) % P;
            F[b][j][0] = (G[a][j - 1][0] + G[a][j - 1][1] + G[a][j - 1][2]) % P;
            F[b][j][1] = (G[a][200][1] - G[a][j][1] + G[a][200][2] - G[a][j][2]) % P;
        }
        for(int j = 1; j <= 200; j++)
            for(int k = 0; k < 3; k++)
                G[b][j][k] = (F[b][j][k] + G[b][j - 1][k]) % P;
    }
    printf("%lld\n", ((G[a][200][1] + G[a][200][2]) % P + P) % P);
    return 0;
}