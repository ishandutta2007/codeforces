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
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
inline int add(int a, int b){
  a = a + b;
  if(a >= MOD)a -= MOD;
  return a;
}
inline int mul(int a, int b){
  return (a * 1ll * b) % MOD;
}
inline int subt(int a, int b){
  a = a - b;
  if(a < 0) a += MOD;
  return a;
}
VI g[N];int sub[N],nn,U[N],V[N],done[N];
int val[N], ans, cnt[2], addd;
int adj(int x, int e){
  return U[e] ^ V[e] ^ x;
}
void dfs1(int u,int p){
  sub[u]=1;nn++;
  for(auto e:g[u]){
    int w = adj(u,e);
    if(w!=p && !done[e])
      dfs1(w,u),sub[u]+=sub[w];
  }
}
int dfs2(int u,int p){
  for(auto e:g[u]){
    if(done[e])continue;
    int w = adj(u,e);
    if(w!=p && sub[w]>nn/2)
      return dfs2(w,u);
  }return u;
}
void dfs3(int x, int p, int lvl){
  cnt[lvl & 1] += addd;
  for(auto e : g[x]){
    if(done[e])continue;
    int y = adj(x, e);
    if(y == p)continue;
    dfs3(y, x, lvl + 1);
  }
}
int vroot;
void dfs4(int x, int p, int s0 = 0, int s1 = 0, int lvl = 1){
  if(lvl & 1){
    s1 = subt(s1, val[x]);
    s0 = add(s0, val[x]);
    ans = add(ans, mul(s0, add(cnt[0], cnt[1])));
    ans = subt(ans, mul(vroot, add(cnt[0], cnt[1])));
  }
  else {
    s1 = add(s1, val[x]);
    s0 = subt(s0, val[x]);
    ans = add(ans, mul(s1, add(cnt[0], cnt[1])));
    ans = add(ans, mul(vroot, add(cnt[0], cnt[1])));
  }
  trace(x, p, s0, s1, cnt[0], cnt[1]);
  ans = add(ans, mul(s0, cnt[1]));
  ans = add(ans, mul(s1, cnt[0]));
  for(auto e : g[x]){
    if(done[e])continue;
    int y = adj(x, e);
    if(y == p)continue;
    dfs4(y, x, s0, s1, lvl + 1);
  }
}
void decompose(int root,int p){
  nn=0;dfs1(root,root);root=dfs2(root,root);
  if(p==-1)p=root;//fuck centroid :)
  
  cnt[0] = cnt[1] = 0;
  addd = +1;
  dfs3(root, root, 0);
  
  vroot = val[root];
  
  ans = add(ans, mul(vroot, cnt[0] + cnt[1]));
  
  for(auto e : g[root]){
    if(done[e])continue;
    int y = adj(root, e);
    addd = -1;
    dfs3(y, root, 1);

    dfs4(y, root);

    addd = +1;
    dfs3(y, root, 1);
  }
  for(auto e:g[root]){
    if(done[e])continue;
    done[e]=1;int w = adj(root,e);
    decompose(w,root);
  }
}

int main()
{
  int n;si(n);
  for(int i = 1; i <= n; i++){
    si(val[i]);
    val[i] = (val[i] + MOD) % MOD;
  }
  REP(i, n - 1){
    scanf("%d %d", U + i, V + i);
    g[U[i]].PB(i);
    g[V[i]].PB(i);
  }
  decompose(1, -1);
  dout(ans);
	return 0;
}