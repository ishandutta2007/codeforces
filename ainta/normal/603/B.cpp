#include<stdio.h>
int UF[1010000];
long long Res, Mod = 1000000007;
bool v[1010000];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a]=Find(UF[a]);
}
int p, K;
int main(){
    int i, t, a, b;
    scanf("%d%d",&p,&K);
    if(K == 0){
        Res = 1;
        for(i=1;i<p;i++){
            Res = Res * p % Mod;
        }
        printf("%lld\n",Res);
        return 0;
    }
    for(i=0;i<p;i++)UF[i]=i;
    for(i=0;i<p;i++){
        t = (long long)i*K%p;
        a = Find(i), b = Find(t);
        if(a != b){
            UF[a] = b;
        }
    }
    Res = 1;
    for(i=0;i<p;i++){
        a = Find(i);
        if(!v[a] && a){
            v[a]=true;
            Res = Res * p % Mod;
        }
    }
    if(K == 1){
        Res = Res * p % Mod;
    }
    printf("%lld\n",Res);
}