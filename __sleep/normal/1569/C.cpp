#include<cstdio>
#include<algorithm>
using namespace std;
const int P=998244353;
int t,n,a[200005];
long long fact[200005];
int qpow(long long a,int b){
    long long ans=1;
    for(;b;b>>=1){
        if(b&1) ans=ans*a%P;
        a=a*a%P;
    }
    return ans;
}
int main(){
    fact[0]=1;
    for(int i=1;i<=200000;i++)
        fact[i]=fact[i-1]*i%P;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        sort(a+1,a+n+1);
        if(a[n]-a[n-1]>1){
            puts("0");
            continue;
        }
        if(a[n]==a[n-1]){
            printf("%lld\n",fact[n]);
            continue;
        }
        int l=0,num; a[0]=-1;
        for(l=n-1;a[l]==a[n]-1;--l);
        num=n-1-l;
        printf("%lld\n",fact[n]*num%P*qpow(num+1,P-2)%P);
    }
    return 0;
}