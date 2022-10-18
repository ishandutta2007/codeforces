//TooMuchMath
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
//init(n1,n2):takes no of vertices on left and right
//addEdge(u,v):node u on left and v on right(0-based)
const int MAXN1=50000,MAXN2=50000,MAXM=150000;
int n1,n2,edges,last[MAXN1],prv[MAXM],head[MAXM],Q[MAXN1];
int matching[MAXN2],dist[MAXN1];bool used[MAXN1],vis[MAXN1];
void init(int _n1,int _n2){n1=_n1;n2=_n2;edges=0;fill(last,last+n1,-1);}
void addEdge(int u,int v){head[edges]=v;prv[edges]=last[u];last[u]=edges++;}
void bfs(){fill(dist,dist+n1,-1);int sizeQ=0;
  for(int u=0;u<n1;++u)if(!used[u])Q[sizeQ++]=u,dist[u]=0;
  for(int i=0;i<sizeQ;i++){int u1=Q[i];
    for(int e=last[u1];e>=0;e=prv[e]){int u2=matching[head[e]];
      if(u2>=0&&dist[u2]<0)dist[u2]=dist[u1]+1,Q[sizeQ++]=u2;}}}
bool dfs(int u1){vis[u1]=true;
  for(int e=last[u1];e>=0;e=prv[e]){
    int v=head[e],u2=matching[v];
    if(u2<0||(!vis[u2] && dist[u2]==dist[u1]+1 && dfs(u2))){
      matching[v]=u1;used[u1]=true;return true;
    }}return false;}
int maxMatching(){
  fill(used,used+n1,false);fill(matching,matching+n2,-1);
  for(int res=0;;){bfs();fill(vis,vis+n1,false);int f=0;
    for(int u=0;u<n1;++u)if(!used[u]&&dfs(u))++f;
    if(!f)return res;res+=f;}}
const int N = 601;
const int INF = int(1e9);
int d[N][N],S[N];
bool ok(int t, int n, int m, int k){
  init(m, n);
  REP(i,m)REP(j,n){
    if(d[S[i]][j+1] <= t){
      addEdge(i, j);
    }
  }
  return maxMatching() >= k;
}
int main()
{
  REP(i,N)REP(j,N)d[i][j] = INF;
  REP(i,N)d[i][i] = 0;
  int n,m,t,k;
  si(n);si(m);si(t);si(k);
  REP(i,t)si(S[i]);
  REP(i,m){
    int a,b,w;
    si(a);si(b);si(w);
    d[a][b] = min(d[a][b],w);
    d[b][a] = min(d[b][a],w);
  }
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
  int l = 0, h = 1731311, ans = -1;
  while(l <= h){
    int mid = (l + h) >> 1;
    if(ok(mid,n,t,k)){
      ans = mid;
      h = mid - 1;
    }
    else l = mid + 1;
  }
  dout(ans);
	return 0;
}