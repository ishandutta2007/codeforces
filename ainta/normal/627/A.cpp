#include<stdio.h>
long long s, x, t, g, Res;
int main(){
    int i;
    scanf("%lld%lld",&s,&x);
    if((s-x)%2!=0 || s<x){
        printf("0\n");
        return 0;
    }
    t = (s-x)/2;
    if(t&x){
        printf("0\n");
        return 0;
    }
    Res = 1;
    while(x){
        if(x%2)Res*=2;
        x/=2;
    }
    if(!t)Res-=2;
    printf("%lld\n",Res);
}