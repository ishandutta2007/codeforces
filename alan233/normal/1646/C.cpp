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

ll fac[15],n;

ll calc(ll x){return x?__builtin_popcountll(x):0;}

void solve(){
    n=read();
    ll ans=1e18;
    rep(st,0,1<<14){
        ll nn=n;
        rep(i,0,13)if(st>>i&1)nn-=fac[i+1];
        if(nn<0)continue;
        ans=min(ans,calc(st)+calc(nn));
    }
    print(ans,'\n');
}

int main(){
    fac[0]=1;rep(i,1,14)fac[i]=fac[i-1]*i;
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}