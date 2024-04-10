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
const int N = int(1e5)+10;
LL A[N],d[N];
int sub[N],mark[N];
VII g[N];
multiset<LL> S;
int ans;
void dfs(int u,int p){
  S.insert({d[u]});
  if(d[u] > *S.begin() + A[u]){
    ans+=sub[u];
    S.erase(S.find(d[u]));
    return;
  }
  for(auto it:g[u]){
    int w = it.F;
    int weight = it.S;
    if(w==p)continue;
    d[w]=d[u]+weight;
    dfs(w,u);
  }
  S.erase(S.find(d[u]));
}
void dfs1(int u,int p){
  sub[u]=1;
  for(auto it:g[u])
    if(it.F!=p)
      dfs1(it.F,u),sub[u]+=sub[it.F];
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++)
    sll(A[i]);
  for(int i=2;i<=n;i++){
    int p,c;
    si(p);si(c);
    g[p].PB({i,c});
    g[i].PB({p,c});
  }
  dfs1(1,1);
  dfs(1,1);
  dout(ans);
	return 0;
}