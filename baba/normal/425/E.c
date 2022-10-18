#include<stdio.h>
#define M 510
#define ll long long int
ll mod=1000000007;
ll f[M][M];
ll pp[1000000];
ll ans;
int n,k;
void prepare(){
    ll cnt;
    int i,j;
    pp[0]=1;
    for(i=1;i<1000000;i++)pp[i]=(pp[i-1]*2)%mod;
    for(i=0;i<=500;i++)f[i][0]=1;
    for(n=1;n<=500;n++)for(k=1;k<=n;k++){
        for(j=k;j<=n;j++){
            cnt=(pp[j*(n-j+1)]-pp[(j-1)*(n-j+1)]+mod)%mod;
            cnt=(f[j-1][k-1]*cnt)%mod;
            f[n][k]=(f[n][k]+cnt);
        }
        f[n][k]%=mod;
    }
}
int main(){
    int i,j;
    prepare();
    scanf("%d %d",&n,&k);
    printf("%lld\n",f[n][k]);
    return 0;
}