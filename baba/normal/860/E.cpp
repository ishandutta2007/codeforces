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

const int N = int(5e5)+10;
VI A[N],g[N];
int sub[N];
LL ans[N];
int chainParent[N],chainHead[N],blen,chainNo[N],pos[N],nchain;
LL BIT[2][N];
inline void update(int t, int x, int v){
  for(;x<N;x+=x^(x & (x-1)))BIT[t][x] += v;
}
inline void update(int l, int r){
  update(0,l,1);
  update(0,r+1,-1);
  update(1,l,l - 1);
  update(1,r+1,-r);
}
inline LL query(int t,int x){
  LL ret = 0;
  for(;x;x=(x&(x-1)))ret+=BIT[t][x];
  return ret;
}
inline LL query(int x){
  return query(0,x) * x  - query(1,x);
}
inline LL range_query(int l,int r){
  return query(r) - query(l-1);
}

inline void dfs(int x,int l = 1){
  A[l].PB(x);
  sub[x] = 1;
  for(auto y : g[x]){
    dfs(y,l+1);
    sub[x] += sub[y];
  }
}
inline void HLD(int x){
  pos[x] = ++blen;
  chainNo[x] = nchain;
  int sc = -1;
  for(auto y : g[x])
    if(sc == -1 || sub[y] > sub[sc])
      sc = y;
  if(sc == -1)return;
  HLD(sc);
  for(auto y : g[x])
    if(y != sc){
      nchain++;
      chainParent[nchain] = x;
      chainHead[nchain] = y;
      HLD(y);
    }
}
int root = -1;
inline LL query_up(int x){
  LL ret = 0;
  while(chainNo[x] != chainNo[root]){
    int cno = chainNo[x];
    ret += range_query(pos[chainHead[cno]],pos[x]);
    x = chainParent[cno];
  }
  ret += range_query(pos[root],pos[x]);
  return ret;
}
inline void update_up(int x){
  while(chainNo[x] != chainNo[root]){
    int cno = chainNo[x];
    update(pos[chainHead[cno]],pos[x]);
    x = chainParent[cno];
  }
  update(pos[root],pos[x]);
}
int main()
{
  int n;si(n);
  root = -1;
  for(int i=1;i<=n;i++){
    int p;si(p);
    if(p == 0)root = i;
    else g[p].PB(i);
  }
  dfs(root);
  HLD(root);
  for(int i=1;i<=n;i++){
   for(auto x : A[i]){
      update_up(x);
    }
    for(auto x : A[i]){
      ans[x] = query_up(x) - i;
    }
 }
  for(int i=1;i<=n;i++)
    printf("%lld ",ans[i]);
  puts("");
	return 0;
}