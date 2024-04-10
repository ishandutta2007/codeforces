#include<cstdio>
#include<algorithm>
using namespace std;
int n, K;
long long Mod = 998244353, F[601000], InvF[601000], Res;
long long Pow(long long a, long long b){
    long long r=1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;b>>=1;
    }
    return r;
}
int main(){
    int i;
    scanf("%d%d",&n,&K);
    F[0]=1;
    for(i=1;i<=n;i++)F[i]=F[i-1]*i%Mod;
    InvF[n]=Pow(F[n],Mod-2);
    for(i=n;i>=1;i--)InvF[i-1]=InvF[i]*i%Mod;
    for(i=1;i<=n;i++){
        long long z = n/i;
        if(z>=K){
            Res=(Res+F[z-1]*InvF[K-1]%Mod*InvF[z-K])%Mod;
        }
    }
    printf("%lld\n",Res);
}