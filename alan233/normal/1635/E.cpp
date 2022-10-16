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

const int N=200005;

vector<int> adj[N],G[N];
bool vis[N];
int n,m;
int ans[N];

void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]){
            if(ans[v]!=(ans[u]^1)){
                puts("NO");
                exit(0);
            }
        }else{
            ans[v]=ans[u]^1;
            dfs(v);
        }
    }
}

int typ[N],loc[N],deg[N];

int main(){
    n=read(),m=read();
    vector<array<int,3>> fuck;
    rep(i,1,m){
        int type=read()-1;
        int x=read(),y=read();
        fuck.pb({x,y,type});
        adj[x].pb(y),adj[y].pb(x);
    }
    rep(i,1,n){
        if(!vis[i])dfs(i);
    }
    // rep(i,1,n){
    //     printf("ans[%d]=%d\n",i,ans[i]);
    // }
    for(auto [x,y,type]:fuck){
        if(type==0){
            if(!ans[x])G[x].pb(y),deg[y]++;
            else G[y].pb(x),deg[x]++;
        }else{
            if(!ans[x])G[y].pb(x),deg[x]++;
            else G[x].pb(y),deg[y]++;
        }
    }
    queue<int> q;
    int pos=0,ok=0;
    rep(i,1,n)if(!deg[i])q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        loc[u]=++pos,ok++;
        for(auto v:G[u])if(--deg[v]==0)q.push(v);
    }
    if(ok!=n)return puts("NO"),0;
    puts("YES");
    rep(i,1,n){
        putchar(!ans[i]?'L':'R');
        printf(" %d\n",loc[i]);
    }
    return 0;
}