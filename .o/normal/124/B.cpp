#include<stdio.h>
#include<string.h>
#include<algorithm>

#define N_ 10
#define K_ 15
int N, K;
char S[N_][K_];
int A[K_+1];
int res = 2147483647;

int main(){
    int i, j;

    scanf("%d%d",&N,&K);
    for(i=1; i<=N; i++) scanf("%s",S[i]+1);
    
    for(i=1; i<=K; i++) A[i] = i;
    while(1){
        int max = -1, min = 2147483647;
        for(i=1; i<=N; i++){
            int sum = 0;
            for(j=1; j<=K; j++) sum = sum * 10 + S[i][A[j]] - '0';
            if(sum > max) max = sum;
            if(sum < min) min = sum;
        }
        if(res > max - min) res = max - min;
        if(!std::next_permutation(A+1, A+K+1)) break;
    }

    printf("%d\n",res);
    return 0;
}