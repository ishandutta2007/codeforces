// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
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
const int M=N;
const ll inf=1e18;

vector<int>adj[N];
ll a[N],b[N];
int n;

struct SMT{
    struct Func{
        ll k,b;
        ll eval(ll x){return k*x+b;}
    }tr[M];
    int ls[M],rs[M],tot;
    
    int bin[M],btot;
    int newnode(){
        int u=btot?bin[btot--]:++tot;
        // int u=++tot;
        ls[u]=rs[u]=0;
        return u;
    }
    void ins(int &u,int l,int r,Func f){
        if(!u){
            u=newnode(),tr[u]=f;
            return;
        }
        int mid=l+r>>1;
        if(f.eval(mid)<tr[u].eval(mid))swap(tr[u],f);
        if(l==r)return;
        if(f.k>tr[u].k)ins(ls[u],l,mid,f);
        else ins(rs[u],mid+1,r,f);
    }
    ll query(int u,int l,int r,int pos){
        if(!u)return inf;
        if(l==r)return tr[u].eval(pos);
        int mid=l+r>>1;
        if(pos<=mid)return min(query(ls[u],l,mid,pos),tr[u].eval(pos));
        else return min(query(rs[u],mid+1,r,pos),tr[u].eval(pos));
    }
    void merge(int &u,int v,int l,int r){
        if(!u||!v){
            u=u+v;
            return;
        }
        int mid=l+r>>1;
        ins(u,l,r,tr[v]);
        int lsv=ls[v],rsv=rs[v];
        bin[++btot]=v;
        merge(ls[u],lsv,l,mid);
        merge(rs[u],rsv,mid+1,r);
    }
}smt;

ll dp[N];
int rt[N],sz[N];

void dfs(int u,int fa){
    sz[u]=1;
    for(auto v:adj[u]){
        if(v==fa)continue;
        dfs(v,u);
        sz[u]+=sz[v];
        smt.merge(rt[u],rt[v],-100000,100000);
    }
    if(sz[u]>1)dp[u]=smt.query(rt[u],-100000,100000,a[u]);
    else dp[u]=0;
    smt.ins(rt[u],-100000,100000,{b[u],dp[u]});
}

int main(){
    n=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n)b[i]=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(1,0);
    rep(i,1,n)print(dp[i]," \n"[i==n]);
    return 0;
}