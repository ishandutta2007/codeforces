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
const int N = int(1e5)+10;
int dp[N][2],pos[N],wt[N];
//dp[x][0] : go in subtree and don't come back.
//dp[x][1] : go in subtree and do come back up.
VII g[N];
int n,k;
void dfs(int x,int p){
  VII child;
  for(auto it : g[x]){
    int y = it.F, wt = it.S;
    if(y == p)continue;
    ::wt[y] = wt;
    dfs(y,x);
    child.PB(MP(dp[y][1] + wt,y));
  }
  sort(ALL(child));
  reverse(ALL(child));
  REP(i,SZ(child)){
    if(i < k - 1)dp[x][1] += child[i].F;
    pos[child[i].S] = i;
  }
  int val = SZ(child) < k ? 0 : child[k-1].F;
  REP(i,SZ(child)){
    int y = child[i].S;
    int add = (wt[y] + dp[y][0]) - (i < k - 1 ? (child[i].F - val) : 0);
    dp[x][0] = max(dp[x][0],dp[x][1] + add);
  }
}
int main()
{
  si(n);si(k);
  REP(i,n-1){
    int u,v,c;
    si(u);si(v);si(c);
    g[u].PB({v,c});
    g[v].PB({u,c});
  }
  dfs(0,0);
  dout(dp[0][0]);
	return 0;
}