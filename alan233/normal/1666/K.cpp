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

const ll inf=1e18;

template<typename C>
class FLOW {
public:
  #define SZ(x) ((int)x.size())
  #define pb push_back
  const C FLOWinf = numeric_limits<C>::max() / 2;
  struct Edge {
    int from, to;
    C cap; 
  };
  vector<int> dep;
  vector<Edge> edge;
  vector<vector<int>> adj, pot;
  int n;
  
  explicit FLOW(int _n) {
    n = _n;
    dep.resize(_n);
    adj.resize(_n);
    pot.resize(_n);
    edge.resize(0);
  }
  
  void add(int u, int v, C cap) {
    int id = SZ(edge);
    edge.pb({u, v, cap});
    adj[u].pb(id);
  }
  void addedge(int u, int v, C cap) {
    add(u, v, cap), add(v, u, 0);
  }
  bool bfs(int S, int T) {
    for (int i = 0; i < n; i++) pot[i] = adj[i], dep[i] = 0;
    queue<int> q;
    dep[S] = 1, q.push(S);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto id: adj[u]) {
        int v = edge[id].to;
        C cap = edge[id].cap;
        if (!dep[v] && cap) {
          dep[v] = dep[u] + 1;
          if (v == T) return 1;
          q.push(v);
        } 
      }
    }
    return 0;
  }
  C dfs(int u, int T, C res) {
    if (u == T) return res;
    C over = 0;
    while (SZ(pot[u])) {
      int id = pot[u].back(); pot[u].pop_back();
      int v = edge[id].to;
      C cap = edge[id].cap;
      if (dep[v] == dep[u] + 1 && cap) {
        C go = dfs(v, T, min(res, cap));
        over += go, res -= go;
        edge[id].cap -= go, edge[id ^ 1].cap += go;
        if (!go) dep[v] = -1e9;
        if (!res) break;
      }
    }
    return over;
  }
  C Dinic(int S, int T) {
    C flow = 0;
    while (bfs(S, T)) flow += dfs(S, T, FLOWinf);
    return flow;
  }

    bool vis[5005];
    void dfs(int u){
        vis[u]=1;
        for(auto id:adj[u]){
            int v=edge[id].to,cap=edge[id].cap;
            if(cap&&!vis[v])
                dfs(v);
        }
    }
    void getcut(int S){
        for(int i=0;i<n;i++)vis[i]=0;
        dfs(S);
    }
};

int n,m,A,B;

int main(){
    n=read(),m=read(),A=read(),B=read();
    FLOW<ll> flow(2*n+3);
    int S=2*n+1,T=2*n+2;
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        flow.add(u,v+n,w),flow.add(v+n,u,w);
        flow.add(v,u+n,w),flow.add(u+n,v,w);
    }
    flow.addedge(S,A,inf),flow.addedge(S,B+n,inf);
    flow.addedge(B,T,inf),flow.addedge(A+n,T,inf);
    print(flow.Dinic(S,T),'\n');
    flow.getcut(S);
    for(int i=1;i<=n;i++){
        if(flow.vis[i]&&!flow.vis[i+n])putchar('A');
        else if(!flow.vis[i]&&flow.vis[i+n])putchar('B');
        else putchar('C');
    }
    return 0;
}