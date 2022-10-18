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

const int N = int(2e5)+10;
const int MOD = int(1e9)+7;
VI g[N], pts_x[N], pts_y[N];
int vis[N], fact[N], inv[N], X[N], Y[N];
int add(int a, int b){
  a = (a + b);
  if(a >= MOD)a -= MOD;
  return a;
}
int sub(int a, int b){
  a = a - b;
  if(a < 0) a += MOD;
  return a;
}
int mul(int a, int b){
  return (a * 1ll * b) % MOD;
}
int power(int a, int p){
  int ret = 1;
  while(p){
    if(p & 1)ret = mul(ret, a);
    a = mul(a, a);
    p >>= 1;
  }
  return ret;
}
void addEdge(int a, int b){
  g[a].PB(b);
  g[b].PB(a);
}
int nn, ee;
void dfs(int x){
  if(vis[x])return;
  vis[x] = 1;nn++;
  ee += SZ(g[x]);
  for(auto y : g[x])
    dfs(y);
}
int nCr(int n, int r){
  assert(r <= n);
  return mul(fact[n], mul(inv[r], inv[n-r]));
}
int main()
{
  fact[0] = 1;
  FOR(i, 1, N)fact[i] = mul(fact[i-1], i);
  REP(i, N)inv[i] = power(fact[i], MOD - 2);
  int n;si(n);
  map<int, int> mp;
  for(int i=1;i<=n;i++){
    scanf("%d %d",X+i, Y+i);
    mp[X[i]];mp[Y[i]];
  }
  int len = 0;
  for(auto &it : mp)
    it.S = ++len;
  for(int i=1;i<=n;i++){
    X[i] = mp[X[i]];
    Y[i] = mp[Y[i]];
    pts_x[X[i]].PB(i);
    pts_y[Y[i]].PB(i);
  }
  REP(i, len + 1){
    sort(ALL(pts_x[i]),[&](int a, int b){return Y[a] < Y[b];});
    sort(ALL(pts_y[i]),[&](int a, int b){return X[a] < X[b];});
    REP(j, SZ(pts_x[i]) - 1)
      addEdge(pts_x[i][j], pts_x[i][j+1]);
    REP(j, SZ(pts_y[i]) - 1)
      addEdge(pts_y[i][j], pts_y[i][j+1]);
  }
  int ans = 1;
  for(int i=1;i<=n;i++){
    if(vis[i])continue;
    nn = 0, ee = 0;
    dfs(i);
    ee /= 2;
    int k = nn, num = 2 * nn - ee;
    int v = 0;
    REP(j, min(num + 1, k + 1))v = add(v, nCr(num, j));
    ans = mul(ans, v);
  }
  dout(ans);

	return 0;
}