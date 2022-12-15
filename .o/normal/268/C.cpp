#include <stdio.h>

int N, M, K;

int main(){
    scanf("%d%d", &N, &M);
    if(N < M){
        K = N + 1; printf("%d\n", N+1);
        for(int i = M, c = 0; i >= M - N; i--, c++){
            printf("%d %d\n",c,i);
        }
    }else{
        K = M + 1;printf("%d\n", M+1);
        for(int i = N, c = 0; i >= N - M; i--, c++){
            printf("%d %d\n",i,c);
        }
    }
    return 0;
}