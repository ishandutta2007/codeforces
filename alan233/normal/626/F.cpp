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

const int mod=1e9+7;

inline void add(int &x,int y){
    if((x+=y)>=mod)x-=mod;
}

int f[205][205][1005];
int a[205],n,K;

int main(){
    n=read(),K=read();rep(i,1,n)a[i]=read();
    sort(a+1,a+n+1);
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        int d=a[i]-a[i-1];
        for(int j=0;j<=i;j++){
            for(int k=0;k<=K;k++){
                if(k-d*j>=0)add(f[i][j][k],1ll*(j+1)*f[i-1][j][k-d*j]%mod);
                if(k-d*(j+1)>=0)add(f[i][j][k],1ll*(j+1)*f[i-1][j+1][k-d*(j+1)]%mod);
                if(j&&k-d*(j-1)>=0)add(f[i][j][k],f[i-1][j-1][k-d*(j-1)]%mod);
            }
        }
    }
    int ans=0;
    for(int k=0;k<=K;k++)add(ans,f[n][0][k]);
    print(ans,'\n');
    return 0;
}