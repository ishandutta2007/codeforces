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

const int N=5005;

int n,S,E;
ll x[N],a[N],b[N],c[N],d[N];
ll dp[N][N];

int main(){
    n=read(),S=read(),E=read();
    rep(i,1,n)x[i]=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n)b[i]=read();
    rep(i,1,n)c[i]=read();
    rep(i,1,n)d[i]=read();
    memset(dp,0x3f,sizeof(dp));
    if(S==1)dp[1][1]=-x[1]+d[1];
    else if(E==1)dp[1][1]=-x[1]+b[1];
    else dp[1][1]=-x[1]+d[1]-x[1]+b[1];
    rep(i,2,n){
        rep(j,1,i){
            if(i==S){
                // 
                ckmin(dp[i][j],dp[i-1][j]+x[i]+c[i]);
                // 
                ckmin(dp[i][j+1],dp[i-1][j]-x[i]+d[i]);
            }else if(i==E){
                // 
                ckmin(dp[i][j],dp[i-1][j]+x[i]+a[i]);
                // 
                ckmin(dp[i][j+1],dp[i-1][j]-x[i]+b[i]);
            }else{
                if(j>=(i>S)+(i>E)){
                    // 
                    if(j-(i>S))ckmin(dp[i][j],dp[i-1][j]+b[i]+c[i]);
                    // 
                    if(j-(i>E))ckmin(dp[i][j],dp[i-1][j]+d[i]+a[i]);
                    // 
                    ckmin(dp[i][j+1],dp[i-1][j]-x[i]+d[i]-x[i]+b[i]);
                    // 
                    if(j>1)ckmin(dp[i][j-1],dp[i-1][j]+x[i]+c[i]+x[i]+a[i]);
                }
            }
        }
    }
    // printf("%lld\n",dp[1][1]);
    // printf("%lld\n",dp[2][2]);
    // printf("%lld\n",dp[3][2]);
    // printf("%lld\n",dp[4][2]);
    // printf("%lld\n",dp[5][3]);
    // printf("%lld\n",dp[6][2]);
    print(dp[n][1],'\n');
    return 0;
}