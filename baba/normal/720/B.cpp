//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<int> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], int(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
	Gap(dist[v]); 
      else
	Relabel(v);
    }
  }

  int GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    int totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};
const int N = int(2e4)+10;
const int M = int(2e4)+10;
const int INF = int(1e6)+10;
VI g[N],st;
int U[M],V[M],W[M],low[N],ord[N],depth[N],col[N],C,T,compNo[N],extra[N];
bool isArtic[N];
//everything from [1,n+C] whose extra[i]=0 is part of Block-Tree 
//1-Based Graph Input.Everything from [1,C] is type B and [C,n+C] is type C.
int adj(int u,int e){
  return U[e]^V[e]^u;
}
void dfs(int i){
  low[i]=ord[i]=T++;
  for(int j=0;j<SZ(g[i]);j++){
    int ei=g[i][j],to = adj(i,ei);
    if(ord[to]==-1){
      depth[to]=depth[i]+1;
      st.PB(ei);dfs(to);
      low[i] = min(low[i],low[to]);
      if(ord[i]==0||low[to]>=ord[i]){
        if(ord[i]!=0||j>=1)
          isArtic[i] = true;
        ++C;
        while(!st.empty()){
          int fi=st.back();st.pop_back();
          col[fi]=C;
          if(fi==ei)break;
        }
      }
    }else if(depth[to]<depth[i]-1){
      low[i] = min(low[i],ord[to]);
      st.PB(ei);
    }
  }
}
void run(int n){
  SET(low,-1);SET(depth,-1);
  SET(ord,-1);SET(col,-1);
  SET(isArtic,0);st.clear();C=0;
  for(int i=1;i<=n;++i)
    if(ord[i]==-1){
      T = 0;dfs(i);
    }
}
VI e[N];
int main()
{
  int n,m;
  si(n);si(m);
  for(int i=1;i<=m;i++){
    scanf("%d %d %d",U+i,V+i,W+i);
    g[U[i]].PB(i);
    g[V[i]].PB(i);
  }
  run(n);
  for(int i=1;i<=m;i++)
    e[col[i]].PB(i);
  PushRelabel G(1 + C + m + 1 + 10);
  int s = 0, t = 1 + C + m;
  for(int i=1;i<=C;i++){
    G.AddEdge(s,i,(SZ(e[i])==1?INF : SZ(e[i]) - 1));
    for(auto x : e[i])
      G.AddEdge(i,C + W[x],1);
  }
  for(int i=C+1;i<=C+m;i++)
    G.AddEdge(i,t,1);
  dout(G.GetMaxFlow(s,t));
	return 0;
}