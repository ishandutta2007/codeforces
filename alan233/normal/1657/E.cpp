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

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline ll read(){
    ll x=0,f=0;char ch=getchar();
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

const int mod=998244353;

void add(int &x,int y){
    if((x+=y)>=mod)x-=mod;
}
int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return res;
}

int fac[255],ifac[255];
void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n]);per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}

int dp[255][255],n,K;

int main(){
    init(250);
    n=read()-1,K=read();
    dp[0][0]=1;
    rep(i,1,K){
        rep(j,0,n){
            rep(k,0,n-j){
                add(dp[i][j+k],1ll*dp[i-1][j]*ifac[k]%mod*qpow(K-i+1,j*k+k*(k-1)/2)%mod);
            }
        }
    }
    // printf("dp[1][0]=%d\n",dp[1][0]);
    // printf("dp[1][1]=%d\n",dp[1][1]);
    // printf("dp[1][2]=%d\n",dp[1][2]);
    print(1ll*dp[K][n]*fac[n]%mod,'\n');
    return 0;
}