#include<stdio.h>

int N, M, K;
int D[100005];
int C[100005];

int main(){
    int i, j;
    
    scanf("%d%d",&M,&K);
    int p = -1;
    for(i = 1; i <= M; i++){
        int d; scanf("%d",&d);
        if(p != d) D[++N] = d;
        p = d;
    }
    
    for(i = 1; i <= N; i++){
        if(i == 1 || i == N) C[D[i]]++;
        else C[D[i]] += (D[i-1] == D[i+1] ? 2 : 1);
    }
    
    int m = 0; C[0] = -2147483647;
    for(i = 1; i <= K; i++){
        if(C[m] < C[i]) m = i;
    }
    
    printf("%d\n",m);
    return 0;
}