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

const int mod=1e9+7;
const int N=200005;

inline void add(int &x,int y){
    if((x+=y)>=mod)x-=mod;
}

vector<int> adj[N];
int n,m,S,T;

int dis[N];
void bfs(int S){
    rep(i,1,n)dis[i]=-1;
    queue<int> q;
    q.push(S),dis[S]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:adj[u]){
            if(!~dis[v]){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}


int f[N][2],go[N][2];
void sol(int S){
    rep(i,1,n){
        f[i][0]=f[i][1]=0;
        go[i][0]=go[i][1]=-1;
    }
    queue<array<int,2>> q;
    q.push({S,0}),f[S][0]=1,go[S][0]=0;
    while(!q.empty()){
        auto [u,type]=q.front();q.pop();
        for(auto v:adj[u]){
            int new_type=dis[u]+type+1-dis[v];
            if(new_type>=2)continue;
            if(!~go[v][new_type]){
                go[v][new_type]=go[u][type]+1;
                q.push({v,new_type});
            }
            if(go[v][new_type]==go[u][type]+1){
                add(f[v][new_type],f[u][type]);
            }
        }
    }
}

void solve(){
    n=read(),m=read();
    S=read(),T=read();
    rep(i,1,n)adj[i].clear();
    rep(i,1,m){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    bfs(S);
    sol(S);
    print((f[T][0]+f[T][1])%mod,'\n');
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}