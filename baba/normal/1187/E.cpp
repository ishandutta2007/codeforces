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
const int N = 2e5 + 10;
int e[N], U[N], V[N];
VI tree[N];
LL DP[N][2], PS[N];
#define left leftt
int sz[N][2], tsz[N], par[N], vis[N], left[N];
inline int u(int e, int x){
  return x ? V[e] : U[e];
}
inline int v(int e, int x) {
  return x ? U[e] : V[e];
}
inline int get_t(int e, int source){
  return source == U[e] ? 0 : 1;
}
void dfs(int x, int pe) {
  tsz[x] = 1;
  par[x] = pe;
  for(auto e : tree[x]){
    if(e == pe) continue;
    int y = U[e] ^ V[e] ^ x;
    dfs(y, e);
    tsz[x] += tsz[y];
  }
}
LL f(int e, int t) {
  LL& dp = DP[e][t];
  if(dp)return dp;
  dp = sz[e][t];
  int y = v(e, t);
  if(vis[y]){
    dp += PS[y];
    if(left[y] != e){
      dp -= f(e, 1 - t);
     if(left[y]) {
       int ct = get_t(left[y], y);
       auto val = f(left[y], ct);
       PS[y] += val;
       dp += val;
       left[y] = 0;
     }
    }
  }
  else {
    vis[y] = 1;
    PS[y] = 0;
    left[y] = e;
    for(auto ce : tree[y]){
      if(ce == e) continue;
      int ct = get_t(ce, y);
      auto val = f(ce, ct);
      PS[y] += val;
      dp += val;
    }
  }
  return dp;
}
int main()
{
  int n;si(n);
  for(int i = 1; i < n; i++){
    si(U[i]);si(V[i]);
    tree[U[i]].PB(i);
    tree[V[i]].PB(i);
  }
  dfs(1, 0);
  for(int e = 1; e < n; e++)
    for(int t = 0; t < 2; t++) {
      int x = u(e, t), y = v(e, t);
      if(par[y] == e){
        sz[e][t] = tsz[y];
      }
      else if(par[x] == e){
        sz[e][t] = n - tsz[x];
      }
      else {
        assert(false);
      }
    }
  LL ans = 0;
  for(int i = 1; i <= n; i++){
    LL cans = n;
    for(auto &e : tree[i]){
      int ct = get_t(e, i);
      cans += f(e, ct);
    }
    ans = max(ans, cans);
  }
  lldout(ans);
  return 0;
}