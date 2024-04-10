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

const int N=300005;
const int inf=1e9;

ll sum[3][N];
int a[3][N],pre[3][N],n;

map<int,int> dp[N];
int S;

int DP(int x,int y){
    if(x<0||y<0)return -inf;
    if(x==0&&y==0)return 0;
    ++S;
    if(dp[x].count(y))return dp[x][y];
    int cur=0;
    if(pre[1][x]>pre[2][y])ckmax(cur,DP(pre[1][x],y)+1);
    else ckmax(cur,DP(x,pre[2][y])+1);
    ckmax(cur,DP(pre[0][min(x,y)],pre[0][min(x,y)])+1);
    // printf("dp[%d][%d]=%d\n",x,y,cur);
    // printf("pre[0][%d]=%d,pre[1][%d]=%d,pre[2][%d]=%d\n",min(x,y),pre[0][min(x,y)],x,pre[1][x],y,pre[2][y]);
    return dp[x][y]=cur;
}

int main(){
    n=read();
    rep(i,1,2)rep(j,1,n)a[i][j]=read();
    rep(i,1,n)a[0][i]=a[1][i]+a[2][i];
    rep(i,0,2){
        map<ll,int> mp;
        rep(j,0,n){
            pre[i][j]=-1;
            if(j)sum[i][j]=sum[i][j-1]+a[i][j];
            // printf("sum[%d][%d]=%lld\n",i,j,sum[i][j]);
            if(mp.count(sum[i][j]))pre[i][j]=mp[sum[i][j]];
            if(j)ckmax(pre[i][j],pre[i][j-1]);
            // printf("pre[%d][%d]=%d\n",i,j,pre[i][j]);
            mp[sum[i][j]]=j;
        }
    }
    print(DP(n,n),'\n');
    assert(S<=10000000);
    return 0;
}