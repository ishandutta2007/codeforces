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

double p[18][18],dp[1<<18];
int n;

double DP(int states){
    if(states==1)return 1.;
    if(dp[states]>=0.)return dp[states];
    double res=0.;
    rep(i,0,n-1)if(states>>i&1){
        rep(j,i+1,n-1)if(states>>j&1){
            ckmax(res,p[i][j]*DP(states^1<<j)+p[j][i]*DP(states^1<<i));
        }
    }
    return dp[states]=res;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    rep(i,0,n-1)rep(j,0,n-1)cin>>p[i][j];
    printf("%.10f\n",DP((1<<n)-1));
    return 0;
}