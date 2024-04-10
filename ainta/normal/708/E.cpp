#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, K;
long long Mod = 1000000007, p, np, D[1510][1510], S[1510][1510];
long long F[101000], InvF[101000], G[2010];
long long Pow(long long a, int b){
    long long r = 1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;
        b>>=1;
    }
    return r;
}
long long Comb(int a, int b){
    return F[a]*InvF[b]%Mod*InvF[a-b]%Mod;
}
int main(){
    int A, B, i, j;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&A,&B);
    scanf("%d",&K);
    F[0]=InvF[0]=1;
    for(i=1;i<=K;i++){
        F[i]=F[i-1]*i%Mod;
        InvF[i] = Pow(F[i],Mod-2);
    }
    p = A*Pow(B,Mod-2)%Mod;
    np = (B-A)*Pow(B,Mod-2)%Mod;
    D[0][m] = 1;
    for(i=0;i<=m;i++){
        if(i>K)G[i] = 0;
        else G[i] = Pow(p,i)*Pow(np,K-i)%Mod*Comb(K,i)%Mod;
    }
    for(i=0;i<=n;i++){
        for(j=1;j<=m;j++)S[i][j] = (S[i][j-1] + D[i][j])%Mod;
        if(i==n)break;
        long long S1 = 0, S2 = 0;
        for(j=1;j<=m;j++){
            S1 = (S1+G[j-1])%Mod;
            S2 = (S2+G[j-1]*S[i][j-1])%Mod;
            D[i+1][j] = ((S[i][m] - S[i][m-j] + Mod)%Mod * S1 - S2 + Mod) % Mod * G[m-j] % Mod;
        }
    }
    printf("%lld\n",S[n][m]);
}