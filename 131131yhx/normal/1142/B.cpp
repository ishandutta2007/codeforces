#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 400010

using namespace std;

int n, m, q, X[M], A[M], Mx[M], Nx[M], To[M], nwMx[M], Fa[M][22];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
    for(int i = 1; i <= n; i++) Nx[X[i]] = X[i % n + 1];
    for(int i = 1; i <= m; i++) scanf("%d", &A[i]), To[i] = m + 1;
    for(int i = 1; i <= n; i++) Mx[i] = -1, nwMx[i] = m + 1;
    for(int i = m; i >= 1; i--) {
        Fa[i][0] = nwMx[Nx[A[i]]];
        nwMx[A[i]] = i;
    }
    Fa[m + 1][0] = m + 1;
    for(int i = 0; i <= 20; i++)
        for(int j = 1; j <= m + 1; j++)
            Fa[j][i + 1] = Fa[Fa[j][i]][i];
    for(int i = 1; i <= m; i++) {
        int o = n - 1, nw = i;
        for(int j = 20; j >= 0; j--)
            if(o >> j & 1) nw = Fa[nw][j];
        To[i] = nw;
    }
    for(int i = m - 1; i >= 1; i--) To[i] = min(To[i], To[i + 1]);
    while(q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        putchar((To[a] <= b) + '0');
    }
    return 0;
}