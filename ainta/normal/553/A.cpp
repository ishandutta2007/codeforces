#include<stdio.h>
int w[1010], n;
long long Res = 1, Mod=1000000007, C[1010][1010];
int main(){
    int i, j, S = 0;
    for(i=0;i<=1000;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        S+=w[i];
    }
    for(i=n;i>=1;i--){
        Res=Res*C[S-1][w[i]-1]%Mod;
        S-=w[i];
    }
    printf("%lld\n",Res);
}