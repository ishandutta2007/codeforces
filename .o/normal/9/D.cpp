#include<stdio.h>

const int N_ = 40;
typedef unsigned long long llu;

int N, H;
llu T[N_][N_];
llu res;

int main() {
    int i, j;
    
    scanf("%d%d", &N, &H);
    
    T[0][0] = 1;
    for(i = 1; i <= N; i++){
        for(j = 1; j <= i; j++){
            for(int r = 1; r <= i; r++){
                llu sum;
                
                sum = 0;
                for(int k = 0; k <= j - 1; k++) sum += T[i - r][k];
                T[i][j] += sum * T[r - 1][j - 1];
                
                sum = 0;
                for(int k = 0; k <= j - 2; k++) sum += T[r - 1][k];
                T[i][j] += sum * T[i - r][j - 1];
            }
            
        }
    }
    
    for(i = H; i <= N; i++) res += T[N][i];
    
    printf("%llu\n",res);
    return 0;
}