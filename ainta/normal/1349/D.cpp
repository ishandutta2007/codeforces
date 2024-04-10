#include<cstdio>
#include<algorithm>
using namespace std;
long long Mod = 998244353;
long long Pow(long long a, long long b){
    long long r=1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;b>>=1;
    }
    return r;
}
long long Inv(long long a){
    a%=Mod;
    while(a<0)a+=Mod;
    return Pow(a,Mod-2);
}
int n, S, w[101000];
long long D[301000], C[301000];
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        S+=w[i];
    }
    long long invS = Inv(S);
    long long invNN = Inv(n-1);
    for(i=0;i<S;i++){
        long long X = invS*i%Mod;
        long long pt = invS*(S-i)%Mod;
        long long Z = pt*invNN%Mod;
        if(i==0){
            D[1] = Inv(Z);
        }
        else{
            D[i+1] = (D[i]*X+1)%Mod*Inv(Z)%Mod;
        }
    }
    long long s=0;
    for(i=S;i>=1;i--){
        s+=D[i];
        C[i-1]=s%Mod;
    }
    long long res=0;
    for(i=1;i<=n;i++)res+=C[w[i]];
    for(i=1;i<n;i++)res+=Mod-C[0];
    res%=Mod;
    res=res*Inv(n)%Mod;
    printf("%lld\n",res);
}