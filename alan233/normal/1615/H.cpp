#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((long long)(x.size()))
#define pii pair<int,int>
#define poly vector<int>
#define int long long
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=3005;
const int inf=1e15;

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
        int v = edge[id].to, cap = edge[id].cap;
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
        int go = dfs(v, T, min(res, cap));
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
  
  vector<bool> inS;
  void getcutDFS(int u) {
    inS[u] = 1;
    for (auto id: adj[u]) {
      int v = edge[id].to, cap = edge[id].cap;
      if (cap && !inS[v])
        getcutDFS(v);
    }
  }
  void getcut(int S) {
    inS.resize(n);
    for (int i = 0; i < n; i++) inS[i] = 0;
    getcutDFS(S);
  }
};

vector<int>adj[N];
int a[N],b[N],ans[N];
int n,m;

int id[N],S,T;

void sol(int l,int r,vector<int>V){
    if(!SZ(V))return;
    
    FLOW<long long>flow(SZ(V)+2);
    S=SZ(V),T=S+1;
    for(int i=0;i<SZ(V);i++)id[V[i]]=i;
    for(auto u:V){
        for(auto v:adj[u])
            if(id[v]!=-1)
                flow.addedge(id[u],id[v],inf);
    }    
    if(l+1==r){
        for(auto u:V){
            ll c=llabs(a[u]-b[l])-llabs(a[u]-b[r]);
            if(c>0)flow.addedge(S,id[u],c);
            else flow.addedge(id[u],T,-c);
        }
        flow.Dinic(S,T),flow.getcut(S);
        for(auto u:V){
            ans[u]=flow.inS[id[u]]?b[r]:b[l];
        }
        for(auto u:V)id[u]=-1;
        return;
    }
    int mid=l+r>>1;
    for(int i=0;i<SZ(V);i++){
        int u=V[i];
        ll c=llabs(a[u]-b[mid])-llabs(a[u]-b[mid+1]);
        if(c>0)flow.addedge(S,i,c);else flow.addedge(i,T,-c);
    }
    flow.Dinic(S,T),flow.getcut(S);
    vector<int>L,R;
    for(auto u:V){
        if(flow.inS[id[u]])R.pb(u);
        else L.pb(u);
    }
    for(auto u:V)id[u]=-1;
    sol(l,mid,L);
    sol(mid,r,R);
}

signed main(){
    memset(id,-1,sizeof(id));
    n=read(),m=read();
    rep(i,1,n)a[i]=b[i]=read();
    int len=n;
    sort(b+1,b+len+1),len=unique(b+1,b+len+1)-b-1;
    if(len==1){
        rep(i,1,n){
            printf("%d ",a[i]); 
        }
        puts("");
        return 0;
    }
    rep(i,1,m){
        int u=read(),v=read();
        adj[u].pb(v);
    }
    vector<int>ini;rep(i,1,n)ini.pb(i);
    sol(1,len,ini);
    rep(i,1,n)print(ans[i]," \n"[i==n]);
    return 0;
}