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

//#define TRACE

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
const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(1e9);
VI g[N];
int sub[N],nn,U[N],V[N],done[N],A[N],par[N],d[LOGN][N],level[N],mark[N],cntbn[N],ans[2][N];
int adj(int u,int e){
  return U[e]^V[e]^u;
}
void dfs1(int u,int p){
  sub[u]=1;nn++;
  for(auto e:g[u]){
    int w = adj(u,e);
    if(w!=p && !done[e])
      dfs1(w,u),sub[u]+=sub[w];
  }
}
int dfs2(int u,int p){
  for(auto e:g[u]){
    if(done[e])continue;int w = adj(u,e);
    if(w!=p && sub[w]>nn/2)
      return dfs2(w,u);
  }return u;
}
int dfs(int u,int p,int t){
  int ret = (mark[u]?0:-INF);
  d[t][u] = d[t][p] + 1;
  for(auto e:g[u]){
    if(done[e])continue;int w = adj(u,e);
    if(w==p)continue;
    ret = max(ret,1 + dfs(w,u,t));
  }
  return ret;
}
void decompose(int root,int p,int ct){
  nn=0;dfs1(root,root);
  int centroid=dfs2(root,root);
  if(p==-1)p=centroid;//fuck centroid :)
  else level[centroid]=level[p]+1;
  trace(centroid,p);
  par[centroid]=p;cntbn[centroid]=ct;
  VI x;x.PB(-INF);x.PB(-INF);if(mark[centroid])x.PB(0);
  for(auto e:g[centroid]){
    if(done[e])continue;
    int w = adj(centroid,e);
    int y = 1 + dfs(w,centroid,level[centroid]);x.PB(y);
    done[e]=1;decompose(w,centroid,y);
  }
  sort(ALL(x));reverse(ALL(x));
  ans[0][centroid]=x[0];ans[1][centroid]=x[1];
}
int query(int x){
  int ret = ans[0][x];
  int y = x;
  while(x!=par[x]){
    ret = max(ret , (ans[0][par[x]]==cntbn[x]?ans[1][par[x]]:ans[0][par[x]]) + d[level[par[x]]][y]);
    x = par[x];
  }
  return ret;
}
int main()
{
  int n,m,d;
  si(n);si(m);si(d);
  for(int i=1;i<=m;i++){
    int x;si(x);mark[x]=1;
  }
  for(int i=0;i<n-1;i++){
    scanf("%d %d",U+i,V+i);
    g[U[i]].PB(i);g[V[i]].PB(i);
  }
  decompose(1,-1,0);
  for(int i=1;i<=n;i++)
    trace(i,ans[0][i],ans[1][i],cntbn[i]);
  int ans = 0;
  for(int i=1;i<=n;i++){
    trace(i,query(i));
    if(query(i) <= d)
      ans++;
  }
  dout(ans);
	return 0;
}