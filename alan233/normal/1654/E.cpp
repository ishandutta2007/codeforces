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

const int N=100005;

int cnt[100005+700*100000];
int a[N],n,ans;

void sol(){
    for(int d=0;d<=600;d++){
        int res=0;
        rep(i,1,n){
            ckmax(res,++cnt[a[i]-d*i+70000000]);
        }
        rep(i,1,n){
            --cnt[a[i]-d*i+70000000];
        }
        ckmax(ans,res);
    }
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=i-1;j>=max(1,i-600);j--){
            if(a[j]<a[i]&&(a[i]-a[j])%(i-j)==0){
                ckmax(res,++cnt[(a[i]-a[j])/(i-j)]);
            }
        }
        for(int j=i-1;j>=max(1,i-600);j--){
            if(a[j]<a[i]&&(a[i]-a[j])%(i-j)==0){
                --cnt[(a[i]-a[j])/(i-j)];
            }
        }
        ckmax(ans,res+1);
    }
}

int main(){
    n=read();
    rep(i,1,n)a[i]=read();
    sol();
    rep(i,1,n)a[i]=100001-a[i];
    sol();
    print(n-ans,'\n');
}