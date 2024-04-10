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

const int mod=1e9+7;

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return res;
}

int a[1<<20],n,lim;

void FMT(int *a){
    rep(i,0,19)
        rep(j,0,lim-1)
            if(j>>i&1)
                a[j^1<<i]+=a[j];
}

int main(){
    n=read(),lim=1<<20;
    rep(i,1,n)a[read()]++;
    FMT(a);
    int ans=0;
    rep(i,0,lim-1){
        int coef=qpow(2,a[i]);
        if(i&&(__builtin_popcount(i)&1))ans=(ans+mod-coef)%mod;
        else ans=(ans+coef)%mod;
    }
    print(ans,'\n');
}