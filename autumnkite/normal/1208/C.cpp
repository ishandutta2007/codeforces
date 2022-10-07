#include <cstdio>
int n, a[1005][1005];
int main(){
    scanf("%d", &n), n >>= 1;
    for (register int i = 0; i < n; ++i)
        for (register int j = 0; j < n; ++j){
            int x = (i * n + j) * 4;
            a[i][j] = x, a[i][j + n] = x + 1, a[i + n][j] = x + 2, a[i + n][j + n] = x + 3;
        }
    n <<= 1;
    for (register int i = 0; i < n; ++i){
        for (register int j = 0; j < n; ++j) printf("%d ", a[i][j]);
        putchar('\n');
    }
}