#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 111

using namespace std;

int n, Head[M], Next[M], Go[M], Dep[M], Sz[M], ans = 0, nw = 0, _1 = 0, Cnt = 0;

double F[M][M], C[M][M], Fac[M];

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

void DFS1(int x, int f = 0) {
    Sz[x] = 1;
    double tmp[2][M];
    memset(tmp, 0, sizeof tmp);
    int a = 0, b = 1;
    tmp[0][0] = 1;
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) {
        int g = Go[T];
        DFS1(g, x);
        memset(tmp[b], 0, sizeof tmp[b]);
        for(int j = 0; j <= Sz[x]; j++)
            for(int k = 0; k <= Sz[g]; k++) if(F[g][k])
                tmp[b][j + k] += tmp[a][j] * F[g][k] / Fac[k] / Fac[Sz[g] - k];
        Sz[x] += Sz[g];
        swap(a, b);
    }
    for(int i = 0; i < Sz[x]; i++) tmp[a][i] *= Fac[i] * Fac[Sz[x] - 1 - i];
    for(int i = 0; i <= Sz[x]; i++) {
        for(int j = 0; j < Sz[x]; j++)
            F[x][i] += tmp[a][max(i - 1, j)] / 2 * (1 + (j <= i - 1));
    }
}

double Solve(int x) {
    memset(F, 0, sizeof F);
    double ans = 1;
    for(int T = Head[x]; T; T = Next[T]) {
        DFS1(Go[T], x);
        ans *= F[Go[T]][0] / Fac[Sz[Go[T]]];
    }
    return ans;
}

signed main() {
    for(int i = 0; i < M; i++)
        for(int j = 0; j <= i; j++)
            C[i][j] = !j ? 1 : C[i - 1][j - 1] + C[i - 1][j];
    Fac[0] = 1;
    for(int i = 1; i < M; i++) Fac[i] = Fac[i - 1] * i;
    scanf("%lld", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    for(int i = 1; i <= n; i++) printf("%.12lf\n", Solve(i));
    return 0;
}