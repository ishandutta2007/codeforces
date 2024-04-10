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

inline ll read(){
    ll x=0,f=0;char ch=getchar();
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

vector<int> adj[N];
int n;

// (/): pair()
pii dp[N][2];
pii operator + (pii a,pii b){
    return make_pair(a.fir+b.fir,a.sec+b.sec);
}
void dfs1(int u,int fa){
    dp[u][0]=make_pair(0,-1);
    dp[u][1]=make_pair(1,-SZ(adj[u]));
    for(auto v:adj[u]){
        if(v==fa)continue;
        dfs1(v,u);
        dp[u][0]=dp[u][0]+max(dp[v][0],dp[v][1]);
        dp[u][1]=dp[u][1]+dp[v][0];
    }
}
int ans[N];
void dfs2(int u,int fa,int type){
    if(type)ans[u]=1,type=0;// 
    else{
        if(dp[u][0]>=dp[u][1])ans[u]=1,type=0;
        else ans[u]=SZ(adj[u]),type=1;
    }
    for(auto v:adj[u]){
        if(v==fa)continue;
        dfs2(v,u,type);
    }
}

int main(){
    n=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    if(n==2){
        puts("2 2");
        puts("1 1");
        return 0;
    }
    dfs1(1,0);
    pii anss=max(dp[1][0],dp[1][1]);
    printf("%d %d\n",anss.fir,-anss.sec);
    dfs2(1,0,0);
    rep(i,1,n)
        printf("%d ",ans[i]);
    return 0;
}