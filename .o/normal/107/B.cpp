#include<stdio.h>
#include<string.h>
#include<math.h>

#define N_ 100
#define M_ 1000
int N, M, K;
int Sum, Wafa;
double res;

int main(){
    int i, j;

    scanf("%d%d%d",&N,&M,&K);
    for(i=1; i<=M; i++){
        scanf("%d",&j);
        if(i == K) Wafa = j; else Sum += j;
    }

    if(N == 1) res = 0;
    else if(Sum + Wafa < N) res = -1;
    else if(1 + Sum < N) res = 1;
    else{
        --Wafa;
        res = 1;
        for(i=0; i<N-1; i++) res *= (double)(Sum - i) / (Wafa + Sum - i);
        res = 1 - res;
    }

    printf("%.7lf\n",res);
    return 0;
}