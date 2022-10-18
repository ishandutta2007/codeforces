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
VI g[N];
int A[N],cnt[N],k;
LL dp[N];
void dfs(int u,int p){
  cnt[u]=A[u];
  for(auto w:g[u])
    if(w!=p){
      dfs(w,u);
      cnt[u] += cnt[w];
      dp[u] += dp[w] + cnt[w];
    }
  if(cnt[u] <= k)return;
  int out = 2*k - cnt[u];
  int use = cnt[u] - out;
  cnt[u] -= use;
  k -= use/2;
}
int main()
{
  int n;
  si(n);si(k);
  for(int i=1;i<=2*k;i++){
    int x;si(x);
    A[x]=1;
  }
  for(int i=1;i<n;i++){
    int u,v;
    si(u);si(v);
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(1,1);
  lldout(dp[1]);
	return 0;
}