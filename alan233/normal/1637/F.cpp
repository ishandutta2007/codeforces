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

vector<int> adj[N];
int h[N],n;

int f[N],son[N];ll ans;
void dfs1(int u,int fa){
    for(auto v:adj[u]){
        if(v==fa)continue;
        dfs1(v,u);
        if(f[v]>=f[son[u]])son[u]=v;
    }
    f[u]=max(f[son[u]],h[u]);
    if(fa){
        for(auto v:adj[u]){
            if(v==fa)continue;
            if(v!=son[u])ans+=f[v];
        }
    }else{
        if(SZ(adj[u])==1)ans+=2*f[u];
        else{
            vector<int> son;
            for(auto v:adj[u])son.pb(v);
            sort(son.begin(),son.end(),[&](int x,int y){
                return f[x]>f[y];
            });
            for(int i=2;i<SZ(son);i++)ans+=f[son[i]];
            ans+=2*f[u];
        }
    }
}

int main(){
    n=read();
    rep(i,1,n)h[i]=read();
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    int root=max_element(h+1,h+n+1)-h;
    dfs1(root,0);
    printf("%lld\n",ans);
    return 0;
}