#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, H;
long long s1, s2, Mod = 1000000007, F[201000], InvF[201000];
long long Get(int a, int b){
    if(b==0){
        if(a==0)return 1;
        return 0;
    }
    return F[a+b-1]*InvF[a]%Mod*InvF[b-1]%Mod;
}
long long Calc(int a, int b, int h){
    if(a==0 && b==0)return 0;
    if(1ll*h*b>m)return 0;
    return Get(n-a,a) * Get(m-h*b,b) % Mod;
}
long long Pow(long long a, long long b){
    long long r = 1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;b/=2;
    }
    return r;
}
int main(){
    int i;
    scanf("%d%d%d",&n,&m,&H);
    F[0]=InvF[0]=1;
    for(i=1;i<=200000;i++){
        F[i]=F[i-1]*i%Mod;
        InvF[i] = Pow(F[i], Mod-2);
    }
    for(i=0;i<=n && i<=m;i++){
        s1 += Calc(i,i,1) * 2;
        s1 += Calc(i+1,i,1);
        s1 += Calc(i,i+1,1);
        s2 += Calc(i,i,H+1) * 2;
        s2 += Calc(i+1,i,H+1);
        s2 += Calc(i,i+1,H+1);
    }
    s1%=Mod, s2%=Mod;
    printf("%lld\n",s2 * Pow(s1,Mod-2)%Mod);
}