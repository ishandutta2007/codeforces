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

const int N = 1e5 + 10;
const int LOGN = 20;
VI g[N];
LL A[N], BIT[2][N];
int DP[LOGN][N], level[N], st[N], en[N], T;
void update(LL BIT[], int x, LL val){
  for(;x < N; x += x ^ (x & (x - 1)))BIT[x]  += val;
}
LL query(LL BIT[], int x){
  LL ret = 0;
  for(;x;x = x & (x - 1))ret += BIT[x];
  return ret;
}
void range_update(int L, int R, LL val){
  update(BIT[0], L, val);
  update(BIT[0], R + 1, -val);
  update(BIT[1], L, (L - 1) * val);
  update(BIT[1], R + 1, -R * val);
}
LL range_query(int x){
  return query(BIT[0], x) * x - query(BIT[1], x);
}
LL range_query(int L, int R){
  return range_query(R) - range_query(L - 1);
}
void dfs(int x, int p){
  DP[0][x] = p;
  st[x] = ++T;
  for(auto y : g[x])
    if(y != p){
      level[y] = level[x] + 1;
      dfs(y, x);
    }
  en[x] = T;
}
void preprocess(int n){
  dfs(1, 1);
  for(int i = 1; i < LOGN; i++)
    for(int j = 1; j <= n; j++)
      DP[i][j] = DP[i - 1][DP[i - 1][j]];
  for(int i = 1; i <= n; i++)
    range_update(st[i], st[i], A[i]);
}
int goUp(int b, int d){
  REP(i, LOGN)if((1 << i) & d)b = DP[i][b];
  return b;
}
int lca(int a, int b){
  if(level[a] > level[b])swap(a, b);
  int d = level[b] - level[a];
  b = goUp(b, d);
  if(a == b)return a;
  for(int i = LOGN - 1; i >= 0; i--)
    if(DP[i][a] != DP[i][b])
      a = DP[i][a], b = DP[i][b];
  return DP[0][a];
}
bool anc(int p, int v){
  return st[v] >= st[p] && en[v] <= en[p];
}
LL query(int root, int v){
  LL ret = 0;
  if(v == root){
    ret += range_query(st[1], en[1]);
  }
  else if(anc(v, root)){
    ret += range_query(st[1], en[1]);
    int node = goUp(root, level[root] - level[v] - 1);
    ret -= range_query(st[node], en[node]);
  }
  else {
    ret += range_query(st[v], en[v]);
  }
  return ret;
}
void update(int root, int a, int b, int val){
  int LCA = lca(a, b) ^ lca(a, root) ^ lca(b, root);
  if(LCA == root){
    range_update(st[1], en[1], val);
  }
  else if(anc(LCA, root)){
    range_update(st[1], en[1], val);
    int node = goUp(root, level[root] - level[LCA] - 1);
    range_update(st[node], en[node], -val);
  }
  else {
    range_update(st[LCA], en[LCA], val);
  }
}
int main()
{
  int n, q;
  si(n);si(q);
  for(int i = 1; i <= n; i++)sll(A[i]);
  REP(i, n - 1){
    int x, y;
    si(x);si(y);
    g[x].PB(y);
    g[y].PB(x);
  }
  preprocess(n);
  int root = 1;
  while(q--){
    int t;si(t);
    if(t == 1){
      si(root);
    }
    else if(t == 2){
      int u, v, x;
      si(u);si(v);si(x);
      update(root, u, v, x);
    }
    else {
      int v;si(v);
      lldout(query(root, v));
    }
  }
	return 0;
}