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
const int B=555;
const int inf=1e9;

queue<int> q;
vector<int> adj[N],dp[N],zz[N];
int s[N],d[N],n;

int tag[N],type[B],itype[N],len;
bool vis[N];
void dfs1(int u,int fa){
    vis[u]=1;
    for(auto v:adj[u]){
        if(d[v]!=d[u]||v==fa)continue;
        for(int k=1;k<=len;k++)
            ckmin(dp[v][k],dp[u][k]+1);
        /*if(itype[d[v]])*/dp[v][itype[d[v]]]=1;
        dfs1(v,u);
    }
}
void dfs2(int u,int fa){
    vis[u]=1;
    for(auto v:adj[u]){
        if(d[v]!=d[u]||v==fa)continue;
        dfs2(v,u);
        for(int k=1;k<=len;k++)
            ckmin(dp[u][k],dp[v][k]+1);
        /*if(itype[d[u]])*/dp[u][itype[d[u]]]=1;
    }
}

int main(){
    n=read();
    rep(i,1,n){
        s[i]=read();
        if(s[i])q.push(i);
        else d[i]=inf;
    }
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:adj[u])
            if(d[v]>d[u]+1)
                d[v]=d[u]+1,q.push(v);
    }
    rep(i,1,n){
        zz[d[i]].pb(i);
        for(auto j:adj[i])
            if(d[i]==d[j])
                tag[d[i]]=1;
    }
    rep(i,0,n){
        if(tag[i])
            type[++len]=i,itype[i]=len;
    }
    rep(i,1,n)dp[i].resize(len+1,inf);
    rep(di,0,n){
        for(auto i:zz[di]){
            for(auto j:adj[i])
                if(d[j]==d[i]-1)
                    rep(k,1,len)
                        ckmin(dp[i][k],max(0,dp[j][k]-1));
        }
        for(auto i:zz[di]){
            if(!vis[i]){
                dfs1(i,0);
                dfs2(i,0);
                dfs1(i,0);
                dfs2(i,0);
            }
        }
    }
    rep(i,1,n){
        int ans=d[i];
        // printf("d[%d]=%d\n",i,d[i]);
        rep(j,1,len)
            if(dp[i][j]==0)
                ckmax(ans,2*d[i]-type[j]);
        print(ans," \n"[i==n]);
    }
    return 0;
}