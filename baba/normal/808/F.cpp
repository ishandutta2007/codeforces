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
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

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
// Max flow of directed weighted graph from source to sink.
// init(n)-->AddEdge(x,y,c1,c2)-->run(src,sink).
// AddEdge(x,y,c1,c2)adds x->y of cap c1 and y->x of cap c2
namespace Dinic{// MAXE = 2*(# calls to AddEdge);
  const int MAXV=int(1e5)+10,MAXE=int(2e5)+10;
  const LL INF=1e18;LL cap[MAXE];int V,E,last[MAXV];
  int dist[MAXV],curr[MAXV],next[MAXE],adj[MAXE];
  void init(int n){V=n;E=0;REP(i,V)last[i]=-1;}
  void AddEdge(int x,int y,LL c1,LL c2){
    adj[E]=y;cap[E]=c1;next[E]=last[x];last[x]=E++;
    adj[E]=x;cap[E]=c2;next[E]=last[y];last[y]=E++;
  }LL push(int x,int sink,LL flow){
    if(x==sink)return flow;
    for(int &e=curr[x];e!=-1;e=next[e]){
      int y=adj[e];
      if(cap[e]&&dist[x]+1==dist[y])
        if(LL f=push(y,sink,min(flow,cap[e])))
          return cap[e]-=f,cap[e^1]+=f,f;
    }return 0;
  }LL run(int src,int sink){
    LL ret=0;
    while(1){
      REP(i,V)curr[i]=last[i],dist[i]=-1;
      queue<int> Q;Q.push(src),dist[src]=0;
      while(!Q.empty()){
        int x=Q.front();Q.pop();
        for(int e=last[x];e!=-1;e=next[e]){
          int y=adj[e];
          if(cap[e]&&dist[y]==-1)
            Q.push(y),dist[y]=dist[x]+1;
        }
      }
      if(dist[sink]==-1)break;
      while(LL f=push(src,sink,INF))ret+=f;
    }
    return ret;
  }
}
const int N = 101;
const int MAX = int(2e5)+10;
int P[N],C[N],L[N];
bool isP[MAX];
int solve(int n,int val){
  int nodes = 0;
  map<int,int> g;
  for(int i=1;i<=n;i++){
    if(L[i] > val)continue;
    if(C[i] == 1){
      g[C[i]] = max(g[C[i]],P[i]);
    }
    else g[C[i]] += P[i];
  }
  Dinic::init(SZ(g) + 2);
  int s = nodes++, t = nodes++;
  LL total = 0;
  VII B[2];
  for(auto it : g){
    int t = it.F & 1;
    total += it.S;
    B[t].PB(MP(nodes,it.F));
    if(s == t)
      Dinic::AddEdge(s,nodes,it.S,0);
    else Dinic::AddEdge(nodes,t,it.S,0);
    nodes++;
  }
  for(auto l : B[0])
    for(auto r : B[1])
      if(isP[l.S + r.S])
      Dinic::AddEdge(l.F,r.F,Dinic::INF,0);
  return total - Dinic::run(s,t);
}
int main()
{
  FOR(i,2,MAX)isP[i]=true;
  FOR(i,2,MAX)
    if(isP[i])
      for(int j=2*i;j<MAX;j+=i)
        isP[j] = false;
  int n,k;
  si(n);si(k);
  for(int i=1;i<=n;i++)
    scanf("%d %d %d",P+i,C+i,L+i);
  int l = 1,h = n, ans = -1;
  while(l <= h){
    int m = (l + h) >> 1;
    if(solve(n,m) >= k){
      ans = m;
      h = m - 1;
    }
    else l = m + 1;
  }
  dout(ans);
	return 0;
}