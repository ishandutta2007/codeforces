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
const int M = 2*N;
int last[N],edges,to[M],prv[M],deg[N];
vector<int> ans[N];
bool same(int e1,int e2){
  if(e1 == -1 || e2 == -1)return false;
  return (e1^e2) == 1;
}
void addEdge(int u,int v){
  to[edges] = v;
  prv[edges] = last[u];
  last[u] = edges++;
}
void dfs(int u,int edge,int ctime = -1){
  int curr = 0;
  for(int e = last[u];e >= 0; e = prv[e]){
    if(same(e,edge))continue;
    if(curr == ctime)curr++;
    int w = to[e];
    ans[curr].PB(e/2);
    dfs(w,e,curr);
    curr++;
  }
}
int main()
{
  int n;si(n);
  int mx = 0;
  SET(last,-1);
  for(int i=1;i<n;i++){
    int u,v;
    si(u);si(v);
    deg[u]++;deg[v]++;
    mx = max(mx,deg[u]);
    mx = max(mx,deg[v]);
    addEdge(u,v);
    addEdge(v,u);
  }
  dout(mx);
  dfs(1,-1);
  for(int i=0;i<mx;i++){
    printf("%d ",SZ(ans[i]));
    for(auto x : ans[i])
      printf("%d ",1+x);
    puts("");
  }
	return 0;
}