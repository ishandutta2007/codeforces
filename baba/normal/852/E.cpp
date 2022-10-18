//TooMuchMath
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
const int MOD = int(1e9)+7;
int mul(int a,int b){
  return (a * 1ll * b) % MOD;
}
int add(int a,int b){
  a = a + b;
  if(a >= MOD) a -= MOD;
  return a;
}
int power(int a,int p){
  int ret = 1;
  while(p){
    if(p & 1)ret = mul(ret,a);
    a = mul(a,a);
    p >>= 1;
  }
  return ret;
}
int inv(int x){
  return power(x, MOD - 2);
}
int dp[N][2],up[N][2],ans;
VI g[N];
void dfs1(int x,int p){
  int p1 = 1, p2 = 1, isLeaf = 1;
  for(auto y : g[x]){
    if(y == p)continue;
    isLeaf = 0;
    dfs1(y, x);
    p1 = mul(p1, dp[y][0]);
    p2 = mul(p2, dp[y][1]);
  }
  dp[x][0] = add(p1, p2);
  dp[x][1] = add(p1, p2);
  if(isLeaf){
    dp[x][0] = dp[x][1] = 1;
  }
}
void dfs2(int x, int p){
  int p1 = 1, p2 = 1;
  for(auto y : g[x]){
    if(y == p)continue;
    p1 = mul(p1, dp[y][0]);
    p2 = mul(p2, dp[y][1]);
  }
//  trace(x,dp[x][0],dp[x][1],up[x][0],up[x][1], p1, p2);
//  trace(ans);
  ans = add(ans, mul(p1, up[x][0]));
//  trace(ans);
  ans = add(ans, mul(p2, up[x][1]));
//  trace(ans);
  for(auto y : g[x]){
    if(y == p)continue;
    p1 = mul(p1, inv(dp[y][0]));
    p2 = mul(p2, inv(dp[y][1]));
    if(x == p && SZ(g[x]) == 1){
      up[y][0] = 1; 
    }
    else{
      up[y][0] = add(mul(p1, up[x][0]),mul(p2, up[x][1])); 
    }
    up[y][1] = up[y][0];
    dfs2(y, x);
    p1 = mul(p1, dp[y][0]);
    p2 = mul(p2, dp[y][1]);
  }
}
int main()
{
  int n;si(n);
  for(int i=1;i<n;i++){
    int u,v;
    si(u);si(v);
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs1(1,1);
  up[1][0] = 1;
  up[1][1] = 1;
  dfs2(1,1);
  dout(ans);

	return 0;
}