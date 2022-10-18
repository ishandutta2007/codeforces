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
const int N = int(4e5)+10;
VI g[N];
int P[N],B[N],vis[N];
void dfs(int x){
  vis[x]=1;
  for(auto w : g[x])
    if(!vis[w])
      dfs(w);
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++){
    si(P[i]);
    g[i].PB(P[i]);
    g[P[i]].PB(i);
  }
  int want = 0;
  for(int i=1;i<=n;i++){
    int x;si(x);
    want ^= x;
  }
  int ans = 1 - want;
  int comp = 0;
  for(int i=1;i<=n;i++)
    if(!vis[i])
      dfs(i),comp++;
  ans = ans + (comp > 1 ? comp : 0);
  dout(ans);
	return 0;
}