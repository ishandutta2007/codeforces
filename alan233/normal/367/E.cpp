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

const int mod=1e9+7;

inline void add(int &x,int y){
    if((x+=y)>=mod)x-=mod;
}

int n,m,X;

int main(){
    n=read(),m=read(),X=read();
    if(n>m)return puts("0"),0;
    vector dp(m+1,vector(n+2,vector<int>(n+2,0)));
    dp[0][0][0]=1;
    rep(i,1,m){
        rep(j,0,min(i,n)){
            rep(k,j,min(i,n)){
                if(i==X){
                    if(!j)add(dp[i][j][k+1],dp[i-1][j][k]);
                    add(dp[i][j+1][k+1],dp[i-1][j][k]);

                    if(j)add(dp[i][j][k+1],dp[i-1][j][k]);
                }else{
                    if(!j)add(dp[i][j][k+1],dp[i-1][j][k]);
                    add(dp[i][j+1][k+1],dp[i-1][j][k]);

                    if(j)add(dp[i][j-1][k],dp[i-1][j][k]);
                    add(dp[i][j][k],dp[i-1][j][k]);

                    if(j)add(dp[i][j][k+1],dp[i-1][j][k]);
                }
            }
        }
    }
    int ans=dp[m][0][n];
    rep(i,1,n)ans=1ll*ans*i%mod;
    print(ans,'\n');
    return 0;
}