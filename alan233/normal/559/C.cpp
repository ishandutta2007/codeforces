// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

template<class T1,class T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<class T1,class T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}

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

const int N=200005;
const int mod=1e9+7;

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return res;
}
int fac[N],ifac[N];
void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n]);per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}
inline int C(int n,int m){
    return n<m||m<0?0:1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}

pii a[2005];int H,W,n;
int dp[2005];

int main(){
    init(2e5);
    H=read(),W=read(),n=read();
    rep(i,1,n)a[i].fir=read(),a[i].sec=read();
    sort(a+1,a+n+1);
    int ans=C(H-1+W-1,W-1);
    rep(i,1,n){
        dp[i]=C(a[i].fir-1+a[i].sec-1,a[i].sec-1);
        rep(j,1,i-1){
            if(a[j].fir<=a[i].fir&&a[j].sec<=a[i].sec){
                // printf("IN!\n");
                dp[i]=(dp[i]+mod-1ll*dp[j]*C(a[i].sec-a[j].sec+a[i].fir-a[j].fir,a[i].fir-a[j].fir)%mod)%mod;
            }
        }
        // printf("a[%d]=(%d,%d),dp[%d]=%d\n",i,a[i].fir,a[i].sec,i,dp[i]);
        ans=(ans+mod-1ll*dp[i]*C(H-a[i].fir+W-a[i].sec,W-a[i].sec)%mod)%mod;
    }
    print(ans,'\n');
    return 0;
}