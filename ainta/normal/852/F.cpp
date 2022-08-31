#include<cstdio>
#include<algorithm>
using namespace std;
int N, M, a, Q, mod, F[1010000], InvF[1010000], Res[1010000];
int Pow(int a, int b, int Mod){
    int r = 1;
    while(b){
        if(b&1)r=1ll*r*a%Mod;
        a=1ll*a*a%Mod;b>>=1;
    }
    return r;
}
int Comb(int a, int b){
    return 1ll*F[a]*InvF[b]%mod*InvF[a-b]%mod;
}
int main(){
    scanf("%d%d%d%d",&N,&M,&a,&Q);
    int t = 1, i;
    for(i=1;;i++){
        t=1ll*t*a%Q;
        if(t==1)break;
    }
    mod = i;
    F[0]=1;
    for(i=1;i<=M;i++)F[i]=1ll*F[i-1]*i%mod;
    InvF[M] = Pow(F[M], mod-2, mod);
    for(i=M-1;i>=0;i--)InvF[i] = 1ll*InvF[i+1]*(i+1)%mod;
    int s = 0;
    for(i=0;i<N;i++){
        if(i<=M)s = (s + Comb(M,min(M,i)))%mod;
        Res[N-i] = s;
    }
    for(i=1;i<=N;i++){
        printf("%d ",Pow(a, Res[i], Q));
    }
}