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

const int N = 2e5;
const int LOGN = 20;
LL G[50][50];
int DP[LOGN][N];
int dsu[N], U[N], V[N], W[N], istree[N], idx[N], len, level[N], rev[N];
LL d[N];
VI g[N];
int f(int x){
  if(dsu[x] == x)return x;
  return dsu[x] = f(dsu[x]);
}
int adj(int x, int e){
  return U[e] ^ V[e] ^ x;
}
int lca(int a, int b){
  if(level[a] > level[b])swap(a, b);
  int d = level[b] - level[a];
  for(int i = LOGN - 1; i >= 0; i--)
    if((1 << i) & d)
      b = DP[i][b];
  if(a == b)return a;
  for(int i = LOGN - 1; i >= 0; i--)
    if(DP[i][a] != DP[i][b])
      a = DP[i][a], b = DP[i][b];
  return DP[0][a];
}
void dfs(int x, int p){
  DP[0][x] = p;
  for(auto e : g[x]){
    int y = adj(x, e);
    if(y != p){
      level[y] = level[x] + 1;
      d[y] = d[x] + W[e];
      dfs(y, x);
    }
  }
}
LL dist(int a, int b){
  int LCA = lca(a, b);
  return d[a] + d[b] - 2 * d[LCA];
}
void process(int n){
  dfs(1, 1);
  for(int i = 1; i < LOGN; i++)
    for(int j = 1; j <= n; j++)
      DP[i][j] = DP[i - 1][DP[i - 1][j]];
}
LL D[100];
int vis[100];
LL get(int s, int d){
  trace(len, s, d);
  SET(vis, 0);
  for(int i = 1; i <= len; i++){
    G[0][i] = G[i][0] = dist(s, rev[i]);
    G[i][len + 1] = G[len + 1][i] = dist(d, rev[i]);
  }
  G[0][len + 1] = G[len + 1][0] = dist(s, d);
  for(int i = 0; i <= len + 1; i++){
    D[i] = 1e18;
  }
  REP(i, len + 2)REP(j, len + 2)trace(i, j, rev[i], rev[j], G[i][j]);
  D[0] = 0;
  for(int i = 0; i <= len + 1; i++){
    int x = -1;
    for(int j = 0; j <= len + 1; j++){
      if(vis[j])continue;
      if(x == -1 || D[j] < D[x]){
        x = j;
      }
    }
    if(x == -1)break;
    vis[x] = 1;
    trace(x);
    for(int j = 0; j <= len + 1; j++){
      if(vis[j])continue;
      D[j] = min(D[j], D[x] + G[x][j]);
    }
  }
  return D[len + 1];
}
int main()
{
  int n, m;
  si(n);si(m);
  for(int i = 1; i <= n; i++){
    dsu[i] = i;
  }
  for(int i = 1; i <= m; i++){
    scanf("%d %d %d", U + i, V + i, W + i);
    int a = f(U[i]), b = f(V[i]);
    if(a == b)continue;
    dsu[a] = b;
    g[U[i]].PB(i);
    g[V[i]].PB(i);
    istree[i] = 1;
  }
  process(n);
  set<int> S;
  for(int i = 1; i <= m; i++){
    if(!istree[i]){
      S.insert(U[i]);
      S.insert(V[i]);
    }
  }
  for(auto &x : S){
    idx[x] = ++len;
    rev[len] = x;
  }
  for(int i = 1; i <= len; i++){
    for(int j = 1; j <= len; j++){
      G[i][j] = 1e18;
    }
  }
  for(int i = 1; i <= m; i++){
    if(!istree[i]){
      int a = idx[U[i]];
      int b = idx[V[i]];
      G[a][b] = G[b][a] = W[i];
    }
  }
  for(int i = 1; i <= len; i++)
    for(int j = 1; j <= len; j++){
      G[i][j] = min(G[i][j], dist(rev[i], rev[j]));
    }
  int q;si(q);
  while(q--){
    int s, d;
    si(s);si(d);
    lldout(get(s, d));
  }
  return 0;
}