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
const int N = int(1e6)+10;
VI g[N],tree[N],V[N];
map<pair<int,int>,vector<int>> E;
int origin,n;
int vis[N],C[N],R[N];
bool cmp(int a,int b){
  if(a < origin)a = a + n;
  if(b < origin)b = b + n;
  return a < b;
}
bool cmp1(int a,int b){
  return V[a] < V[b];
}
namespace Centroid{
  VI g[N];
  int sub[N],nn,U[N],V[N],done[N],m;
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
      if(done[e])continue;
      int w = adj(u,e);
      if(w!=p && sub[w]>nn/2)
        return dfs2(w,u);
    }
    return u;
  }
  void decompose(int root,int p,int l = 1){
    nn=0;dfs1(root,root);
    root=dfs2(root,root);
    if(p==-1)p=root;//fuck centroid :)
    C[root] = l;
    for(auto e:g[root]){
      if(done[e])continue;
      done[e]=1;
      int w = adj(root,e);
      decompose(w,root,l+1);
    }
  }
  void addEdge(int a,int b){
    m++;
    U[m] = a; V[m] = b;
    g[a].PB(m);g[b].PB(m);
  }
}


int main()
{
  si(n);
  for(int i=0;i<n;i++){
    g[i].PB((i+1)%n);
    g[(i+1)%n].PB(i);
    trace(i,(i+1)%n);
  }
  int m;si(m);
  for(int i=0;i<m;i++){
    int a,b;
    si(a);si(b);
    a--;b--;
    g[a].PB(b);
    g[b].PB(a);
    trace(a,b);
  }
  for(int i=0;i<n;i++){
    origin = i;
    sort(ALL(g[i]),cmp);
  }
  map<pair<int,int>,int> mp;
  vector<vector<int>> A;
  for(int i=0;i<n;i++){
    for(int j=0;j<SZ(g[i])-1;j++){
      int a = g[i][j], b = g[i][j+1];
      A.PB({a,i,b});
      mp[MP(a,i)] = b;
    }
  }
  map<vector<int>,int> vis1;
  int cr = 0;
  for(auto angle : A){
    if(vis1[angle])continue;
    int a = angle[0], b = angle[1], c = angle[2];
    ++cr;
    int cv = b;
    while(!vis[cv]){
      V[cr].PB(cv);
      E[MP(min(a,b),max(a,b))].PB(cr);
      vis[cv] = 1;
      vis1[{a,b,c}] = 1;
      cv = mp[MP(b,c)];
      a = b; b = c;c = cv;
      cv = b;
    }
    sort(ALL(V[cr]));
    reverse(ALL(V[cr]));
    for(auto x :V[cr])
      vis[x]=0;
  }
  n = cr;
  for(int i=1;i<=n;i++)
    R[i] = i;
  sort(R+1,R+1+n,cmp1);
  for(auto e : E){
    assert(SZ(e.S) <= 2);
    if(SZ(e.S) == 1)continue;
    int a  = e.S[0], b = e.S[1];
    Centroid::addEdge(a,b);
  }
  Centroid::decompose(1,-1);
  for(int i=1;i<=n;i++)
    printf("%d ",C[R[i]]);
  puts("");
  return 0;
}