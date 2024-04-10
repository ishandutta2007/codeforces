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
  int AddEdge(int x,int y,LL c1,LL c2){
    adj[E]=y;cap[E]=c1;next[E]=last[x];last[x]=E++;
    adj[E]=x;cap[E]=c2;next[E]=last[y];last[y]=E++;
    return E - 2;
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
const int N = 5001;
int n,m,U[N],V[N],L[N],R[N],from[N],to[N];
vector<pair<int,II>> edges;
bool ok(int val){
  int len = 0;
  int s = len++, t = len++;
  for(int i=1;i<=n;i++)
    L[i] = len++;
  for(int i=1;i<=m;i++)
    R[i] = len++;
  Dinic::init(len+1);
  for(int i=1;i<=n;i++)
    Dinic::AddEdge(s, L[i], val, 0);
  for(int i=1;i<=m;i++)
    Dinic::AddEdge(R[i], t, 1, 0);
  edges.clear();
  for(int i=1;i<=m;i++){
    edges.PB({Dinic::AddEdge(L[U[i]],R[i],1,0),{U[i],i}});
    edges.PB({Dinic::AddEdge(L[V[i]],R[i],1,0),{V[i],i}});
  }
  return Dinic::run(s, t) == m;
}
int main()
{
  si(n);si(m);
  for(int i=1;i<=m;i++)
    scanf("%d %d",U+i,V+i);
  int l = 0, h = N, ans = -1;
  while(l <= h){
    int mid = (l + h) >> 1;
    if(ok(mid)){
      ans = mid;
      h = mid - 1;
    }
    else l = mid + 1;
  }
  ok(ans);
  for(auto e : edges){
    if(Dinic::cap[e.F])continue;
    assert(!from[e.S.S] && !to[e.S.S]);
    from[e.S.S] = e.S.F;
    to[e.S.S] = U[e.S.S] ^ V[e.S.S] ^ from[e.S.S];
  }
  for(int i=1;i<=m;i++)
    assert(from[i] && to[i]);
  dout(ans);
  for(int i=1;i<=m;i++)
    printf("%d %d\n",from[i],to[i]);
	return 0;
}