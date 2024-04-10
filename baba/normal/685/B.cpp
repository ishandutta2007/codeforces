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
const int N = int(3e5)+10;
VI g[N];
int sub[N],P[N],ans[N];
set<II>* A[N];
void dfs(int u,int p){
  sub[u]=1;
  for(auto w:g[u])
    if(w!=p)
      dfs(w,u),sub[u]+=sub[w];
}
set<II>* create_node(int x){
  set<II>* ret = new set<II>;
  ret->insert({1,x});
  return ret;
}
void dfs2(int u,int p){
  int mx = 0;
  //trace(u,p);
  for(auto w:g[u])
    if(w!=p)
      dfs2(w,u);
  for(auto w:g[u])
    if(w!=p && sub[w] > sub[mx])
      mx = w;
  //trace(u,mx);
  if(mx == 0){
    A[u] = create_node(u);
    ans[u]=u;
    return;
  }
  A[u] = A[mx];
  for(auto w:g[u])
    if(w!=p && w!=mx)
      for(auto it : *A[w])
        A[u]->insert(it);
  A[u]->insert({sub[u],u});
  auto it = (A[u]->upper_bound({sub[u]/2,N}));
  //trace(it->F,it->S,sub[u]/2);
  //assert(it!=A[u]->begin());it--;
  //trace(it->F,it->S);
  ans[u]=it->S;
}
int main()
{
  int n,q;
  si(n);si(q);
  for(int i=2;i<=n;i++){
    int x;si(x);
    P[i]=x;
    g[x].PB(i);
    g[i].PB(x);
  }
  dfs(1,1);
  dfs2(1,1);
  while(q--){
    int v;si(v);
    dout(ans[v]);
  }
	return 0;
}