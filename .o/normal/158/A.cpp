#include<stdio.h>
#include<string.h>

int N, K;
int res, sc;

int main(){
    int i;

    scanf("%d%d",&N,&K);
    for(i=1; i<=N; i++){
        int d; scanf("%d",&d);
        if(i < K && d > 0) res ++;
        else if(i == K){ sc = d; if(d > 0) res++; }
        else if(d >= sc && d > 0) res++;
    }

    printf("%d\n",res);
    return 0;
}