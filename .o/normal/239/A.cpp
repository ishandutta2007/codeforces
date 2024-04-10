#include<stdio.h>

int Y, K, N;

int main(){
    bool ck = 0;
    scanf("%d%d%d",&Y,&K,&N);
    for(int X = K - Y % K; X + Y <= N; X += K){
        printf("%d ",X); ck = 1;
    }
    if(!ck) puts("-1");
    return 0;
}