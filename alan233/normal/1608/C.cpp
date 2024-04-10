#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
inline int read(){
    int x=0;char ch=getchar();
    int f=0;
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char let){
    print(x),putchar(let);
}
template<typename T1,typename T2>void ckmin(T1&x,T2 y){
    if(x>y)x=y;
}

const int N=200005;

int comp,dtot,dfn[N],low[N];
vector<int>adj[N];
int n,m;

int a[N],b[N],ida[N],idb[N];
stack<int>stk;
int instack[N],be[N];
void tarjan(int u){
    stk.push(u),dfn[u]=low[u]=++dtot;instack[u]=1;
    for(auto v:adj[u]){
        if(!dfn[v]){
            tarjan(v);
            ckmin(low[u],low[v]);
        }else if(instack[v]){
            ckmin(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int y;++comp;
        while(y=stk.top()){
            instack[y]=0;stk.pop();
            be[y]=comp;
            if(y==u)break;
        }
    }
}
void solve(){
    comp=0;
    n=read();
    rep(i,1,n)dfn[i]=low[i]=be[i]=0;dtot=0;
    rep(i,1,n)a[i]=read();rep(i,1,n)b[i]=read();
    iota(ida+1,ida+n+1,1);iota(idb+1,idb+n+1,1);
    sort(ida+1,ida+n+1,[&](int x,int y){return a[x]<a[y];});
    sort(idb+1,idb+n+1,[&](int x,int y){return b[x]<b[y];});
    rep(i,1,n)adj[i].clear();
    rep(i,2,n)adj[ida[i]].pb(ida[i-1]),adj[idb[i]].pb(idb[i-1]);
    rep(i,1,n)if(!dfn[i])tarjan(i);  
    rep(i,1,n)putchar(be[i]==comp?'1':'0');putchar('\n');
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}