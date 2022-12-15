#include <stdio.h>
#include <string.h>

const int N_ = 1005;

int N, M, X, Y;
int Cst[N_];
char str[N_];

int A[N_], B[N_];
// A -  #, B -  .

int min (int a, int b){
    return a < b ? a : b;
}

int main(){
    int i, j, sum;
    
    scanf("%d%d%d%d", &M, &N, &X, &Y);
    for(i = 1; i <= M; i++){
        scanf("%s", str + 1);
        for(j = 1; j <= N; j++){
            if(str[j] == '.') ++Cst[j];
        }
    }
    
    for(i = 1; i <= N; i++){
        sum = 0; A[i] = 987654321;
        for(j = 0; j < i && j < Y; j++){
            sum += Cst[i - j];
            if(j >= X - 1) A[i] = min(A[i], B[i - j - 1] + sum);
        }
        
        sum = 0; B[i] = 987654321;
        for(j = 0; j < i && j < Y; j++){
            sum += M - Cst[i - j];
            if(j >= X - 1) B[i] = min(B[i], A[i - j - 1] + sum);
        }
    }
    
    printf("%d\n", min(A[N], B[N]));
    return 0;
}