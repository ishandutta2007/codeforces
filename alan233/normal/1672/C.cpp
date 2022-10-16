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

const int N=200005;

int a[N],n;
int pre[N],suf[N];

void solve(){
    n=read();
    rep(i,1,n)a[i]=read();
    pre[0]=0;
    rep(i,1,n){
        pre[i]=pre[i-1];
        if(!pre[i]&&a[i]==a[i-1])
            pre[i]=i;
    }
    suf[n+1]=0,a[n+1]=0;
    per(i,n,1){
        suf[i]=suf[i+1];
        if(!suf[i]&&a[i]==a[i+1])
            suf[i]=i;
    }
    int _=0;
    rep(i,1,n-1)if(a[i]==a[i+1])_++;
    if(_<=1){
        puts("0");
        return;
    }
    int ans=1e9;
    rep(i,1,n-1){
        int L=i,R=i;
        if(pre[i-1])L=pre[i-1];
        if(suf[i+2])R=suf[i+2];
        ckmin(ans,R-L+1);
    }
    print(ans,'\n');
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}