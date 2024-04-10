#include<stdio.h>
long long D[26], S, Mod = 1000000007;
char p[1010000];
int pp[26], n, m, K;
int main(){
    int x, i, j, MM;
    scanf("%d%d",&n,&K);
    scanf("%s",p+1);
    for(i=1;p[i];i++){
        x = p[i]-'a';
        S = 1;
        for(j=0;j<K;j++){
            if(j!=x) S += D[j];
        }
        pp[x] = i;
        D[x] = (D[x]+S)%Mod;
    }
    m = i-1;
    for(i=m+1;i<=m+n;i++){
        MM = m+n+1;
        for(j=0;j<K;j++){
            if(MM>pp[j]){
                MM=pp[j];
                x = j;
            }
        }
        S = 1;
        for(j=0;j<K;j++){
            if(j!=x) S += D[j];
        }
        pp[x] = i;
        D[x] = (D[x]+S)%Mod;
    }
    S=1;
    for(i=0;i<K;i++)S=(S+D[i])%Mod;
    printf("%lld\n",S);
}