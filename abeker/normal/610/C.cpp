#include <cstdio>
using namespace std;

const int MAXN = 1 << 10;

int mat[MAXN][MAXN];

int main() {
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int len = 1 << i;
        for (int k = 0; k < len; k++)
            for (int l = 0; l < len; l++) {
                mat[len + k][l] = mat[k][l];
                mat[k][len + l] = mat[k][l];
                mat[len + k][len + l] = mat[k][l] ^ 1;
            }
    }
    
    for (int i = 0; i < 1 << K; i++, puts(""))
        for (int j = 0; j < 1 << K; j++)
            printf("%c", "*+"[mat[i][j]]);
            
    return 0;
}