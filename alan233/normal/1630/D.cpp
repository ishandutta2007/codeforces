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

const int N=1000005;

int n,m,a[N],g;

ll sol(int opt){
    ll tot=0;
    rep(t,1,g){
        ll sum=0,flg=0,mn=INT_MAX;
        for(int i=t;i<=n;i+=g){
            if(a[i]<0)flg^=1,sum-=a[i];
            else sum+=a[i];
            ckmin(mn,abs(a[i]));
        }
        if(flg!=opt)sum-=2*mn;
        tot+=sum;
    }
    return tot;
}

void solve(){
    n=read(),m=read();
    rep(i,1,n)a[i]=read();
    g=0;
    rep(i,1,m)g=__gcd(g,read());
    print(max(sol(0),sol(1)),'\n');
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}