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
const int N = int(1e6)+10;
const LL INF = LL(1e18);
int in[N],out[N],len;
int T[N],L[N],R[N],U[N],V[N],W[N];
int vis[N];
LL d[N];
VII g[N];
void build(int l,int r,int x=1){
  if(l == r - 1){
    in[x] = out[x] = l;
  }
  else if(!in[x]){
    in[x] = ++len;
    out[x] = ++len;
  }
  if(x != 1)g[in[x]].PB({in[x/2],0});
  if(x != 1)g[out[x/2]].PB({out[x],0});
  if(l == r - 1)return;
  int m = (l + r) / 2;
  int lc = 2*x;
  int rc = 2*x + 1;
  build(l,m,lc);
  build(m,r,rc);
}
void Insert(int L,int R,int id,int l,int r,int x=1,bool del = false){
  if(r <= L || R <= l)return;
  if(l >= L && r <= R){
    if(T[id] == 2){
      int u = U[id];
      g[u].PB({out[x],W[id]});
    }
    else if(T[id] == 3){
      int v = V[id];
      g[in[x]].PB({v,W[id]});
    }
    else assert(false);
    return;
  }
  int m = (l + r) / 2;
  int lc = 2*x;
  int rc = 2*x + 1;
  Insert(L,R,id,l,m,lc,del);
  Insert(L,R,id,m,r,rc,del);
}
int main()
{
  int n,q,s;
  si(n);si(q);si(s);
  len = n;
  build(1,n+1);
  for(int i=1;i<=q;i++){
    si(T[i]);
    if(T[i] == 1){
      si(U[i]);si(V[i]),si(W[i]);
      g[U[i]].PB({V[i],W[i]});
    }
    else if(T[i] == 2){
      si(U[i]);si(L[i]);si(R[i]);si(W[i]);
      Insert(L[i],R[i]+1,i,1,n+1);
    }
    else {
      si(V[i]);si(L[i]);si(R[i]);si(W[i]);
      Insert(L[i],R[i]+1,i,1,n+1);
    }
  }
  set<pair<LL,int>> S;
  S.insert({0,s});
  for(int i=1;i<=len;i++)d[i] = INF;
  d[s] = 0;
  while(!S.empty()){
    auto it = *S.begin();
    S.erase(S.begin());
    int u = it.S;
    if(vis[u])continue;
    vis[u] = 1;
    for(auto it : g[u]){
      int w = it.F;
      int wt = it.S;
      if(d[u] + wt < d[w]){
        d[w] = d[u] + wt;
        S.insert({d[w],w});
      }
    }
  }
  for(int i=1;i<=n;i++)
    if(d[i] == INF)
      d[i] = -1;
  for(int i=1;i<=n;i++)
    printf("%lld ",d[i]);
  puts("");
	return 0;
}