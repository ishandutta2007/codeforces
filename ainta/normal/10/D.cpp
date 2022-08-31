#include<stdio.h>
int n, m, a[501], b[501], i, j, D[501][501], P1[501][501], P2[501][501], k, w[501];
int main(){
    int x, y, M = 0, t;
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (i = 1; i <= m; i++){
        scanf("%d", &b[i]);
    }
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            D[i][j] = D[i][j - 1], P1[i][j] = P1[i][j - 1], P2[i][j] = P2[i][j - 1];
            if (a[i] == b[j]){
                for (k = 1; k < i; k++){
                    if (a[k] < a[i] && D[i][j] < D[k][j - 1] + 1){
                        D[i][j] = D[k][j - 1] + 1;
                        P1[i][j] = j, P2[i][j] = k;
                    }
                }
                if (!D[i][j])D[i][j] = 1;
            }
            if (M < D[i][j]){
                M = D[i][j];
                x = i, y = j;
            }
        }
    }
    for (i = M; i >= 1; i--){
        w[i] = a[x];
        if (i == 1)break;
        t = P1[x][y] - 1;
        x = P2[x][y];
        y = t;
    }
    printf("%d\n", M);
    for (i = 1; i <= M; i++)printf("%d ", w[i]);
}