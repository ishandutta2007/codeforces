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
const int N = int(2e5)+10;
int U[N],V[N],A[N],dsu[N],n,vis[N],sz[N],val[N],nodes[N],len,level[N],far[N];
VI g[N];
inline int f(int x){
  return dsu[x] = (x == dsu[x] ? x : f(dsu[x]));
}
inline void Union(int a,int b){
  a = f(a);b = f(b);
  if(a == b)return;
  sz[b] += sz[a];
  dsu[a] = b;
}
void dfs(int u,int p){
  far[u]=u;
  for(auto w : g[u])
    if(w!=p){
      level[w] = level[u]+1;
      dfs(w,u);
      if(level[far[u]] < level[far[w]])
        far[u] =far[w];
    }
}
int main()
{
  si(n);
  for(int i=1;i<=n;i++)
    si(A[i]);
  for(int i=1;i<n;i++)
    scanf("%d %d",U+i,V+i);
  for(int i=1;i<=n;i++)
    dsu[i]=i,sz[i]=1;
  for(int i=1;i<n;i++)
    if(A[U[i]]==A[V[i]])
      Union(U[i],V[i]);
  int root = -1;
  for(int i=1;i<n;i++)
    if(A[U[i]]!=A[V[i]]){
      int a = f(U[i]);
      int b = f(V[i]);
      g[a].PB(b);
      g[b].PB(a);
      root = a;
    }
  level[root]=0;
  dfs(root,root);
  int x = far[root];
  level[x]=0;
  dfs(x,x);
  int ans = (level[far[x]] + 1)/2;
  dout(ans);
	return 0;
}