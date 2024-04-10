#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#define N_ 35
int N, K;
int A[N_];
bool Chk[N_*N_];

int main(){
    int i, j;

    scanf("%d%d",&N,&K);
    for(i=1; i<=K; i++){
        scanf("%d",A+i);
        Chk[A[i]] = 1;
    }

    for(i=1; i<=K; i++){
        printf("%d ",A[i]);
        int cnt = 0;
        for(j=1; j<=N*K; j++) if(!Chk[j]){
            ++cnt; Chk[j] = 1;
            printf("%d ",j);
            if(cnt == N - 1) break;
        }
        puts("");
    }
    return 0;
}