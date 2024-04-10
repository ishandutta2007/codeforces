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

template<class T1,class T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<class T1,class T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}

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
  
  void add(int u, int v, int cap) {
    int id = SZ(edge);
    edge.pb({u, v, cap});
    adj[u].pb(id);
  }
  void addedge(int u, int v, int cap) {
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
        if (!go) dep[v] = -FLOWinf;
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
};

const int N=50005;

vector<int>inz[N];
int n,a[N],pos[N];

void solve(){
    n=read();rep(i,1,n)a[i]=read(),pos[a[i]]=i;
    FLOW<int> flow(4*n+3);
    int S=4*n+1,T=4*n+2;
    rep(i,1,n){
        flow.addedge(S,4*i-3,1);
        flow.addedge(4*i-2,4*i-1,1);
        flow.addedge(4*i,T,1);
    }
    rep(i,1,n){
        for(auto it:inz[a[i]]){
            if(!pos[it])continue;
            int j=pos[it];
            flow.addedge(4*i-3,4*j-2,1);
            flow.addedge(4*i-1,4*j,1);
        }
    }
    print(flow.Dinic(S,T),'\n');
    rep(i,1,n)pos[a[i]]=0;
}

int main(){
    rep(i,1,50000){
        for(int j=2*i;j<=50000;j+=i)
            inz[j].pb(i);
    }
    int T=read();
    while(T--)solve();
    return 0;
}