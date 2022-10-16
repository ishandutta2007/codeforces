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

// h[i] * d[i] * num > H[i] * D[i]

ll dp[1000005];
pair<ll,ll> a[300005];
int n,C,m;

int main(){
    n=read(),C=read();
    rep(i,1,n){
        ll k1=read(),k2=read(),k3=read();
        a[i]={k1,k2*k3};
    }
    sort(a+1,a+n+1);
    rep(i,1,n){
        int j=i;
        while(j<n&&a[j+1].fir==a[i].fir)j++;
        ll k1=a[j].fir,k2=a[j].sec;
        for(int t=0;t<=C;t+=k1)
            ckmax(dp[t],t/k1*k2);
        i=j;
    }
    rep(i,1,C)ckmax(dp[i],dp[i-1]);
    m=read();
    while(m--){
        ll k1=read(),k2=read();
        k1*=k2;
        int pos=upper_bound(dp,dp+C+1,k1)-dp;
        print(pos==C+1?-1:pos,' ');
    }
    return 0;
}