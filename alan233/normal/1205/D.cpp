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

const int N=1005;

vector<int>adj[N];
int n;

int dep[N],sz[N],maxp[N],rt;
void getrt(int u,int fa){
    dep[u]=dep[fa]+1,sz[u]=1;
    for(auto v:adj[u]){
        if(v==fa)continue;
        getrt(v,u),sz[u]+=sz[v];
        ckmax(maxp[u],sz[v]);
    }
    ckmax(maxp[u],n-sz[u]);
    if(maxp[u]<maxp[rt])rt=u;
}
void dfs1(int u,int fa){
    sz[u]=1;
    for(auto v:adj[u]){
        if(v==fa)continue;
        dfs1(v,u),sz[u]+=sz[v];
    }
}

int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

queue<int>q;
int ans[N],jb[N];
void dfs2(int u,int fa){
    // printf("dfs2 u=%d,ans[fa]=%d,front=%d\n",u,ans[fa],q.front());
    jb[u]=q.front(),ans[u]=q.front()-jb[fa],q.pop();
    printf("%d %d %d\n",fa,u,ans[u]);
    for(auto v:adj[u]){
        if(v==fa)continue;
        dfs2(v,u);
    }
}

int main(){
    n=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    if(n==1)return 0;
    if(n==2)return puts("1 2 1"),0;
    maxp[rt=0]=1e9;
    getrt(1,0);
    dfs1(rt,0);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    for(auto u:adj[rt])pq.push({sz[u],u}),f[u]=u;
    while(SZ(pq)>2){
        auto [sz1,u]=pq.top();pq.pop();
        auto [sz2,v]=pq.top();pq.pop();
        f[find(u)]=find(v),pq.push({sz1+sz2,find(v)});
    }
    auto [A,u]=pq.top();pq.pop();assert(u==find(u));
    auto [B,v]=pq.top();pq.pop();assert(v==find(v));

    // fprintf(stderr,"rt=%d,A=%d,u=%d,B=%d,v=%d\n",rt,A,u,B,v);

    for(int i=1;i<=A;i++)q.push(i);
    for(auto node:adj[rt])if(find(node)==u)dfs2(node,rt);
    for(int i=1;i<=B;i++)q.push((A+1)*i);
    for(auto node:adj[rt])if(find(node)==v)dfs2(node,rt);
    return 0;
}