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
const int inf=2e9;

int a[N],n,d;

int qwq[N],pre[N],suf[N];
int p2[N],s2[N];
bool check(int x){
    rep(i,1,n)qwq[i]=a[i]-a[i-1]-1;
    pre[0]=inf;
    p2[0]=0;
    rep(i,1,n)pre[i]=min(pre[i-1],qwq[i]),p2[i]=max(p2[i-1],qwq[i]);
    suf[n+1]=suf[n+2]=inf;
    s2[n+1]=s2[n+2]=0;
    per(i,n,1)suf[i]=min(suf[i+1],qwq[i]),s2[i]=max(s2[i+1],qwq[i]);
    rep(i,1,n){ // move i
        if(min(pre[i-1],suf[i+2])<x)continue;
        if(i==n){
            if(a[i-1]+x+1<=d)return true;
            int t=p2[i-1];
            if(2*x+1<=t)return true;
            continue;
        }
        if(a[i+1]-a[i-1]-1<x)continue;
        int t=a[i+1]-a[i-1]-1;
        if(2*x+1<=t)return true;
        t=max(p2[i-1],s2[i+2]);
        if(2*x+1<=t)return true;
        if(a[n]+x+1<=d)return true;
    }
    return false;
}

void solve(){
    n=read(),d=read();
    rep(i,1,n)a[i]=read();
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r+1>>1;
        // printf("l=%d,r=%d\n",l,r);
        if(check(mid))l=mid;
        else r=mid-1;
    }
    print(l,'\n');
    return;
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}