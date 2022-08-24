#include<stdio.h>
int n, K;
long long Res;
int main(){
    int i;
    scanf("%d%d",&n,&K);
    if(K>=n/2)printf("%lld\n",(long long)n*(n-1)/2);
    else{
        for(i=1;i<=K;i++){
            Res += 1 + (n-i*2)*2;
        }
        printf("%lld\n",Res);
    }
}