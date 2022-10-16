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

const int N=200005;

int a[N],n;
ll S;
int b[N];

void solve(){
    S=0;
    n=read();rep(i,1,n)a[i]=read(),S+=a[i];
    S/=n,S=n-S;
    int ptr=n+1;
    b[n+1]=1;
    // printf("S=%d\n",S);
    per(i,n,1){
        if(i<=S){
            ptr--;
            while(ptr>i&&b[ptr])ptr--;
        }
        if(ptr==i)b[i]=0;
        else if(ptr-i==a[i])b[i]=0;
        else b[i]=1;
    }
    b[1]=a[1]?1:0;
    rep(i,1,n)
        print(b[i]," \n"[i==n]);
}

int main(){
    int T=read();while(T--)solve();
    return 0;
}