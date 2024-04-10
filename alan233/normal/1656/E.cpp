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

vector<int> adj[100005];
int n;

int dep[100005];
void dfs1(int u,int fa){
    dep[u]=dep[fa]^1;
    for(auto v:adj[u])if(v!=fa)dfs1(v,u);
}

void solve(){
    n=read();rep(i,1,n)adj[i].clear();
    rep(i,1,n-1){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs1(1,0);
    rep(i,1,n)
        if(dep[i])printf("%d ",-SZ(adj[i]));
        else printf("%d ",SZ(adj[i]));
    puts("");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}