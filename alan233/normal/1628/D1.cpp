// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}

const int mod=1e9+7;
const int inv2=(mod+1)/2;

int dp[2005][2005];

int main(){
    dp[0][0]=0;
    rep(i,1,2000){
        dp[i][0]=0;
        dp[i][i]=i;
        rep(j,1,i-1){
            dp[i][j]=1ll*(dp[i-1][j-1]+dp[i-1][j])*inv2%mod;
        }
    }
    int T=read();
    while(T--){
        int n=read(),m=read(),k=read();
        print(1ll*dp[n][m]*k%mod,'\n');
    }
    return 0;
}