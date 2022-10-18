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
const int MASK = 1 << 20;
VI g[N];
int sub[N],nn,U[N],V[N],done[N], A[N];
char s[N];
LL ans[N], cnt[MASK];
int adj(int x, int e){
  return U[e] ^ V[e] ^ x;
}
inline void dfs1(int u,int p){
  sub[u]=1;nn++;
  for(auto e:g[u]){
    int w = adj(u,e);
    if(w!=p && !done[e])
      dfs1(w,u),sub[u]+=sub[w];
  }
}
inline int dfs2(int u,int p){
  for(auto e:g[u]){
    if(done[e])continue;
    int w = adj(u,e);
    if(w!=p && sub[w]>nn/2)
      return dfs2(w,u);
  }
  return u;
}
inline void dfs3(int x, int p, int mask = 0, int sign = 1){
  mask ^= (1 << A[x]);
  cnt[mask] += sign;
  for(auto e : g[x]){
    if(done[e])continue;
    int y = adj(x, e);
    if(y == p)continue;
    dfs3(y, x, mask, sign);
  }
}
LL add;
int rmask;
inline LL dfs4(int x, int p, int mask = 0){
  mask ^= (1 << A[x]);
  LL ret = 0;
  for(auto e : g[x]){
    if(done[e])continue;
    int y = adj(x, e);
    if(y == p)continue;
    ret += dfs4(y, x, mask);
  }
  ret += cnt[mask]; //for even palindrome
  REP(i, 20){
    //try to make each character odd
    mask ^= (1 << i);
    ret += cnt[mask];
    mask ^= (1 << i);
  }
  if(__builtin_popcount(mask ^ rmask) <= 1)add++;
  ans[x] += ret;
  trace(x, p, ret, ans[x], bitset<20>(mask));
  return ret;
}
inline  void decompose(int root,int p){
  nn=0;dfs1(root,root);root=dfs2(root,root);
  if(p==-1)p=root;//fuck centroid :)
  //first compute mask for each node and add to cnt
  dfs3(root, root);
  trace(root, p, "hola");
  add = 2;rmask = 1 << A[root];
  for(auto e : g[root]){
    if(done[e])continue;
    int y = adj(root, e);
    //remove contribution of this child
    dfs3(y, root, 1 << A[root], -1);
    //process the subtree
    add += dfs4(y, root);
    //add contribution of this child
    dfs3(y, root, 1 << A[root], 1);
  }

  ans[root] += add / 2;
  dfs3(root, root, 0, -1);//clear cnt's for use in future
  //done :)
  for(auto e:g[root]){
    if(done[e])continue;
    done[e]=1;
    int w = adj(root,e);
    decompose(w,root);
  }
}
int main()
{
  int n;si(n);
  REP(i, n - 1){
    scanf("%d %d", U + i, V + i);
    g[U[i]].PB(i);
    g[V[i]].PB(i);
  }
  scanf("%s", s);
  REP(i, n)A[i + 1] = s[i] - 'a';
  decompose(1, -1);
  REP(i, n)printf("%lld ", ans[i + 1]);
  puts("");
	return 0;
}