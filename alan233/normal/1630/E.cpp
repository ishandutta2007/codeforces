// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const int N=1000005;
const int mod=998244353;

int fac[N],ifac[N];
inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return res;
}
void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n]);per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}

int ans1[N],ans2[N];
int a[N],cnt[N],g,n;

void solve(){
    n=read();

    bool same=1;
    rep(i,1,n)a[i]=read(),same&=a[i]==a[1];
    if(same)return puts("1"),void();

    memset(cnt,0,4*(n+1));
    memset(ans1,0,4*(n+1));
    memset(ans2,0,4*(n+1));

    rep(i,1,n)cnt[a[i]]++;
    g=n;vector<int>qwq;
    rep(i,1,n)if(cnt[i])qwq.pb(cnt[i]),g=__gcd(g,cnt[i]);
    rep(i,1,g)if(g%i==0){ // 
        int sum=0,ways=fac[n/i];
        for(auto it:qwq){
            ways=1ll*ways*ifac[it/i]%mod;
            if(it/i>=2)sum=(sum+1ll*(it/i)*(it/i-1))%mod;
        }
        sum=1ll*sum*ways%mod*qpow(n/i)%mod*qpow(n/i-1)%mod;
        sum=(mod+ways-sum)%mod;
        ans1[i]=1ll*sum*n%mod;
        ans2[i]=ways;
        // printf("ans1[%d]=%d,ans2[%d]=%d\n",i,ans1[i],i,ans2[i]);
    }
    int ANS1=0,ANS2=0;
    rep(i,1,n){
        int t=n/__gcd(i,n);
        ANS1=(ANS1+ans1[t])%mod,ANS2=(ANS2+ans2[t])%mod;
    }
    print(1ll*ANS1*qpow(ANS2)%mod,'\n');
}

int main(){
    init(1e6);
    int T=read();
    while(T--)solve();
    return 0;
}