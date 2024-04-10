// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}

const int mod=998244353;
const int N=12252240;

int dp[N],ans;
int n,a[N],x,y,k,M;

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}

int main(){
    cin>>n>>a[1]>>x>>y>>k>>M;
    int cf1=1ll*k*qpow(n)%mod;
    for(int i=1;i<=n;i++){
        if(i>1)a[i]=(1ll*a[i-1]*x+y)%M;
//        printf("a[%d]=%d\n",i,a[i]);
        int rem=a[i]%N;
        dp[rem]++;
        ans=(ans+1ll*(a[i]-rem)*cf1)%mod;
    }
//    cerr<<ans<<'\n';
    int cf2=1ll*(n-1)*qpow(n)%mod,cf3=qpow(n);
    for(int t=1;t<=k;t++){
        for(int i=0;i<N;i++){
//            if(dp[i])printf("%d\n",1ll*dp[i]*i%mod*qpow(n,k-1)%mod);
            ans=(ans+1ll*dp[i]*i%mod*cf3)%mod;
            int mem=dp[i];
            dp[i]=1ll*dp[i]*cf2%mod;
            dp[i-i%t]=(dp[i-i%t]+1ll*mem*cf3)%mod;
        }
//        cerr<<"ans="<<1ll*ans*n%mod<<'\n';
//        cerr<<1ll*ans*qpow(n,k)%mod<<'\n';
    }
    print(1ll*ans*qpow(n,k)%mod,'\n');
    return 0;
}