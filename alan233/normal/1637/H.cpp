// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

const int N=500005;

int p[N],q[N],n;

struct Fen{
    int c[N];
    void clr(int n){memset(c,0,4*(n+1));}
    void add(int x,int dlt){
        while(x)c[x]+=dlt,x^=x&-x;
    }
    int qry(int x){
        int ans=0;
        while(x<=n)ans+=c[x],x+=x&-x;
        return ans;
    }
}tr;

void solve(){
    n=read(),tr.clr(n);
    rep(i,1,n)p[i]=read(),q[p[i]]=i;
    ll res=0;
    vector<ll> zz;
    rep(i,1,n){
        res+=tr.qry(p[i]),tr.add(p[i],1);
        zz.pb(2*i-q[i]);
    }
    sort(zz.begin(),zz.end());
    rep(i,0,n){
        if(i)res+=zz[i-1]-i;
        print(res," \n"[i==n]);
    }
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}