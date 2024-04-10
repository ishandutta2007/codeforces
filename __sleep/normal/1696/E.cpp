#include<cstdio>
const int N=400005,P=1000000007;
int fact[N],inv[N];
typedef long long ll;
long long qpow(long long a,long long b){
    long long ans=1;
    for(;b;b>>=1){
        if(b&1) ans=ans*a%P;
        a=a*a%P;
    }
    return ans;
}
inline int C(int n,int m){
    // printf("# %d %d\n",n,m);
    if(m<0) return 0;
    return 1ll*fact[n]*inv[m]%P*inv[n-m]%P;
}
int main(){
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=1ll*fact[i-1]*i%P;
    inv[N-1]=qpow(fact[N-1],P-2);
    for(int i=N-2;i>=0;--i)
        inv[i]=inv[i+1]*(i+1ll)%P;
    int n,a;
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d",&a);
        ans=(ans+C(i+a,a-1))%P;
    }
    printf("%lld\n",ans%P);
    return 0;
}