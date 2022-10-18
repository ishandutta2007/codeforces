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

const int N = int(5e3)+10;
VI g[N],rg[N],order;
int vis[N],C[N],outdeg[N],cmpno,d[N],n,m;
//g:graph,rg:reverse graph 
void dfs1(int u){
  vis[u]=1;
  for(auto w:g[u])
    if(!vis[w])
      dfs1(w);
  order.PB(u);
}
void dfs2(int u){
  vis[u]=1;C[u]=cmpno;
  for(auto w:rg[u])
    if(!vis[w])
      dfs2(w);
}
int bfs(int x,int c){
  queue<int> Q;Q.push(x);
  vis[x]=1;d[x]=0;
  int ret = N;
  while(!Q.empty()){
    int u = Q.front();Q.pop();
    for(auto w:g[u]){
      if(!vis[w] && C[w]==c){
        d[w] = d[u]+1;
        vis[w]=1;
        Q.push(w);
      }
      else if(w == x)
        ret = min(ret,d[u]+1);
    }
  }
  return ret;
}
int get(int c){
  int ret = N;
  for(int i=1;i<=n;i++){
    if(C[i]!=c)continue;
    SET(vis,0);
    ret = min(ret,bfs(i,c));
  }
  if(ret==N)ret=0;
  return ret;
}
int main()
{
  si(n);si(m);
  for(int i=1;i<=m;i++){
    int u,v;
    si(u);si(v);
    g[u].PB(v);
    rg[v].PB(u);
  }
  SET(vis,0);
  for(int i=1;i<=n;i++)
    if(!vis[i])
      dfs1(i);
  SET(vis,0);
  for(int i=1;i<=n;i++){
    int u = order[n-i];
    if(!vis[u]){
      cmpno++;
      dfs2(u);
    }
  }
  for(int i=1;i<=n;i++)
    for(auto j : g[i])
      if(C[i]!=C[j])
        outdeg[C[i]]++;
  int ans = n;
  for(int i=1;i<=cmpno;i++)
    if(!outdeg[i]){
      int x = get(i);
      ans += 998*x + (x?1:0);
    }
  dout(ans);
  return 0;
}