#include<cstdio>
int t,n,k;
const int P=1000000007;
long long f[200005];
inline long long qpow(long long a,long long b){
    long long ans=1;
    for(;b;b>>=1){
        if(b&1) ans=ans*a%P;
        a=a*a%P;
    } 
    return ans;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        if(n&1){
            long long ans=qpow(qpow(2,n-1)+1,k);
            printf("%lld\n",ans);
        }
        else{
            f[0]=1;
            long long p=qpow(2,n),q=qpow(2,n-1)-1;
            for(int i=1;i<=k;i++)
                f[i]=(q*f[i-1]+qpow(p,i-1))%P;
            printf("%lld\n",f[k]);
        }
    }
    return 0;
}