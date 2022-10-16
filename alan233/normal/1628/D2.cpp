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

const int N=1000005;
const int mod=1e9+7;
const int inv2=(mod+1)/2;

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return res;
}
int fac[N],ifac[N];
inline void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n]);per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}
inline int C(int n,int m){
    return n<m||m<0?0:1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}

int main(){
    init(N-5);
    int T=read();
    while(T--){
        int n=read(),m=read(),k=read();
        int ans=0;
        if(n==m){
            print(1ll*n*k%mod,'\n');
            continue;
        }
        rep(i,1,m){
            ans=(ans+1ll*C(n-i-1,m-i)*i%mod*qpow(inv2,n-i))%mod;
        }
        print(1ll*ans*k%mod,'\n');
    }
    return 0;
}